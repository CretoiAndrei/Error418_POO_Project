#include "Bilet.h"

int Bilet::nrBilete = 0;

Bilet::Bilet() :id(++Bilet::nrBilete)
{
	nume = new char[11];
	strcpy_s(nume, 11, "Necunoscut");
	persoane = 0;
	rand = nullptr;
	loc = nullptr;
	pret = nullptr;
	total = 0;
}

Bilet::Bilet(const char* nume, int persoane, int* randuri, int* loc, int* pret, Difuzare difuzare) :id(++Bilet::nrBilete)
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

Bilet::Bilet(const Bilet& i) :id(i.id)
{
	nume = new char[strlen(i.nume) + 1];
	strcpy_s(nume, strlen(i.nume) + 1, i.nume);
	persoane = i.persoane;
	rand = new int[i.persoane];
	loc = new int[i.persoane];
	pret = new int[i.persoane];
	total = 0;
	for (int j = 0; j < i.persoane;j++) {
		rand[j] = i.rand[j];
		loc[j] = i.loc[j];
		pret[j] = i.pret[j];
		total += i.pret[j];
	}
}

Bilet& Bilet::operator=(const Bilet& i)
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

Bilet::~Bilet()
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

int Bilet::Id()
{
	return id;
}

char* Bilet::Nume()
{
	char* temp = new char[strlen(nume) + 1];
	strcpy_s(temp, strlen(nume) + 1, nume);
	return temp;
}


int* Bilet::Rand()
{
	return rand;
}

int Bilet::Persoane()
{
	return persoane;
}


int* Bilet::Loc()
{
	return loc;
}

int* Bilet::Pret()
{
	return pret;
}

int Bilet::Total()
{
	return total;
}

Difuzare* Bilet::GetDifuzare()
{
	return &difuzare;
}

void Bilet::SetNume(char* nume)
{
	if (nume != nullptr) {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}
}

void Bilet::SetRand(int persoane, int* rand)
{
	if (persoane>0 && rand != nullptr) {
		this->persoane = persoane;
		this->rand = new int[persoane];
		for (int i = 0; i < persoane; i++) {
			this->rand[i] = rand[i];
		}
	}
}
void Bilet::SetLoc(int persoane, int* loc)
{
	if (persoane > 0 && rand != nullptr) {
		this->persoane = persoane;
		this->loc = new int[persoane];
		for (int i = 0; i < persoane; i++) {
			this->loc[i] = loc[i];
		}
	}
}

void Bilet::SetPret(int persoane, int* pret)
{
	if (persoane > 0 && rand != nullptr) {
		this->persoane = persoane;
		this->pret = new int[persoane];
		this->total = 0;
		for (int i = 0; i < persoane; i++) {
			this->pret[i] = pret[i];
			this->total += pret[i];
		}
	}
}

void Bilet::SetDifuzare(Difuzare difuzare)
{
	this->difuzare = difuzare;
}


void Bilet::serialize(string fileName)
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

void Bilet::deserialize(string fileName)
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

ostream& operator<<(ostream& out, const Bilet& i)
{
	out << "nume: " << i.nume << endl;
	out << "Persoane: " << i.persoane << endl;
	out << i.persoane;
	if (i.persoane>0) {
		for (int j = 0; j < i.persoane; j++) {
			out << "Persoana " << j << "- rand:" << i.rand[j] << " rand:"<< i.loc[j] << " pret:" << i.pret[j] << endl;
		}
		out << "Total: " << i.total << endl;
	}
	out << i.difuzare << endl;

	return out;
}

istream& operator>>(istream& in, Bilet& i)
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
			cout << "Persoana " << j << endl <<"Rand:";
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