#include "console.h"

void Console::exec() {
    menu();
}

void Console::menu() {
    int op;
    bool exit = false;

    while (!exit) {
        system("cls");
        welcomeBanner();
        cout << menuText;
        validateCinInt("Masukkan nomor pilihan menu: ", &op);
        switch (op) {
          case 1:
              start();
              break;
          case 2:
              about();
              system("pause");
              break;
          case 3:
              cout << endl;
              cout << "Terima kasih telah bermain..." << endl;
              cout << "Kau berhasil kembali ke dunia nyata..." << endl;
              exit = true;
              break;
          default:
              cout << "Menu tidak valid!\n\n";
              system("pause");
              break;
        }
    }
}

void Console::start() {
    Sims player = Sims();
    string name;
    bool gameOver = false;

    system("cls");
    newGameBanner();

    cout << "Masukkan nama anda: ";
    cin >> name;
    player.setName(name); cout << endl;

    printWrap("Selamat pagi, " + player.getName() + "! Pagi yang indah..."); cout << endl;
    printWrap("Kau adalah seorang mahasiswa biasa yang bercita-cita menjadi seseorang yang luar biasa.");
    printWrap("Oleh karena itu, sekarang kau tinggal di kota Shoors yang jauh dari kampung halamanmu untuk menuntut ilmu di IT*.");
    printWrap("Apakah kau siap membuat dinastimu sendiri??"); cout << endl;
    system("pause");

    while (!gameOver) {
        system("cls");
        statusBar(player);
        doAct(&player); cout << endl;
        system("pause");
        if (player.isWin()) {
            system("cls");
            gameOver = true;
            gameWinBanner();
            printWrap("Yeayy, kamu berhasil menjalani kehidupan (palsu) dengan sangat baik. Tapi jangan lupa kehidupan yang asli juga broo...");
            printWrap("Terima kasih telah bermain..."); cout << endl;
            system("pause");
        } else if (player.isLose()) {
            system("cls");
            gameOver = true;
            gameLoseBanner();
            printWrap("Waduh kamu kalah... Berarti kamu emang gak boleh main game dah kayaknya, kecuali game ini sih...");
            printWrap("Coba lagi lah kuyy..."); cout << endl;
            system("pause");
        }
    }
}

void Console::about() {
    system("cls");
    aboutBanner();

    printCenter("The Sims 10"); cout << endl;
    printCenter("Created by GreeksForGreeks");
    printCenter("Copyright 2019"); cout << endl;
}

void Console::welcomeBanner() {
    openBanner("data/welcomeBanner.txt");

    printCenter("Welcome to The Sims 10");
    srand(time(0));
    printCenter(welcome[rand() % 4]); cout << endl;
}

void Console::newGameBanner() {
    openBanner("data/newGameBanner.txt");
}

void Console::gameWinBanner() {
    openBanner("data/gameWinBanner.txt");
}

void Console::gameLoseBanner() {
    openBanner("data/gameLoseBanner.txt");
}

void Console::aboutBanner() {
    openBanner("data/aboutBanner.txt");
}

void Console::statusBar(Sims s) {
    string name = (s.getName().length() > 37) ? (s.getName().substr(0, 34) + "...") : (s.getName());

    cout << "|===================================================================|" << endl;
    cout << "|  " << name << setfill(' ') << setw(39 - s.getName().length()) << "  ";
    cout << "Hyg: " << setfill('0') << setw(2) << s.getHygiene() << "  ";
    cout << "En: " << setfill('0') << setw(2) << s.getEnergy() << "  ";
    cout << "Fun: " << setfill('0') << setw(2) << s.getFun() << "  |" << endl;
    cout << "|===================================================================|" << endl << endl;
}

void Console::doAct(Sims * s) {
    int act, subAct;

    cout << "Apa yang ingin kau lakukan??\n" << actText << endl;
    validateCinInt("Masukkan nomor pilihan yang ingin anda lakukan: ", &act);
    switch (act) {
        case 1:
            cout << subTidur << endl;
            validateCinInt("Masukkan nomor pilihan tidur yang ingin anda lakukan: ", &subAct);
            switch (subAct) {
                case 1:
                    (*s).doTidur(TIDUR_SIANG);
                    break;
                case 2:
                    (*s).doTidur(TIDUR_MALAM);
                    break;
                default:
                    cout << "Opsi tidak valid!" << endl;
                    break;
            }
            break;
        case 2:
            cout << subMakan << endl;
            validateCinInt("Masukkan nomor pilihan makanan yang ingin anda makan: ", &subAct);
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
                default:
                    cout << "Opsi tidak valid!" << endl;
                    break;
            }
            break;
        case 3:
            cout << subMinum << endl;
            validateCinInt("Masukkan nomor pilihan minuman yang ingin anda minum: ", &subAct);
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
                default:
                    cout << "Opsi tidak valid!" << endl;
                    break;
            }
            break;
        case 4:
            cout << subBuangAir << endl;
            validateCinInt("Masukkan nomor pilihan buang air yang ingin anda lakukan: ", &subAct);
            switch (subAct) {
                case 1:
                    (*s).doBuangAir(BUANG_AIR_KECIL);
                    break;
                case 2:
                    (*s).doBuangAir(BUANG_AIR_BESAR);
                    break;
                default:
                    cout << "Opsi tidak valid!" << endl;
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
            cout << subBaca << endl;
            validateCinInt("Masukkan nomor pilihan bacaan yang ingin anda baca: ", &subAct);
            switch (subAct) {
                case 1:
                    (*s).doMembaca(BACA_KORAN);
                    break;
                case 2:
                    (*s).doMembaca(BACA_NOVEL);
                    break;
                default:
                    cout << "Opsi tidak valid!" << endl;
                    break;
            }
            break;
        default:
            cout << "Opsi tidak valid!" << endl;
            break;
    }
}

void Console::printCenter(string s) {
    int len = s.length();
    int center = (int) ((69 - len) / 2);

    for (int i = 0; i < center; i++)
        cout << ' ';
    cout << s << endl;
}

void Console::printWrap(string s) {
    int x, loc = 69;

    while (loc < s.length()) {
        x = s.rfind(' ', loc);
        s.at(x) = '\n';
        loc += 69;
    }
    cout << s << endl;
}

void Console::openBanner(string filepath) {
    ifstream f;
    string banner;

    f.open(filepath);

    cout << "#####################################################################" << endl;
    while (getline(f, banner))
        printCenter(banner);
    cout << "#####################################################################" << endl << endl;

    f.close();
}

void Console::validateCinInt(string text, int * var) {
    cout << text;
    cin >> (*var);
    while (!cin) {
        cout << "Hanya menerima input integer!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << text;
        cin >> (*var);
    }
}
