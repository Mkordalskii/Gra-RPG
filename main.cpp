#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Postac.h"
#include "Wojownik.h"
#include "Mag.h"

void pojedynek(Postac& p1, Postac& p2) 
{
    std::cout << "Pojedynek miedzy " << p1.getNazwa() << " i " << p2.getNazwa() << std::endl;
    while (p1.getPunktyZycia() > 0 && p2.getPunktyZycia() > 0) 
    {
        p1.atak(p2);
        if (p2.getPunktyZycia() <= 0) 
        {
            std::cout << p2.getNazwa() << " przegrywa pojedynek\n";
            return;
        }
        p2.atak(p1);
        if (p1.getPunktyZycia() <= 0) 
        {
            std::cout << p1.getNazwa() << " przegrywa pojedynek\n";
            return;
        }
    }
}

void zapiszDoPliku(const std::string& nazwaPliku, const Postac& postac) 
{
    std::ofstream plik(nazwaPliku, std::ios::app);
    if (plik.is_open()) {
        plik << postac << std::endl;
        plik.close();
    }
}

int main() 
{
    std::srand(std::time(0));

    Wojownik w("Wojownik1", 100, 80, 10);
    Mag m("Mag1", 100, 90, 20);

    std::cout << w << std::endl;
    std::cout << m << std::endl;

    //std::cin >> w;
    //std::cin >> m;

    pojedynek(w, m);

    zapiszDoPliku("postacie.txt", w);
    zapiszDoPliku("postacie.txt", m);

    return 0;
}
