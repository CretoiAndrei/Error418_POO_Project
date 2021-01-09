// Error418.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Film.h"
#include "Sala.h"
#include "Difuzare.h"
#include "Bilet.h"
#include "Rezervare.h"

using namespace std;

int main()
{
    int* recenzie = new int[3];
    recenzie[0] = 1;
    recenzie[1] = 5;
    recenzie[2] = 5;
    Film test;
    Film test2("Avatar","SF",120,12,2017,3, recenzie);
    Film test3(test2);
    Film test4;
    test4 = test3;

    char* name=new char[8];
    strcpy_s(name, 8, "BadBoys");
    test4.SetNume(name);
    name = new char[9];
    strcpy_s(name, 9, "Aventure");
    test4.SetGen(name);
    test4.SetDurata(115);
    test4.SetPg(16);
    test4.SetAn(2018);
    test4.serialize("film.dat");
    Film test5;
    test5.deserialize("film.dat");
   //cout << test5;
    Sala s1("PrimaSala",0,nullptr);
    Difuzare testD;
    testD.SetSala(s1);
    testD.SetFilm(test5);
    cout << testD;

    int* arra = new int[2];
    arra[0] = 1;
    arra[1] = 1;
    char* name2 = new char[7];
    strcpy_s(name2, 7, "Andrei");
    Bilet bilet1;
    bilet1.SetNume(name2);
    bilet1.SetRand(2, arra);
    arra[0] = 13;
    arra[1] = 14;
    bilet1.SetLoc(2, arra);
    arra[0] = 54;
    arra[1] = 24;
    bilet1.SetPret(2, arra);
    bilet1.SetDifuzare(testD);
    cout << bilet1;

}

 