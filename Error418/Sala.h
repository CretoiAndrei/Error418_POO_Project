#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include<math.h>
using namespace std;

class Sala
{
private:
	const int id;
	static int nrSali;
	char* nume;
	int randuri;
	int* locuri;
public:
	Sala();
	Sala(const char* nume, int randuri, int* locuri);
	Sala(const Sala& i);
	Sala& operator=(const Sala& i);
	~Sala();
	int Id();
	char* Nume();
	int* Locuri();
	void SetNume(char* nume);
	void SetRanduri(int randuri);
	void SetLocuri(int randuri, int* locuri);
	void serialize(string fileName);
	void deserialize(string fileName);
	friend ostream& operator<<(ostream& out, const Sala& i);
	friend istream& operator>>(istream& in, Sala& i);
};