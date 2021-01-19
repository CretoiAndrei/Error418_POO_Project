#include "Film.h"

int Film::nrFilme = 0;
 
Film::Film() :id(++Film::nrFilme)
{
	nume = new char[11];
	strcpy_s(nume, 11, "Necunoscut");
	gen = new char[11];
	strcpy_s(gen, 11, "Necunoscut");
	durata = 0;
	pg = 0;
	an = 0;
	recenzi = 0;
	recenzie = nullptr;
}

Film::Film(const char* nume, const char* gen,int durata,int pg, int an, int recenzi, int* recenzie) :id(++Film::nrFilme)
{
	this->nume = new char[strlen(nume)+1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
	this->gen = new char[strlen(gen) + 1];
	strcpy_s(this->gen, strlen(gen) + 1, gen);
	this->durata = durata;
	this->pg = pg;
	this->an = an;
	this->recenzi = recenzi;
	this->recenzie = new int[recenzi];
	for (int i = 0; i < recenzi; i++)
	{
		this->recenzie[i] = recenzie[i];
	}
}

Film::Film(const Film& i) :id(i.id)
{
	nume = new char[strlen(i.nume) + 1];
	strcpy_s(nume, strlen(i.nume) + 1, i.nume);
	gen = new char[strlen(i.gen) + 1];
	strcpy_s(gen, strlen(i.gen) + 1, i.gen);
	durata = i.durata;
	pg = i.pg;
	an = i.an;
	recenzi =i. recenzi;
	recenzie = new int[i.recenzi];
	for (int j = 0; j < i.recenzi; j++)
	{
		recenzie[j] = i.recenzie[j];
	}
}

Film& Film::operator=(const Film& i)
{
	nume = new char[strlen(i.nume) + 1];
	strcpy_s(nume, strlen(i.nume) + 1, i.nume);
	gen = new char[strlen(i.gen) + 1];
	strcpy_s(gen, strlen(i.gen) + 1, i.gen);
	durata = i.durata;
	pg = i.pg;
	an = i.an;
	recenzi = i.recenzi;
	recenzie = new int[i.recenzi];
	for (int j = 0; j < i.recenzi; j++)
	{
		recenzie[j] = i.recenzie[j];
	}
	return *this;
}

Film::~Film()
{
	if (nume != nullptr) {
		delete[] nume;
	}
	if (gen != nullptr) {
		delete[] gen;
	}
	if (recenzie != nullptr) {
		delete[] recenzie;
	}
}

int Film::Id()
{
	return id;
}

char* Film::Nume() 
{
	char* temp = new char[strlen(nume)+1];
	strcpy_s(temp, strlen(nume) + 1, nume);
	return temp;
}

char* Film::Gen()
{
	char* temp = new char[strlen(gen) + 1];
	strcpy_s(temp, strlen(gen) + 1, gen);
	return temp;
}

int Film::Durata()
{
	return durata;
}
  
int Film::Pg()
{
	return pg;
}

int Film::An()
{
	return an;
}

void Film::SetNume(char* nume)
{
	if (nume != nullptr) {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}
}

void Film::SetGen(char* gen)
{
	if (gen != nullptr) {
		this->gen = new char[strlen(gen) + 1];
		strcpy_s(this->gen, strlen(gen) + 1, gen);
	}
}

void Film::SetDurata(int durata)
{
	if (durata > 0) {
		this->durata = durata;
	}
}

void Film::SetPg(int pg)
{
	if (pg > 0) {
		this->pg = pg;
	}
}

void Film::SetAn(int an)
{
	if (an > 0) {
		this->an = an;
	}
}

void Film::serialize(string fileName) 
{
	string idS = to_string(id);
	ofstream f("files/" + fileName + idS + ".dat", ios::binary);

	f.write(nume, (long long)strlen(nume) + 1);
	f.write(gen, (long long)strlen(gen) + 1);
	f.write((char*)&durata, sizeof(durata));
	f.write((char*)&pg, sizeof(pg));
	f.write((char*)&an, sizeof(an));
	f.write((char*)&recenzi, sizeof(recenzi));
	for (int i = 0; i < recenzi; i++) {
		f.write((char*)&recenzie[i], sizeof(recenzie[i]));
	}
	f.close();
}

void Film::deserialize(string fileName)
{
	ifstream f("files/"+fileName, ios::binary);

	string buffer = "";
	char c = 0;
	while ((c = f.get()) != 0)
	{
		buffer += c;
	}
	delete[] nume;
	nume = new char[buffer.length() + 1];
	strcpy_s(nume, buffer.length() + 1, buffer.c_str());
	buffer = "";
	c = 0;
	while ((c = f.get()) != 0)
	{
		buffer += c;
	}
	delete[] gen;
	gen = new char[buffer.length() + 1];
	strcpy_s(gen, buffer.length() + 1, buffer.c_str());
	f.read((char*)&durata, sizeof(durata));
	f.read((char*)&pg, sizeof(pg));
	f.read((char*)&an, sizeof(an));
	f.read((char*)&recenzi, sizeof(recenzi));
	delete[] recenzie;
	recenzie = new int[recenzi];
	for (int i = 0; i < recenzi; i++) {
		f.read((char*)&recenzie[i], sizeof(recenzie[i]));
	}

	f.close();
}

ostream& operator<<(ostream& out, const Film& i)
{
	out << "Nume: " << i.nume << endl;
	out << "Gen: " << i.gen << endl;
	out << "Durata: " << i.durata << endl;
	out << "Pg: " << i.pg << endl;
	out << "Anul lansarii: " << i.an << endl;
	out << "Numar recenzi: " << i.recenzi << endl;

	out << "Recenzii:";
	for (int j = 0; j < i.recenzi; j++) {
		out << " " << i.recenzie[j];
	}
	out << endl;
	return out;
}

istream& operator>>(istream& in, Film& i)
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

	cout << "Gen:";
	if (i.gen != nullptr)
	{
		delete[] i.gen;
	}
	char buffer2[100];
	in >> ws;
	in.getline(buffer2, 99);
	i.gen = new char[strlen(buffer2) + 1];
	strcpy_s(i.gen, strlen(buffer2) + 1, buffer2);

	cout << "Durata: ";
	in >> i.durata;

	cout << "Pg: ";
	in >> i.pg;

	cout << "Anul aparitiei: ";
	in >> i.an;

	cout << "Numar recenzi: ";
	in >> i.recenzi;

	cout << "Recenzii: ";
	for (int j = 0; j < i.recenzi; j++) {
		in >> i.recenzie[j];
	}
	return in;
}