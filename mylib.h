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


class Studentas {
private:
    string vardas1 = "", pavarde1 = "";
    vector<int> paz1;
    int egz1 = 0;

public:
    // Constructor
    Studentas() {}

    // Getters and Setters
    string vardas() const { return vardas1; }
    void vardas(const string& v) { vardas1 = v; }

    string pavarde() const { return pavarde1; }
    void pavarde(const string& p) { pavarde1 = p; }

    vector<int> paz() const { return paz1; }
    void paz(const vector<int>& p) { paz1 = p; }

    int egz() const { return egz1; }
    void egz(int e) { egz1 = e; }
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
