#include "sims.h"

Sims::Sims (string name) {
    name = name;
    hygiene = 0;
    energy = 10;
    fun = 0;
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
    switch (option) {
      case TIDUR_SIANG:
          changeStatus(0, 10, 0);
          break;
      case TIDUR_MALAM:
          changeStatus(0, 15, 0);
          break;
      default:
          cout << "Opsi tidak valid!" << '\n';
          break;
    }
}

void Sims::doMakan(int option) {
    switch (option) {
      case MAKAN_HAMBURGER:
          changeStatus(0, 5, 0);
          break;
      case MAKAN_PIZZA:
          changeStatus(0, 10, 0);
          break;
      case MAKAN_STEAK_AND_BEANS:
          changeStatus(0, 15, 0);
          break;
      default:
          cout << "Opsi tidak valid!" << '\n';
          break;
    }
}

void Sims::doMinum(int option) {
    switch (option) {
      case MINUM_AIR:
          changeStatus(-5, 0, 0);
          break;
      case MINUM_KOPI:
          changeStatus(-10, 5, 0);
          break;
      case MINUM_JUS:
          changeStatus(-5, 10, 0);
          break;
      default:
          cout << "Opsi tidak valid!" << '\n';
          break;
    }
}

void Sims::doBuangAir(int option) {
    switch (option) {
      case BUANG_AIR_KECIL:
          changeStatus(5, 0, 0);
          break;
      case BUANG_AIR_BESAR:
          changeStatus(10, -5, 0);
          break;
      default:
          cout << "Opsi tidak valid!" << '\n';
          break;
    }
}

void Sims::doSosialisasiKeKafe() {
    changeStatus(-5, -10, 15);
}

void Sims::doBermainMedsos() {
    changeStatus(0, -10, 10);
}

void Sims::doBermainKomputer() {
    changeStatus(0, -10, 15);
}

void Sims::doMandi() {
    changeStatus(15, -5, 0);
}

void Sims::doCuciTangan() {
    changeStatus(5, 0, 0);
}

void Sims::doMendengarMusik() {
    changeStatus(0, -5, 10);
}

void Sims::doMembaca(int option) {
    switch (option) {
      case BACA_KORAN:
          changeStatus(0, -5, 5);
          break;
      case BACA_NOVEL:
          changeStatus(0, -5, 10);
          break;
      default:
          cout << "Opsi tidak valid!" << '\n';
          break;
    }
}
