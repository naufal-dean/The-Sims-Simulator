#ifndef SIMS_H
#define SIMS_H

#include <iostream>
#include <string>
#include "constants.h"

using namespace std;

class Sims {
private:
    string name;
    int hygiene, energy, fun;

public:
    Sims (string name);
    bool changeStatus(int h, int e, int f);
    void doTidur(int option);
    void doMakan(int option);
    void doMinum(int option);
    void doBuangAir(int option);
    void doSosialisasiKeKafe();
    void doBermainMedsos();
    void doBermainKomputer();
    void doMandi();
    void doCuciTangan();
    void doMendengarMusik();
    void doMembaca(int option);
};

#endif // SIMS_H
