#include "Difuzare.h"

int Difuzare::nrDifuzari = 0;

Difuzare::Difuzare() :id(++Difuzare::nrDifuzari)
{
	data = new char[11];
	strcpy_s(data, 11, "01/01/2021");
	ora = nullptr;
}

Difuzare::Difuzare(const char* data, int* ora, Film film, Sala sala) :id(++Difuzare::nrDifuzari)
{
	this->data = new char[strlen(data) + 1];
	strcpy_s(this->data, strlen(data) + 1, data);
	this->ora = new int[2];
	this->ora[0] = ora[0];
	this->ora[1] = ora[1];
	this->film = film;
	this->sala = sala;
}

Difuzare::Difuzare(const Difuzare& i) :id(i.id)
{
	data = new char[strlen(i.data) + 1];
	strcpy_s(data, strlen(i.data) + 1, i.data);
	if (i.ora != nullptr) {
		ora = new int[2];
		ora[0] = i.ora[0];
		ora[1] = i.ora[1];
	}
	else {
		ora = nullptr;
	}
	film = i.film;
	sala = i.sala;
}

Difuzare& Difuzare::operator=(const Difuzare& i)
{
	data = new char[strlen(i.data) + 1];
	strcpy_s(data, strlen(i.data) + 1, i.data);
	if (i.ora != nullptr) {
		ora = new int[2];
		ora[0] = i.ora[0];
		ora[1] = i.ora[1];
	}
	else {
		ora = nullptr;
	}
	film = i.film;
	sala = i.sala;
	return *this;
}

Difuzare::~Difuzare()
{
	if (data != nullptr) {
		delete[] data;
	}
	if (ora != nullptr) {
		delete[] ora;
	}
}

int Difuzare::Id()
{
	return id;
}

char* Difuzare::Data()
{
	char* temp = new char[strlen(data) + 1];
	strcpy_s(temp, strlen(data) + 1, data);
	return temp;
}


int* Difuzare::Ora()
{
	return ora;
}

void Difuzare::SetData(char* data)
{
	if (data != nullptr) {
		this->data = new char[strlen(data) + 1];
		strcpy_s(this->data, strlen(data) + 1, data);
	}
}

void Difuzare::SetOra(int* ora)
{
	if (ora !=nullptr) {
		this->ora[0] = ora[0];
		this->ora[1] = ora[1];
	}
}

void Difuzare::SetSala(Sala sala)
{
	this->sala = sala;
}

void Difuzare::SetFilm(Film film)
{
	this->film = film;
}

void Difuzare::serialize(string fileName)
{
	ofstream f(fileName, ios::binary);

	f.write(data, (long long)strlen(data) + 1);
	f.write((char*)&ora[0], sizeof(ora[0]));
	f.write((char*)&ora[1], sizeof(ora[1]));

	f.close();
}

void Difuzare::deserialize(string fileName)
{
	ifstream f(fileName, ios::binary);

	string buffer = "";
	char c = 0;
	while ((c = f.get()) != 0)
	{
		buffer += c;
	}
	delete[] data;
	data = new char[buffer.length() + 1];
	strcpy_s(data, buffer.length() + 1, buffer.c_str());
	f.read((char*)&ora[0], sizeof(ora[0]));
	f.read((char*)&ora[1], sizeof(ora[1]));

	f.close();
}

ostream& operator<<(ostream& out, const Difuzare& i)
{
	out << "Data: " << i.data << endl;
	if (i.ora != nullptr) {
		out << "Ora: " << i.ora[0] << ":" << i.ora[1] << endl;
	}
	else {
		out << "Ora: necunoscut" << endl;
	}
	out << i.film << endl << i.sala << endl;

	return out;
}

istream& operator>>(istream& in, Difuzare& i)
{
	cout << "Data:";
	if (i.data != nullptr)
	{
		delete[] i.data;
	}
	char buffer[100];
	in >> ws;
	in.getline(buffer, 99);
	i.data = new char[strlen(buffer) + 1];
	strcpy_s(i.data, strlen(buffer) + 1, buffer);

	i.ora=new int[2];
	cout << "Ora: ";
	in >> i.ora[0];
	cout << "Minutul: ";
	in >> i.ora[1];
	cout << "Film:";
	in >> i.film;
	cout << "Sala:";
	in >> i.sala;

	return in;
}