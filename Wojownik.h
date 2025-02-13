#pragma once
#include "Postac.h"

class Wojownik : public Postac 
{
private:
    int sila;

public:
    Wojownik(std::string nazwa, int punktyZycia = 100, int wytrzymalosc = 100, int sila = 10)
        : Postac(nazwa, punktyZycia, wytrzymalosc), sila(sila) {}

    void atak(Postac& przeciwnik) override 
    {
        int obrazenia = sila + (std::rand() % 10);
        std::cout << nazwa << " atakuje " << przeciwnik.getNazwa() << " i zadaje " << obrazenia << " obrazen!\n";
        przeciwnik.setPunktyZycia(przeciwnik.getPunktyZycia() - obrazenia);
    }
    friend std::istream& operator>>(std::istream& wejscie, Wojownik& p);
    friend std::ostream& operator<<(std::ostream& wyjscie, const Wojownik& p);
};
std::istream& operator>>(std::istream& wejscie, Wojownik& p) 
{
    wejscie >> p.nazwa;
    wejscie >> p.punktyZycia;
    wejscie >> p.wytrzymalosc;
    wejscie >> p.sila;
    return wejscie;
}

std::ostream& operator<<(std::ostream& wyjscie, const Wojownik& p) 
{
    wyjscie << p.nazwa << " ";
    wyjscie << p.punktyZycia << " ";
    wyjscie << p.wytrzymalosc;
    wyjscie << p.sila;
    return wyjscie;
}
