#pragma once
#include "Postac.h"

class Mag : public Postac 
{
private:
    int mana;

public:
    Mag(std::string nazwa, int punktyZycia = 100, int wytrzymalosc = 100, int mana = 100)
        : Postac(nazwa, punktyZycia, wytrzymalosc), mana(mana) {}

    void atak(Postac& przeciwnik) override 
    {
        int obrazenia;
        if (mana > 0)
        {
            obrazenia = mana + (std::rand() % 10);
            std::cout << nazwa << " rzuca zaklêcie na " << przeciwnik.getNazwa() << " i zadaje " << obrazenia << " obrazen!\n";
            przeciwnik.setPunktyZycia(przeciwnik.getPunktyZycia() - obrazenia);
            mana -= 10;
        }
        else
        {
            obrazenia = 0;
            std::cout << "Brak many :(";
        }
    }
    friend std::istream& operator>>(std::istream& wejscie, Mag& p);
    friend std::ostream& operator<<(std::ostream& wyjscie, const Mag& p);
};
std::istream& operator>>(std::istream& wejscie, Mag& p) 
{
    wejscie >> p.nazwa;
    wejscie >> p.punktyZycia;
    wejscie >> p.wytrzymalosc;
    wejscie >> p.mana;
    return wejscie;
}

std::ostream& operator<<(std::ostream& wyjscie, const Mag& p) 
{
    wyjscie << p.nazwa << " ";
    wyjscie << p.punktyZycia << " ";
    wyjscie << p.wytrzymalosc;
    wyjscie << p.mana;
    return wyjscie;
}
