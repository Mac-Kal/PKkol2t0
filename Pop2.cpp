
// budynek.h (Header file)

#ifndef BUDYNEK_H
#define BUDYNEK_H

#include <string>

class Miejscowosc {
public:
    Miejscowosc(const std::string& nazwa);
    const std::string& getNazwa() const;

private:
    std::string nazwa;
};
class Budynek {
public:
    enum Typ { MIESZKALNY, PUBLICZNY, KOMERCYJNY };

    Budynek(const Miejscowosc& miejscowosc, const std::string& ulica, int numer, int kodPocztowy, double metraz, Typ typ);
    ~Budynek();

    // Other public methods (getters, setters, etc.)
virtual double obliczPodatek() const;
    operator double() const; // Conversion to double (przekatna)

    static int getLiczbaInnychBudynkow();

private:
    // Private member variables

    static int liczbaInnychBudynkow;
};
class Posiadlosc : public Budynek {
public:
    Posiadlosc(const Miejscowosc& miejscowosc, const std::string& ulica, int numer, int kodPocztowy, double metraz, Typ typ, double dzialka);
    double getDzialka() const;
    void setDzialka(double dz);

    double obliczPodatek() const override;
    bool operator==(const Posiadlosc& other) const; // Equality operator

private:
    double dzialka;
};

#endif // BUDYNEK_H

// budynek.cpp (Source file)

#include "budynek.h"

// Implement constructors, getters, setters, and other methods for both classes
// ...

// Budynek implementation
double Budynek::obliczPodatek() const {
    return metraz * 10;
}

Budynek::operator double() const {
    return metraz * 1.41421356; // Assuming square shape (diagonal = sqrt(2) * side)
}

// Posiadlosc implementation
double Posiadlosc::obliczPodatek() const {
    return Budynek::obliczPodatek() + dzialka * 5;
}

bool Posiadlosc::operator==(const Posiadlosc& other) const {
    return (this->getMiejscowosc().getNazwa() == other.getMiejscowosc().getNazwa() &&
            this->getMetraz() == other.getMetraz() &&
            this->dzialka == other.dzialka);
}
