// Studentas.h

#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <string>
#include <vector>
#include "median.h"

class Studentas {
private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> pazymiai_;
    int egzaminas_;

public:
    Studentas();
    Studentas(std::istream& is);

    std::string vardas() const;
    std::string pavarde() const;

    double galutinisBalas(double (*mediana)(std::vector<int>)) const;
    std::istream& skaityti(std::istream& is);
};

bool compare(const Studentas& s1, const Studentas& s2);
bool comparePagalPavarde(const Studentas& s1, const Studentas& s2);
bool comparePagalEgza(const Studentas& s1, const Studentas& s2);

#endif  // STUDENTAS_H
