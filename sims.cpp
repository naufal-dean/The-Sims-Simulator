#include <bits/stdc++.h>
#include "sims.h"

Sims::Sims() {
    hygiene = 0;
    energy = 10;
    fun = 0;
}

string Sims::getName() {
    return(name);
}

int Sims::getHygiene() {
    return(hygiene);
}

int Sims::getEnergy() {
    return(energy);
}

int Sims::getFun() {
    return(fun);
}

void Sims::setName(string playerName) {
    name = playerName;
}

bool Sims::changeStatus(int h, int e, int f) {
    int newHygiene = hygiene + h;
    int newEnergy = energy + e;
    int newFun = fun + f;
    if ((newHygiene >= 0) && (newHygiene <= 15) &&
          (newEnergy >= 0) && (newEnergy <= 15) &&
          (newFun >= 0) && (newFun <= 15)) {
        hygiene = newHygiene;
        energy = newEnergy;
        fun = newFun;
        return ACTION_SUCCEED;
    } else {
        return ACTION_FAILED;
    }
}

void Sims::doTidur(int option) {
    bool actStatus = false;
    string subAct;

    switch (option) {
        case TIDUR_SIANG:
            actStatus = changeStatus(0, 10, 0);
            subAct = "siang";
            break;
        case TIDUR_MALAM:
            actStatus = changeStatus(0, 15, 0);
            subAct = "malam";
            break;
        default:
            cout << "Opsi tidak valid!" << endl;
            break;
    }

    if (actStatus) {
        cout << "Tidur " + subAct + " berhasil!" << endl;
        printStatus();
    } else {
        cout << "Tidur " + subAct + " gagal!" << endl;
    }
}

void Sims::doMakan(int option) {
    bool actStatus = false;
    string subAct;

    switch (option) {
        case MAKAN_HAMBURGER:
            actStatus = changeStatus(0, 5, 0);
            subAct = "hamburger";
            break;
        case MAKAN_PIZZA:
            actStatus = changeStatus(0, 10, 0);
            subAct = "pizza";
            break;
        case MAKAN_STEAK_AND_BEANS:
            actStatus = changeStatus(0, 15, 0);
            subAct = "steak and beans";
            break;
        default:
            cout << "Opsi tidak valid!" << endl;
            break;
    }

    if (actStatus) {
        cout << "Makan " + subAct + " berhasil!" << endl;
        printStatus();
    } else {
        cout << "Makan " + subAct + " gagal!" << endl;
    }
}

void Sims::doMinum(int option) {
    bool actStatus = false;
    string subAct;

    switch (option) {
        case MINUM_AIR:
            actStatus = changeStatus(-5, 0, 0);
            subAct = "air";
            break;
        case MINUM_KOPI:
            actStatus = changeStatus(-10, 5, 0);
            subAct = "kopi";
            break;
        case MINUM_JUS:
            actStatus = changeStatus(-5, 10, 0);
            subAct = "jus";
            break;
        default:
            cout << "Opsi tidak valid!" << endl;
            break;
    }

    if (actStatus) {
        cout << "Minum " + subAct + " berhasil!" << endl;
        printStatus();
    } else {
        cout << "Minum " + subAct + " gagal!" << endl;
    }
}

void Sims::doBuangAir(int option) {
    bool actStatus = false;
    string subAct;

    switch (option) {
        case BUANG_AIR_KECIL:
            actStatus = changeStatus(5, 0, 0);
            subAct = "kecil";
            break;
        case BUANG_AIR_BESAR:
            actStatus = changeStatus(10, -5, 0);
            subAct = "besar";
            break;
        default:
            cout << "Opsi tidak valid!" << endl;
            break;
    }

    if (actStatus) {
        cout << "Buang air " + subAct + " berhasil!" << endl;
        printStatus();
    } else {
        cout << "Buang air " + subAct + " gagal!" << endl;
    }
}

void Sims::doSosialisasiKeKafe() {
    bool actStatus = false;
    string subAct;

    actStatus = changeStatus(-5, -10, 15);
    if (actStatus) {
        cout << "Sosialisasi berhasil!" << endl;
        printStatus();
    } else {
        cout << "Sosialisasi gagal!" << endl;
    }
}

void Sims::doBermainMedsos() {
    bool actStatus = false;
    string subAct;

    actStatus = changeStatus(0, -10, 10);
    if (actStatus) {
        cout << "Bermain medsos berhasil!" << endl;
        printStatus();
    } else {
        cout << "Bermain medsos gagal!" << endl;
    }
}

void Sims::doBermainKomputer() {
    bool actStatus = false;
    string subAct;

    actStatus = changeStatus(0, -10, 15);
    if (actStatus) {
        cout << "Bermain komputer berhasil!" << endl;
        printStatus();
    } else {
        cout << "Bermain komputer gagal!" << endl;
    }
}

void Sims::doMandi() {
    bool actStatus = false;
    string subAct;

    actStatus = changeStatus(15, -5, 0);
    if (actStatus) {
        cout << "Mandi berhasil!" << endl;
        printStatus();
    } else {
        cout << "Mandi gagal!" << endl;
    }
}

void Sims::doCuciTangan() {
    bool actStatus = false;
    string subAct;

    actStatus = changeStatus(5, 0, 0);
    if (actStatus) {
        cout << "Cuci tangan berhasil!" << endl;
        printStatus();
    } else {
        cout << "Cuci tangan gagal!" << endl;
    }
}

void Sims::doMendengarMusik() {
    bool actStatus = false;
    string subAct;

    actStatus = changeStatus(0, -5, 10);
    if (actStatus) {
        cout << "Mendengar musik berhasil!" << endl;
        printStatus();
    } else {
        cout << "Mendengar musik gagal!" << endl;
    }
}

void Sims::doMembaca(int option) {
    bool actStatus = false;
    string subAct;

    switch (option) {
        case BACA_KORAN:
            actStatus = changeStatus(0, -5, 5);
            subAct = "koran";
            break;
        case BACA_NOVEL:
            actStatus = changeStatus(0, -5, 10);
            subAct = "novel";
            break;
        default:
            cout << "Opsi tidak valid!" << endl;
            break;
    }

    if (actStatus) {
        cout << "Membaca " + subAct + " berhasil!" << endl;
        printStatus();
    } else {
        cout << "Membaca " + subAct + " gagal!" << endl;
    }
}

bool Sims::isWin() {
    return ((hygiene == 15) && (energy == 15) && (fun == 15));
}

bool Sims::isLose() {
    return ((hygiene == 0) && (energy == 0) && (fun == 0));
}

void Sims::printStatus() {
    cout << "Hygiene  : " << hygiene << endl;
    cout << "Energy   : " << energy << endl;
    cout << "Fun      : " << fun << endl;
}
