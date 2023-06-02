// Studentas.cpp

#include "Studentas.h"

Studentas::Studentas() : egzaminas_(0) {}

Studentas::Studentas(std::istream& is) {
    skaityti(is);
}

std::string Studentas::vardas() const {
    return vardas_;
}

std::string Studentas::pavarde() const {
    return pavarde_;
}

double Studentas::galutinisBalas(double (*mediana)(std::vector<int>)) const {
    double vidurkis = 0;
    if (!pazymiai_.empty()) {
        vidurkis = mediana(pazymiai_);
    }
    return vidurkis * 0.4 + egzaminas_ * 0.6;
}

std::istream& Studentas::skaityti(std::istream& is) {
    std::cout << "Iveskite varda ir pavarde: ";
    is >> vardas_ >> pavarde_;

    std::cout << "Ar pazymiai turi buti atsitiktinai generuojami? Jeigu taip, spauskite 1, jeigu ne 2: ";
    char pasirinkimas;
    do {
        is >> pasirinkimas;
        if (pasirinkimas != '1' && pasirinkimas != '2') {
            std::cout << "Netinkamas pasirinkimas. Prašome pasirinkti 1 arba 2: ";
        }
    } while (pasirinkimas != '1' && pasirinkimas != '2');

    if (pasirinkimas == '1') {
        std::random_device rd;
        std::mt19937 eng(rd());
        std::uniform_int_distribution<> distr(1, 10);

        std::cout << "Namų darbų pazymys: ";
        int pazymys;
        while (is >> pazymys && pazymys != -1) {
            pazymiai_.push_back(pazymys);
        }

        std::cout << "Egzamino pazymys: ";
        is >> egzaminas_;
    } else {
        std::cout << "Iveskite pazymius (baigti iveskite -1): " << std::endl;
        int pazymys;
        while (is >> pazymys && pazymys != -1) {
            pazymiai_.push_back(pazymys);
        }

        std::cout << "Egzamino pazymys: ";
        is >> egzaminas_;
    }

    return is;
}

bool compare(const Studentas& s1, const Studentas& s2) {
    return s1.vardas() < s2.vardas();
}

bool comparePagalPavarde(const Studentas& s1, const Studentas& s2) {
    return s1.pavarde() < s2.pavarde();
}

bool comparePagalEgza(const Studentas& s1, const Studentas& s2) {
    return s1.galutinisBalas(median) < s2.galutinisBalas(median);
}
