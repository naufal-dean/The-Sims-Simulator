#include <bits/stdc++.h>
#include "sims.h"

using namespace std;

void menu();
void start();
void doAct(Sims * s);

const int NMax = 4;
string s[NMax] = {"Bersiaplah untuk bermain!", "Rasakan permainan yang menyenangkan!",
 "Simulasikan kehidupanmu!", "Coba sekali bermain susah berhentinya!"};

int main() {
    cout << "Welcome to The Simz 10\n";
    srand(time(0));
    cout << s[rand() % 4] << "\n\n";

    menu();
    return 0;
}

const string menuText = "Select Menu\n"
                        "1. New Game\n"
                        "2. Load Game\n"
                        "3. About\n"
                        "4. Exit\n";
const string actText =  "Menu aksi:\n"
                        "1. Tidur           7. Bermain Komputer\n"
                        "2. Makan           8. Mandi\n"
                        "3. Minum           9. Cuci Tangan\n"
                        "4. Buang Air       10. Mendengar Musik\n"
                        "5. Sosialisasi     11. Membaca\n"
                        "6. Bermain Medsos\n";
const string subTidur = "Jenis tidur:\n"
                        "1. Siang\n"
                        "2. Malam\n";
const string subMakan = "Makanan:\n"
                        "1. Hamburger\n"
                        "2. Pizza\n"
                        "3. Steak and Beans\n";
const string subMinum = "Minuman:\n"
                        "1. Air\n"
                        "2. Kopi\n"
                        "3. Jus\n";
const string subBuangAir = "Buang air:\n"
                        "1. Besar\n"
                        "2. Kecil\n";
const string subBaca =  "Jenis bacaan:\n"
                        "1. Koran\n"
                        "2. Novel\n";

void menu() {
    int op;

    cout << menuText;
    cout << "Masukkan nomor pilihan : ";
    cin >> op;
    switch (op) {
      case 1:
          start();
          menu();
          break;
      case 2:
          // TODO: read file?? save state by saving menu sequence
          cout << "Under construction...";
          /*
          ofstream file;
          file.open("<namafile>");
          file << "writing to the file";
          file.close();
          */
          break;
      case 3:
          cout  << "The Simz 10\n\n"
                << "Created by Anonymous\n"
                << "Copyright 2019\n\n";
          menu();
          break;
      case 4:
          cout << "Sampai jumpa...\n";
          exit(0);
          break;
      default:
          cout << "Menu tidak valid!";
          break;
    }
}

void start() {
    string name;
    bool gameOver = false;

    cout << "Masukkan nama anda: ";
    cin >> name;
    Sims player(name);

    cout << "\nSelamat pagi, " << name << "! Pagi yang indah...\n";
    while (!gameOver) {
        cout << "\n";
        doAct(&player);
        if (player.isWin()) {
            gameOver = true;
            cout << "Yeayy, kamu memenangkan game ini!\n\n";
        } else if (player.isLose()) {
            gameOver = true;
            cout << "Yahh, kamu kalah...\n\n";
        }
    }

}

void doAct(Sims * s) {
    int act, subAct;

    cout << "Apa yang ingin kau lakukan??\n\n" << actText;
    cout << "\nMasukkan nomor pilihan yang ingin anda lakukan : ";
    cin >> act;
    switch (act) {
        case 1:
            cout << subTidur;
            cout << "\nMasukkan nomor pilihan tidur yang ingin anda lakukan : ";
            cin >> subAct;
            switch (subAct) {
                case 1:
                    (*s).doTidur(TIDUR_SIANG);
                    break;
                case 2:
                    (*s).doTidur(TIDUR_MALAM);
                    break;
            }
            break;
        case 2:
            cout << subMakan;
            cout << "\nMasukkan nomor pilihan makanan yang ingin anda makan : ";
            cin >> subAct;
            switch (subAct) {
                case 1:
                    (*s).doMakan(MAKAN_HAMBURGER);
                    break;
                case 2:
                    (*s).doMakan(MAKAN_PIZZA);
                    break;
                case 3:
                    (*s).doMakan(MAKAN_STEAK_AND_BEANS);
                    break;
            }
            break;
        case 3:
            cout << subMinum;
            cout << "\nMasukkan nomor pilihan minuman yang ingin anda minum : ";
            cin >> subAct;
            switch (subAct) {
                case 1:
                    (*s).doMinum(MINUM_AIR);
                    break;
                case 2:
                    (*s).doMinum(MINUM_KOPI);
                    break;
                case 3:
                    (*s).doMinum(MINUM_JUS);
                    break;
            }
            break;
        case 4:
            cout << subBuangAir;
            cout << "\nMasukkan nomor pilihan buang air yang ingin anda lakukan : ";
            cin >> subAct;
            switch (subAct) {
                case 1:
                    (*s).doBuangAir(BUANG_AIR_KECIL);
                    break;
                case 2:
                    (*s).doBuangAir(BUANG_AIR_BESAR);
                    break;
            }
            break;
        case 5:
            (*s).doSosialisasiKeKafe();
            break;
        case 6:
            (*s).doBermainMedsos();
            break;
        case 7:
            (*s).doBermainKomputer();
            break;
        case 8:
            (*s).doMandi();
            break;
        case 9:
            (*s).doCuciTangan();
            break;
        case 10:
            (*s).doMendengarMusik();
            break;
        case 11:
            cout << subBaca;
            cin >> subAct;
            cout << "\nMasukkan nomor pilihan bacaan yang ingin anda baca : ";
            switch (subAct) {
                case 1:
                    (*s).doMembaca(BACA_KORAN);
                    break;
                case 2:
                    (*s).doMembaca(BACA_NOVEL);
                    break;
            }
            break;
    }
}
