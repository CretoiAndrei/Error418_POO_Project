// Error418.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "main.h"


std::string current_path()
{
    char* cwd = _getcwd(0, 0); // **** microsoft specific ****
    std::string working_directory(cwd);
    std::free(cwd);
    return working_directory;
}

void initiate() {
    //Creare folder files daca nu exista 
    struct stat st = { 0 };
    if (stat("/files", &st) == 0) {
        _mkdir("files");
    }
    //adresa fisierelor binare a aplicatiei
    string path = current_path()+"/files/*.dat";
    
    //obtinere fisierelor .dat disponibile din folderul files
    string* files = new string[30];
    int l = 0;

    std::wstring stemp = std::wstring(path.begin(), path.end());
    LPCWSTR sw = stemp.c_str();
    WIN32_FIND_DATA data;
    HANDLE hFind = FindFirstFile(sw, &data);     

    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            wstring ws(data.cFileName);
            string str(ws.begin(), ws.end());
            files[l] = str;
            l++;
        } while (FindNextFile(hFind, &data));
        FindClose(hFind);
    }

    //introducerea datelor salvate in runtime
    for (int i = 0; i < l; i++) {
        if (files[i].find("film") != string::npos) {
            nrfilme++;
        }
        if (files[i].find("sala") != string::npos) {
            nrsali++;
        }
        if (files[i].find("difuzare") != string::npos) {
            nrdifuzari++;
        }
        if (files[i].find("bilet") != string::npos) {
            nrbilete++;
        }
        if (files[i].find("rezervare") != string::npos) {
            nrrezervari++;
        }
    }
    filme = new Film[nrfilme];
    sali = new Sala[nrsali];
    difuzari = new Difuzare[nrdifuzari];
    bilete = new Bilet[nrbilete];
    rezervari = new Rezervare[nrrezervari];
    for (int i = 0; i < l; i++) {
        if (files[i].find("film") != string::npos) {
            filme[i].deserialize(files[i]);
        }
        if (files[i].find("sala") != string::npos) {
            sali[i].deserialize(files[i]);
        }
        if (files[i].find("difuzare") != string::npos) {
            difuzari[i].deserialize(files[i]);
        }
        if (files[i].find("bilet") != string::npos) {
            bilete[i].deserialize(files[i]);
        }
        if (files[i].find("rezervare") != string::npos) {
            rezervari[i].deserialize(files[i]);
        }
    }

}

void interogareFilme() {
    int id = 0;
    int input3 = 0;
    while (input3 != 3) {
        cout << endl << "1 - Lista filme" << endl << "2 - Cauta film dupa id" << endl << "3 - Inapoi" << endl;
        cin >> input3;
        switch (input3) {
        case 1:
            if (nrfilme > 0) {
                for (int i = 0; i < nrfilme; i++) {
                    cout << "   #" << filme[i].Id() << " " << filme[i].Nume() << endl;
                }
            }
            else {
                cout << "Din pacate nu sunt filme disponibile in acest moment"; 
            }
            break;
        case 2:
            cout << "Introduce-ti id-ul filmului: ";
            cin >> id;
            for (int i = 0; i < nrfilme; i++) {
                if (filme[i].Id() == id) {
                    cout << filme[i];
                    break;
                }
            }
            break;
        case 3:
            break;
        default:
            cout << "Aceasta optiune nu exista" << endl;
        }
    }
    
}



void interogare() {
    int input2 = 0;
    while (input2 != 6) {
        cout << endl << "1 - Interogare Filme " << endl << "2 - Interogare Sali" << endl << "3 - Interogare Difuzari" << endl << "4 - Interogare Bilete" << endl << "5 - Interogare Rezervari" << endl << "6 - Inapoi" << endl;
        cin >> input2;
        switch (input2) {
        case 1:
            interogareFilme();
            break;
        case 2:
            interogareFilme();
            break;
        case 3:
            interogareFilme();
            break;
        case 4:
            interogareFilme();
            break;
        case 5:
            interogareFilme();
            break;
        case 6:
            interogareFilme();
            break;
        default:
            cout << "Aceasta optiune nu exista" << endl;
        }

    }
}

void adaugare() {

}

void stergere() {

}


int main() {
    initiate();
    //Loop pentru executarea de comenzi
    int input=0;
    while (input != 4) {
        cout << endl << "Lista de navigare" << endl << "1 - Interogare date" << endl << "2 - Adaugare date" << endl << "3 - Stergere date" << endl << "4 - Iesire" << endl;
        cin >> input;
        switch (input){
        case 1:
            interogare();
            break;
        case 2:
            adaugare();
            break;
        case 3:
            stergere();
            break;
        default:
            cout << "Aceasta optiune nu exista" << endl;
        }
        cout<< "Ati ales optiunea"<<input;
    }

    return 0;
 }
 