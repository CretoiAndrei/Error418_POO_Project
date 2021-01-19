#include "Sala.h"

int Sala::nrSali = 0;

Sala::Sala() :id(++Sala::nrSali)
{
	nume = new char[11];
	strcpy_s(nume, 11, "Necunoscut");
	randuri = 0;
	locuri = nullptr;
}

Sala::Sala(const char* nume, int randuri, int* locuri) :id(++Sala::nrSali)
{
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
	this->randuri = randuri;
	this->locuri = new int[randuri];
	for (int i = 0; i < randuri; i++)
	{
		this->locuri[i] = locuri[i];
	}
}

Sala::Sala(const Sala& i) :id(i.id)
{
	nume = new char[strlen(i.nume) + 1];
	strcpy_s(nume, strlen(i.nume) + 1, i.nume);
	randuri = i.randuri;
	locuri = new int[i.randuri];
	for (int j = 0; j < i.randuri; j++)
	{
		locuri[j] = i.locuri[j];
	}
}

Sala& Sala::operator=(const Sala& i)
{
	nume = new char[strlen(i.nume) + 1];
	strcpy_s(nume, strlen(i.nume) + 1, i.nume);
	randuri = i.randuri;
	locuri = new int[i.randuri];
	for (int j = 0; j < i.randuri; j++)
	{
		locuri[j] = i.locuri[j];
	}
	return *this;
}

Sala::~Sala()
{
	if (nume != nullptr) {
		delete[] nume;
	}
	if (locuri != nullptr) {
		delete[] locuri;
	}
}

int Sala::Id()
{
	return id;
}

char* Sala::Nume()
{
	char* temp = new char[strlen(nume) + 1];
	strcpy_s(temp, strlen(nume) + 1, nume);
	return temp;
}


int* Sala::Locuri()
{
	return locuri;
}

void Sala::SetNume(char* nume)
{
	if (nume != nullptr) {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}
}

void Sala::SetLocuri(int randuri,int* locuri)
{
	if (randuri > 0) {
		this->randuri = randuri;
		this->locuri = new int[randuri];
		for (int i = 0; i < randuri; i++) {
			this->locuri[i] = locuri[i];
		}
	}
}

void Sala::serialize(string fileName)
{
	ofstream f(fileName, ios::binary);

	f.write(nume, (long long)strlen(nume) + 1);
	f.write((char*)&randuri, sizeof(randuri));
	for (int i = 0; i < randuri; i++) {
		f.write((char*)&locuri[i], sizeof(locuri[i]));
	}
	f.close();
}

void Sala::deserialize(string fileName)
{
	ifstream f(fileName, ios::binary);

	string buffer = "";
	char c = 0;
	while ((c = f.get()) != 0)
	{
		buffer += c;
	}
	delete[] nume;
	nume = new char[buffer.length() + 1];
	strcpy_s(nume, buffer.length() + 1, buffer.c_str());
	f.read((char*)&randuri, sizeof(randuri));
	delete[] locuri;
	locuri = new int[randuri];
	for (int i = 0; i < randuri; i++) {
		f.read((char*)&locuri[i], sizeof(locuri[i]));
	}

	f.close();
}

ostream& operator<<(ostream& out, const Sala& i)
{
	out << "Nume: " << i.nume << endl;
	out << "Numar randuri: " << i.randuri << endl;
	if (i.randuri > 0) {
		out << "Locuri pe rand:";
		for (int j = 0; j < i.randuri; j++) {
			out << " " << i.locuri[j];
		}
		out << endl;
	}
	return out;
}

istream& operator>>(istream& in, Sala& i)
{
	cout << "Nume:";
	if (i.nume != nullptr)
	{
		delete[] i.nume;
	}
	char buffer[100];
	in >> ws;
	in.getline(buffer, 99);
	i.nume = new char[strlen(buffer) + 1];
	strcpy_s(i.nume, strlen(buffer) + 1, buffer);
	cout << "Numar randuri: ";
	in >> i.randuri;

	cout << "Locuri pe rand: ";
	for (int j = 0; j < i.randuri; j++) {
		in >> i.locuri[j];
	}
	return in;
}