#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <iomanip>
#include <string>
#include "sims.h"

using namespace std;

class Console {
private:
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
public:
    void exec();
    void menu();
    void start();
    void statusBar(Sims s);
    void doAct(Sims * s);
};

#endif // CONSOLE_H
