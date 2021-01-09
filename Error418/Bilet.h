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

class Bilet
{
private:
	const int id;
	static int nrBilete ;
	char* nume;
	int persoane;
	int* rand;
	int* loc;
	int* pret;
	int total;
	Difuzare difuzare;
public:
	Bilet();
	Bilet(const char* nume, int persoane, int* randuri, int* loc, int* pret, Difuzare difuzare);
	Bilet(const Bilet& i);
	Bilet& operator=(const Bilet& i);
	~Bilet();
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
	friend ostream& operator<<(ostream& out, const Bilet& i);
	friend istream& operator>>(istream& in, Bilet& i);
};