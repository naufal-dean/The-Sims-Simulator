#ifndef CONSOLE_H
#define CONSOLE_H

#include <bits/stdc++.h>
#include "sims.h"

using namespace std;

class Console {
private:
    //** Constants **//
    const static int NMax = 4;
    const string welcome[NMax] = {"Bersiaplah untuk bermain!", "Rasakan permainan yang menyenangkan!",
                                "Simulasikan kehidupanmu!", "Coba sekali bermain susah berhentinya!"};
    const string menuText = "Menu\n"
                            "1. New Game\n"
                            "2. About\n"
                            "3. Exit\n";
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
                            "1. Kecil\n"
                            "2. Besar\n";
    const string subBaca =  "Jenis bacaan:\n"
                            "1. Koran\n"
                            "2. Novel\n";

    //** Interface Function **//
    void menu();
    void start();
    void about();
    void welcomeBanner();
    void newGameBanner();
    void gameWinBanner();
    void gameLoseBanner();
    void aboutBanner();
    //** Sims Function **//
    void statusBar(Sims s);
    void doAct(Sims * s);
    //** Utility **//
    void printCenter(string s);
    void printWrap(string s);
    void openBanner(string filepath);
    void validateCinInt(string text, int * var);

public:
    void exec();
};

#endif // CONSOLE_H
