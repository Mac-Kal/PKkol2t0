// Plik nagłówkowy Budynek.h
#ifndef BUDYNEK_H
#define BUDYNEK_H

class Budynek {
public:
    Budynek(const char* ulica, const char* numer, const char* kodPocztowy,
            double metraz, const char* typ);

    // Gettery
    const char* getUlica() const;
    const char* getNumer() const;
    const char* getKodPocztowy() const;
    double getMetraz() const;
    const char* getTyp() const;

    // Setery
    void setUlica(const char* ulica);
    void setNumer(const char* numer);
    void setKodPocztowy(const char* kodPocztowy);
    void setMetraz(double metraz);
    void setTyp(const char* typ);

    // Oblicz podatek
    virtual double obliczPodatek() const;

private:
    char ulica[100]; // Przykładowy rozmiar tablicy char
    char numer[20];
    char kodPocztowy[10];
    double metraz;
    char typ[50];
};

#endif // BUDYNEK_H

// Plik źródłowy Budynek.cpp
#include "Budynek.h"
#include <cstring> // Dla funkcji strcpy

Budynek::Budynek(const char* ulica, const char* numer, const char* kodPocztowy,
                 double metraz, const char* typ)
    : metraz(metraz) {
    // Kopiowanie danych do tablic char
    strcpy(this->ulica, ulica);
    strcpy(this->numer, numer);
    strcpy(this->kodPocztowy, kodPocztowy);
    strcpy(this->typ, typ);
}

// Implementacje pozostałych metod

// Plik nagłówkowy Posiadlosc.h
#ifndef POSIADLOSC_H
#define POSIADLOSC_H

#include "Budynek.h"

class Posiadlosc : public Budynek {
public:
    Posiadlosc(const char* ulica, const char* numer, const char* kodPocztowy,
               double metraz, const char* typ, double dzialkaTerenowa);

    // Oblicz podatek dla posiadłości
    double obliczPodatek() const override;

private:
    double dzialkaTerenowa;
};

#endif // POSIADLOSC_H

// Plik źródłowy Posiadlosc.cpp
#include "Posiadlosc.h"

Posiadlosc::Posiadlosc(const char* ulica, const char* numer, const char* kodPocztowy,
                       double metraz, const char* typ, double dzialkaTerenowa)
    : Budynek(ulica, numer, kodPocztowy, metraz, typ), dzialkaTerenowa(dzialkaTerenowa) {
    // Tutaj możesz dodać dodatkowe ograniczenia dla dzialkaTerenowa (np. nieujemność).
}

double Posiadlosc::obliczPodatek() const {
    return Budynek::obliczPodatek() + 5.0 * dzialkaTerenowa; // Dodatkowo 5 PLN za m² działki terenowej
}
