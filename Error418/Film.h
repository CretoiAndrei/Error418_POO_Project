#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include<math.h>
using namespace std;

class Film
{
private:
	const int id;
	static int nrFilme;
	char* nume;
	char* gen;
	int durata;
	int pg;
	int an;
	int recenzi;
	int* recenzie;
public:
	Film();
	Film(const char* nume, const char* gen, int durata, int pg, int an, int recenzi, int* recenzie);
	Film(const Film& i);
	Film& operator=(const Film& i);
	~Film();
	int Id();
	char* Nume();
	char* Gen();
	int Durata();
	int Pg();
	int An();
	void SetNume(char* nume);
	void SetGen(char* gen);
	void SetDurata(int durata);
	void SetPg(int pg);
	void SetAn(int an);
	void serialize(string fileName);
	void deserialize(string fileName);
	friend ostream& operator<<(ostream& out, const Film& i);
	friend istream& operator>>(istream& in, Film& i ); 
};
