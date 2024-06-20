// Posiadlosc.h
#ifndef POSIADLOSC_H
#define POSIADLOSC_H

#include "Budynek.h"

class Posiadlosc : public Budynek {
public:
    Posiadlosc(const char* ulica, const char* numer, const char* kodPocztowy,
        double metraz, const char* typ, double dzialkaTerenowa);

    double obliczPodatek() const override;

private:
    double dzialkaTerenowa;
};

#endif // POSIADLOSC_H

//Posiadlosc.cpp
#include "Posiadlosc.h"

Posiadlosc::Posiadlosc(const char* ulica, const char* numer, const char* kodPocztowy,
    double metraz, const char* typ, double dzialkaTerenowa)
    : Budynek(ulica, numer, kodPocztowy, metraz, typ), dzialkaTerenowa(dzialkaTerenowa) {

}

double Posiadlosc::obliczPodatek() const {
    return Budynek::obliczPodatek() + 5.0 * dzialkaTerenowa; 
}

//Budynek.cpp
#include "Budynek.h"
#include <cstring> 

Budynek::Budynek(const char* ulica, const char* numer, const char* kodPocztowy,
    double metraz, const char* typ)
    : metraz(metraz) {
    
    strcpy_s(this->ulica, ulica);
    strcpy_s(this->numer, numer);
    strcpy_s(this->kodPocztowy, kodPocztowy);
    strcpy_s(this->typ, typ);
}

//Budynek.h
#ifndef BUDYNEK_H
#define BUDYNEK_H

class Budynek {
public:
    Budynek(const char* ulica, const char* numer, const char* kodPocztowy,
        double metraz, const char* typ);

    const char* getUlica() const;
    const char* getNumer() const;
    const char* getKodPocztowy() const;
    double getMetraz() const;
    const char* getTyp() const;

    void setUlica(const char* ulica);
    void setNumer(const char* numer);
    void setKodPocztowy(const char* kodPocztowy);
    void setMetraz(double metraz);
    void setTyp(const char* typ);

    
    virtual double obliczPodatek() const;

private:
    char ulica[100];
    char numer[20];
    char kodPocztowy[10];
    double metraz;
    char typ[50];
};

#endif // BUDYNEK_H
