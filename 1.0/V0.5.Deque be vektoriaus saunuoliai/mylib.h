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
#include <deque>




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
using std::deque;

struct Studentas {
  string vardas = "", pavarde = "";
    deque<int> paz;
  int egz = 0;
};

extern char pasirinkimas;
void generateFile(int n);
extern deque<Studentas> studentai;
bool compareByName(const Studentas& s1, const Studentas& s2);
void pild(Studentas &temp);
void spausd(Studentas &temp, bool armediana, double galutinis);
double pazymiai(deque<int> paz, bool armediana);
void isfailo(ifstream& fd, int &n);
void iskonsoles(int &n);
void pabaiga(int n);
void isved(ofstream& fr, Studentas& temp, bool armediana, double galutinis);

#endif
