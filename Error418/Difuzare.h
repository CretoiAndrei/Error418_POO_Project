#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include<math.h>

#include "Sala.h"
#include "Film.h"

using namespace std;

class Difuzare
{
private:
	const int id;
	static int nrDifuzari;
	char* data;
	int* ora;
	Film film;
	Sala sala;
public:
	Difuzare();
	Difuzare(const char* data, int* ora, Film film, Sala sala);
	Difuzare(const Difuzare& i);
	Difuzare& operator=(const Difuzare& i);
	~Difuzare();
	int Id();
	char* Data();
	int* Ora();
	Difuzare* GetDifuzare();
	Film* GetFilm();
	void SetData(char* data);
	void SetOra(int* ora);
	void SetSala(Sala sala);
	void SetFilm(Film film);
	void serialize(string fileName);
	void deserialize(string fileName);
	friend ostream& operator<<(ostream& out, const Difuzare& i);
	friend istream& operator>>(istream& in, Difuzare& i);
};