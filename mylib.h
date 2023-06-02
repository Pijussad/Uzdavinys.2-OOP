#ifndef MYLIB_H
#define MYLIB_H

#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <limits>
#include <random>
#include <sstream>
#include <algorithm>
#include <sstream>
#include <chrono>




using std::cout;
using std::cin;
using std::endl;
using std::left;
using std::right;
using std::setw;
using std::setprecision;
using std::string;
using std::copy;
using std::fixed;
using std::sort;
using std::streamsize;
using std::numeric_limits;
using std::vector;
using std::ifstream;
using std::fstream;
using std::ofstream;
using std::istringstream;
using std::stringstream;
using std::stringstream;
using std::runtime_error;
using std::to_string;


class Zmogus
{
    protected:
        string vardas1, pavarde1;
    public:
        Zmogus() : vardas1(""), pavarde1("") {}
        Zmogus(string vardas, string pavarde) : vardas1(vardas), pavarde1(pavarde) {}
        virtual string vardas() const = 0;
        ~Zmogus() {}
};

class Studentas : public Zmogus
{
private:
    string vardas1 = "";
    string pavarde1 = "";
    vector<int> paz1;
    int egz1 = 0;

public:
    // Constructor
    Studentas() : Zmogus(), egz1(0) {}
    Studentas(string vardas, string pavarde, vector<int> paz, int egz)  : Zmogus(vardas,pavarde), paz1(paz), egz1(egz){}

    // Destructor
    ~Studentas() {paz1.clear();}

    // Copy constructor
    Studentas(const Studentas& other)
        : vardas1(other.vardas1),
          pavarde1(other.pavarde1),
          paz1(other.paz1),
          egz1(other.egz1) {}

    // Copy assignment operator
    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            vardas1 = other.vardas1;
            pavarde1 = other.pavarde1;
            paz1 = other.paz1;
            egz1 = other.egz1;
        }
        return *this;
    }

    // Move constructor
    Studentas(Studentas&& other)
        : vardas1(std::move(other.vardas1)),
          pavarde1(std::move(other.pavarde1)),
          paz1(std::move(other.paz1)),
    egz1(std::move(other.egz1)) {other.egz1=0;}

    // Move assignment operator
    Studentas& operator=(Studentas&& other) {
        if (this != &other) {
            vardas1 = std::move(other.vardas1);
            pavarde1 = std::move(other.pavarde1);
            paz1 = std::move(other.paz1);
            egz1 = std::move(other.egz1);
            other.egz1=0;
        }
        return *this;
    }

    // Getters and Setters
    string vardas() const { return vardas1; }
    void vardas(const string& v) { vardas1 = v; }

    string pavarde() const { return pavarde1; }
    void pavarde(const string& p) { pavarde1 = p; }

    vector<int> paz() const { return paz1; }
    void paz(const vector<int>& p) { paz1 = p; }

    int egz() const { return egz1; }
    void egz(int e) { egz1 = e; }
    
    Studentas operator+(const Studentas& other) const {
            Studentas result;

            // Combine the names
            result.vardas1 = vardas1 + " " + other.vardas1;
            result.pavarde1 = pavarde1 + " " + other.pavarde1;

            // Combine the vectors of grades
            result.paz1 = paz1;
            result.paz1.insert(result.paz1.end(), other.paz1.begin(), other.paz1.end());

            // Set the exam grade as the average of the two students
            result.egz1 = (egz1 + other.egz1);

            return result;
        }

};


extern char pasirinkimas;
void generateFile(int n);
extern vector<Studentas> studentai;
bool compareByName(const Studentas& s1, const Studentas& s2);
void pild(Studentas &temp);
void spausd(Studentas &temp, bool armediana, double galutinis);
double pazymiai(vector<int> paz, bool armediana);
void isfailo(ifstream& fd, int &n);
void iskonsoles(int &n);
void pabaiga(int n);
void isved(ofstream& fr, Studentas& temp, bool armediana, double galutinis);

#endif
