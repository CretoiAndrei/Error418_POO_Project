#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <sys/stat.h>
#include <direct.h>
#include <sys/types.h>
#include <windows.h>

#include "Film.h"
#include "Sala.h"
#include "Difuzare.h"
#include "Bilet.h"
#include "Rezervare.h"

Film* filme;
int nrfilme = 0;
Sala* sali;
int nrsali = 0;
Difuzare* difuzari;
int nrdifuzari = 0;
Bilet* bilete;
int nrbilete = 0;
Rezervare* rezervari;
int nrrezervari = 0;

using namespace std;
