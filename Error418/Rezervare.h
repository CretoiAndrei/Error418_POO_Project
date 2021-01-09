#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include<math.h>

#include "Difuzare.h"

using namespace std;

class Rezervare
{
private:
	const int id;
	static int nrRezervari;
	char* nume;
	int persoane;
	int* rand;
	int* loc;
	int* pret;
	int total;
	Difuzare difuzare;
public:
	Rezervare();
	Rezervare(const char* nume, int persoane, int* randuri, int* loc, int* pret, Difuzare difuzare);
	Rezervare(const Rezervare& i);
	Rezervare& operator=(const Rezervare& i);
	~Rezervare();
	int Id();
	char* Nume();
	int Persoane();
	int* Rand();
	int* Loc();
	int* Pret();
	int Total();
	Difuzare* GetDifuzare();
	void SetNume(char* nume);
	void SetRand(int persoane, int* rand);
	void SetLoc(int persoane, int* loc);
	void SetPret(int persoane, int* pret);
	void SetDifuzare(Difuzare difuzare);
	void serialize(string fileName);
	void deserialize(string fileName);
	friend ostream& operator<<(ostream& out, const Rezervare& i);
	friend istream& operator>>(istream& in, Rezervare& i);
};