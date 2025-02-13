#pragma once
#include <iostream>

class Postac 
{
protected:
    std::string nazwa;
    int punktyZycia;
    int wytrzymalosc;

public:
    Postac() {}
    Postac(std::string nazwa, int punktyZycia = 100, int wytrzymalosc = 100)
        : nazwa(nazwa), punktyZycia(punktyZycia), wytrzymalosc(wytrzymalosc) 
    {
        std::cout << "Stworzono Postac:" << std::endl;
        std::cout << "Nazwa: " << nazwa << std::endl;
        std::cout << "HP: " << punktyZycia << std::endl;
        std::cout << "Wytrztmalosc: " << wytrzymalosc << std::endl;
    }

    virtual void atak(Postac& przeciwnik) = 0;

    std::string getNazwa() const { return nazwa; }
    int getPunktyZycia() const { return punktyZycia; }
    int getWytrzymalosc() const { return wytrzymalosc; }

    void setPunktyZycia(int nowePunktyZycia) { punktyZycia = nowePunktyZycia; }

    friend std::istream& operator>>(std::istream& wejscie, Postac& p);
    friend std::ostream& operator<<(std::ostream& wyjscie, const Postac& p);
};

std::istream& operator>>(std::istream& wejscie, Postac& p) 
{
    wejscie >> p.nazwa;
    wejscie >> p.punktyZycia;
    wejscie >> p.wytrzymalosc;
    return wejscie;
}

std::ostream& operator<<(std::ostream& wyjscie, const Postac& p) 
{
    wyjscie << p.nazwa << " ";
    wyjscie << p.punktyZycia << " ";
    wyjscie << p.wytrzymalosc;
    return wyjscie;
}
