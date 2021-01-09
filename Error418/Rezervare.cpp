#include "Rezervare.h"

int Rezervare::nrRezervari = 0;

Rezervare::Rezervare() :id(++Rezervare::nrRezervari)
{
	nume = new char[11];
	strcpy_s(nume, 11, "Necunoscut");
	persoane = 0;
	rand = nullptr;
	loc = nullptr;
	pret = nullptr;
	total = 0;
}

Rezervare::Rezervare(const char* nume, int persoane, int* randuri, int* loc, int* pret, Difuzare difuzare) :id(++Rezervare::nrRezervari)
{
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
	this->persoane = persoane;
	this->rand = new int[persoane];
	this->loc = new int[persoane];
	this->pret = new int[persoane];
	this->total = 0;
	for (int i = 0; i < persoane; i++) {
		this->rand[i] = rand[i];
		this->loc[i] = loc[i];
		this->pret[i] = pret[i];
		this->total += pret[i];
	}
	this->difuzare = difuzare;
}

Rezervare::Rezervare(const Rezervare& i) :id(i.id)
{
	nume = new char[strlen(i.nume) + 1];
	strcpy_s(nume, strlen(i.nume) + 1, i.nume);
	persoane = i.persoane;
	rand = new int[i.persoane];
	loc = new int[i.persoane];
	pret = new int[i.persoane];
	total = 0;
	for (int j = 0; j < i.persoane; j++) {
		rand[j] = i.rand[j];
		loc[j] = i.loc[j];
		pret[j] = i.pret[j];
		total += i.pret[j];
	}
}

Rezervare& Rezervare::operator=(const Rezervare& i)
{
	nume = new char[strlen(i.nume) + 1];
	strcpy_s(nume, strlen(i.nume) + 1, i.nume);
	persoane = i.persoane;
	rand = new int[i.persoane];
	loc = new int[i.persoane];
	pret = new int[i.persoane];
	total = 0;
	for (int j = 0; j < i.persoane; j++) {
		rand[j] = i.rand[j];
		loc[j] = i.loc[j];
		pret[j] = i.pret[j];
		total += i.pret[j];
	}
	return *this;
}

Rezervare::~Rezervare()
{
	if (nume != nullptr) {
		delete[] nume;
	}
	if (rand != nullptr) {
		delete[] rand;
	}
	if (loc != nullptr) {
		delete[] loc;
	}
	if (pret != nullptr) {
		delete[] pret;
	}
}

int Rezervare::Id()
{
	return id;
}

char* Rezervare::Nume()
{
	char* temp = new char[strlen(nume) + 1];
	strcpy_s(temp, strlen(nume) + 1, nume);
	return temp;
}


int* Rezervare::Rand()
{
	return rand;
}

int Rezervare::Persoane()
{
	return persoane;
}


int* Rezervare::Loc()
{
	return loc;
}

int* Rezervare::Pret()
{
	return pret;
}

int Rezervare::Total()
{
	return total;
}

Difuzare* Rezervare::GetDifuzare()
{
	return &difuzare;
}

void Rezervare::SetNume(char* nume)
{
	if (nume != nullptr) {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}
}

void Rezervare::SetRand(int persoane, int* rand)
{
	if (persoane > 0 && rand != nullptr) {
		this->rand = new int[persoane];
		for (int i = 0; i < persoane; i++) {
			this->rand[i] = rand[i];
		}
	}
}
void Rezervare::SetLoc(int persoane, int* loc)
{
	if (persoane > 0 && rand != nullptr) {
		this->loc = new int[persoane];
		for (int i = 0; i < persoane; i++) {
			this->loc[i] = loc[i];
		}
	}
}

void Rezervare::SetPret(int persoane, int* pret)
{
	if (persoane > 0 && rand != nullptr) {
		this->pret = new int[persoane];
		for (int i = 0; i < persoane; i++) {
			this->pret[i] = pret[i];
		}
	}
}

void Rezervare::SetDifuzare(Difuzare difuzare)
{
	this->difuzare = difuzare;
}


void Rezervare::serialize(string fileName)
{
	ofstream f(fileName, ios::binary);

	f.write(nume, (long long)strlen(nume) + 1);
	f.write((char*)&persoane, sizeof(persoane));
	for (int i = 0; i < persoane; i++) {
		f.write((char*)&rand[i], sizeof(rand[i]));
	}
	for (int i = 0; i < persoane; i++) {
		f.write((char*)&loc[i], sizeof(loc[i]));
	}
	for (int i = 0; i < persoane; i++) {
		f.write((char*)&loc[i], sizeof(loc[i]));
	}
	f.write((char*)&total, sizeof(total));

	f.close();
}

void Rezervare::deserialize(string fileName)
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

	f.read((char*)&persoane, sizeof(persoane));
	for (int i = 0; i < persoane; i++) {
		f.read((char*)&rand[i], sizeof(rand[i]));
	}
	for (int i = 0; i < persoane; i++) {
		f.read((char*)&loc[i], sizeof(loc[i]));
	}
	for (int i = 0; i < persoane; i++) {
		f.read((char*)&pret[i], sizeof(pret[i]));
	}
	f.read((char*)&total, sizeof(total));

	f.close();
}

ostream& operator<<(ostream& out, const Rezervare& i)
{
	out << "nume: " << i.nume << endl;
	out << "Persoane: " << i.persoane << endl;
	out << i.persoane;
	if (i.persoane > 0) {
		for (int j = 0; j < i.persoane; j++) {
			out << "Persoana " << j << "- rand:" << i.rand[j] << " rand:" << i.loc[j] << " pret:" << i.pret[j] << endl;
		}
		out << "Total: " << i.total << endl;
	}
	out << i.difuzare << endl;

	return out;
}

istream& operator>>(istream& in, Rezervare& i)
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

	cout << "Nr. persoane:";
	in >> i.persoane;

	i.total = 0;

	if (i.persoane > 0) {
		i.rand = new int[i.persoane];
		i.loc = new int[i.persoane];
		i.pret = new int[i.persoane];
		i.total = 0;
		for (int j = 0; j < i.persoane; j++) {
			cout << "Persoana " << j << endl << "Rand:";
			in >> i.rand[j];
			cout << "Loc:";
			in >> i.loc[j];
			cout << "Pret:";
			in >> i.pret[j];
			i.total += i.pret[j];
		}
	}
	in >> i.difuzare;

	return in;
}