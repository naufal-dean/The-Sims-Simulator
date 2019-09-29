#include "console.h"

void Console::exec() {
    cout << "Welcome to The Simz 10\n";
    srand(time(0));
    cout << welcome[rand() % 4] << "\n\n";

    menu();
}

void Console::menu() {
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
                << "Created by GreeksForGreeks\n"
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

void Console::start() {
    Sims player = Sims();
    string name;
    bool gameOver = false;

    cout << "Masukkan nama anda: ";
    cin >> name;
    player.setName(name);

    cout << "\nSelamat pagi, " << name << "! Pagi yang indah...\n";
    while (!gameOver) {
        cout << "\n";
        statusBar(player);
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

void Console::statusBar(Sims s) {
    cout << "|==================================================|\n";
    cout << "|  " << s.getName() << setfill(' ') << setw(22 - s.getName().length()) << "  ";
    cout << "Hyg: " << setfill('0') << setw(2) << s.getHygiene() << "  ";
    cout << "En: " << setfill('0') << setw(2) << s.getEnergy() << "  ";
    cout << "Fun: " << setfill('0') << setw(2) << s.getFun() << "  |\n";
    cout << "|==================================================|\n";
}

void Console::doAct(Sims * s) {
    int act, subAct;

    cout << "Apa yang ingin kau lakukan??\n" << actText;
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
            cout << "\nMasukkan nomor pilihan bacaan yang ingin anda baca : ";
            cin >> subAct;
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
