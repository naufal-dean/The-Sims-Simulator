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
    bool actStatus;

    switch (option) {
      case TIDUR_SIANG:
          actStatus = changeStatus(0, 10, 0);
          break;
      case TIDUR_MALAM:
          actStatus = changeStatus(0, 15, 0);
          break;
      default:
          cout << "Opsi tidak valid!" << '\n';
          break;
    }

    if (actStatus) {
        cout << "Tidur berhasil!" << "\n";
        printStatus();
    } else {
        cout << "Tidur gagal!" << "\n";
    }
}

void Sims::doMakan(int option) {
    bool actStatus;

    switch (option) {
      case MAKAN_HAMBURGER:
          actStatus = changeStatus(0, 5, 0);
          break;
      case MAKAN_PIZZA:
          actStatus = changeStatus(0, 10, 0);
          break;
      case MAKAN_STEAK_AND_BEANS:
          actStatus = changeStatus(0, 15, 0);
          break;
      default:
          cout << "Opsi tidak valid!" << '\n';
          break;
    }

    if (actStatus) {
        cout << "Makan berhasil!" << "\n";
        printStatus();
    } else {
        cout << "Makan gagal!" << "\n";
    }
}

void Sims::doMinum(int option) {
    bool actStatus;

    switch (option) {
      case MINUM_AIR:
          actStatus = changeStatus(-5, 0, 0);
          break;
      case MINUM_KOPI:
          actStatus = changeStatus(-10, 5, 0);
          break;
      case MINUM_JUS:
          actStatus = changeStatus(-5, 10, 0);
          break;
      default:
          cout << "Opsi tidak valid!" << '\n';
          break;
    }

    if (actStatus) {
        cout << "Minum berhasil!" << "\n";
        printStatus();
    } else {
        cout << "Minum gagal!" << "\n";
    }
}

void Sims::doBuangAir(int option) {
    bool actStatus;

    switch (option) {
      case BUANG_AIR_KECIL:
          actStatus = changeStatus(5, 0, 0);
          break;
      case BUANG_AIR_BESAR:
          actStatus = changeStatus(10, -5, 0);
          break;
      default:
          cout << "Opsi tidak valid!" << '\n';
          break;
    }

    if (actStatus) {
        cout << "Buang air berhasil!" << "\n";
        printStatus();
    } else {
        cout << "Buang air gagal!" << "\n";
    }
}

void Sims::doSosialisasiKeKafe() {
    bool actStatus;

    actStatus = changeStatus(-5, -10, 15);
    if (actStatus) {
        cout << "Sosialisasi berhasil!" << "\n";
        printStatus();
    } else {
        cout << "Sosialisasi gagal!" << "\n";
    }
}

void Sims::doBermainMedsos() {
    bool actStatus;

    actStatus = changeStatus(0, -10, 10);
    if (actStatus) {
        cout << "Bermain medsos berhasil!" << "\n";
        printStatus();
    } else {
        cout << "Bermain medsos gagal!" << "\n";
    }
}

void Sims::doBermainKomputer() {
    bool actStatus;

    actStatus = changeStatus(0, -10, 15);
    if (actStatus) {
        cout << "Bermain komputer berhasil!" << "\n";
        printStatus();
    } else {
        cout << "Bermain komputer gagal!" << "\n";
    }
}

void Sims::doMandi() {
    bool actStatus;

    actStatus = changeStatus(15, -5, 0);
    if (actStatus) {
        cout << "Mandi berhasil!" << "\n";
        printStatus();
    } else {
        cout << "Mandi gagal!" << "\n";
    }
}

void Sims::doCuciTangan() {
    bool actStatus;

    actStatus = changeStatus(5, 0, 0);
    if (actStatus) {
        cout << "Cuci tangan berhasil!" << "\n";
        printStatus();
    } else {
        cout << "Cuci tangan gagal!" << "\n";
    }
}

void Sims::doMendengarMusik() {
    bool actStatus;

    actStatus = changeStatus(0, -5, 10);
    if (actStatus) {
        cout << "Mendengar musik berhasil!" << "\n";
        printStatus();
    } else {
        cout << "Mendengar musik gagal!" << "\n";
    }
}

void Sims::doMembaca(int option) {
    bool actStatus;

    switch (option) {
      case BACA_KORAN:
          actStatus = changeStatus(0, -5, 5);
          break;
      case BACA_NOVEL:
          actStatus = changeStatus(0, -5, 10);
          break;
      default:
          cout << "Opsi tidak valid!" << '\n';
          break;
    }

    if (actStatus) {
        cout << "Membaca berhasil!" << "\n";
        printStatus();
    } else {
        cout << "Membaca gagal!" << "\n";
    }
}

bool Sims::isWin() {
    return ((hygiene == 15) && (energy == 15) && (fun == 15));
}

bool Sims::isLose() {
    return ((hygiene == 0) && (energy == 0) && (fun == 0));
}

void Sims::printStatus() {
    cout << "Hygiene  : " << hygiene << "\n";
    cout << "Energy   : " << energy << "\n";
    cout << "Fun      : " << fun << "\n";
}
