#include "mylib.h"

char pasirinkimas;
list<Studentas> studentai;

bool compareByName(const Studentas& s1, const Studentas& s2) {
    return s1.vardas < s2.vardas;
}
double pazymiai(list<int> paz, bool armediana) {
    int n = paz.size();
    if (n == 0) {
        return 0.0;
    }
    double sum = 0;
    for (auto it = paz.begin(); it != paz.end(); ++it) {
        sum += *it;
    }
    if (armediana) {
        auto med = paz.begin();
        std::advance(med, n / 2);
        paz.sort();
        if (n % 2 == 0) {
            auto med2 = med;
            std::advance(med2, -1);
            return static_cast<double>(*med + *med2) / 2;
        } else {
            return static_cast<double>(*med);
        }
    } else {
        return sum / n;
    }
}



void generateFile(int n) {
  std::random_device rd;
  std::mt19937 eng(rd());
  std::uniform_int_distribution<> distr(1, 10);
  ofstream fr("studentai_" + std::to_string(n) + ".txt");
    fr << setw(15) << left << "Vardas"<< setw(20) << left << "Pavarde";
        for (int j = 0; j < 15; j++) {
            fr << setw(2) << right<<"ND"<< setw(3) << left << j + 1;
        }
        fr << setw(3) << right << "Egz" << "\n";
    
        for (int i = 0; i < n; i++) {
            fr<< "\n";
            fr << setw(15) << left << ("Vardas" + to_string(i+1))
               << setw(20) << left << ("Pavarde" + to_string(i+1));
            
            for (int j = 0; j < 15; j++) {
                fr << setw(5) << left << distr(eng);
            }
            
            fr << left << distr(eng);
        }
}

void pild(Studentas &temp){
  cout << "Iveskite varda ir pavarde: ";
  cin >> temp.vardas >> temp.pavarde;

  cout << "Ar pazymiai turi buti atsitiktinai generuojami? Jeigu taip spauskite 1, jeigu ne 2 -  ";
  do{
  cin >> pasirinkimas;
  if (pasirinkimas != '1' && pasirinkimas != '2') cout << "Netinkamas pasirinkimas. Prašome pasirinkti 1 arba 2 - ";
  }while(pasirinkimas != '1' && pasirinkimas != '2');
    if (pasirinkimas == '1') {
        std::random_device rd;
        std::mt19937 eng(rd());
        std::uniform_int_distribution<> distr(1, 10);

        cout << "Namų darbų pazymys - ";
        temp.paz.push_back(distr(eng));
        cout << temp.paz.back() << endl;
        cout << "Egzamino pazymys - ";
        temp.egz = distr(eng);
        cout << temp.egz << endl;
    } else {
        cout << "Iveskite pazymius (baigti iveskite -1): " << endl;
        int pazymys;
          while (true) {
            cin >> pazymys;
            if (cin.fail()) {
              cin.clear();
              cin.ignore(numeric_limits < streamsize > ::max(), '\n');
              cout << "Klaida! Prašome įvesti sveikąjį skaičių: ";
              continue;
            }
            if (pazymys == -1) break;
            temp.paz.push_back(pazymys);
          }
          cout << "Egzamino pazymys - ";
          cin >> temp.egz;
          while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
            cout << "Klaida! Prašome įvesti sveikąjį skaičių: ";
            cin >> temp.egz;
          }
        }

}


void spausd(Studentas& temp, bool armediana, double galutinis) {
    cout << endl << left << setw(15) << temp.vardas << setw(20) << temp.pavarde << fixed << setprecision(2) << setw(15) << galutinis << endl;
}


void iskonsoles(int &n){
do {
  studentai.push_back(Studentas());//sukuria naują objektą "Studentas" ir prideda jį prie vektoriaus galo.
    auto it = studentai.begin(); // get iterator to first element of list
    std::advance(it, n); // advance iterator n positions
    pild(*it); // pass element pointed to by iterator to pild function

  n++;
  cout << "Jei norite įvesti dar vieną studentą paspauskite 1, jei norite baigti spauskite 2 - ";
      do{
      cin >> pasirinkimas;
      if (pasirinkimas != '1'   &&   pasirinkimas != '2')
      cout << "Netinkamas pasirinkimas. Prašome pasirinkti 1 arba 2. "<<endl;
      } while (pasirinkimas != '1'  &&  pasirinkimas != '2');
} while (pasirinkimas != '2');
}



void isfailo(ifstream& fd, int &n) {
    auto start = std::chrono::high_resolution_clock::now();
    if (!fd) {
        throw runtime_error("Nepavyko atidaryti failo");
    }
    string skaitymas;
    int paz_sk=0;
    while (skaitymas != "Egzaminas" && skaitymas != "egz" && skaitymas != "egzaminas"&& skaitymas != "Egz") {
        fd>>skaitymas;
        paz_sk++;
    }
    paz_sk=paz_sk-3;
    try {
        do {
            studentai.push_back(Studentas());
            Studentas& temp = studentai.back();
            if (!(fd >> temp.pavarde >> temp.vardas)) {
                break;
            }
            int pazymys;
            for (int i=0; i<paz_sk; i++) {
                if (!(fd >> pazymys)) {
                    throw runtime_error("Blogas duomenų formatas");
                }
                studentai.back().paz.push_back(pazymys);
            }
            if (!(fd >> studentai.back().egz)) {
                throw runtime_error("Blogas duomenų formatas");
            }
            n++;
        } while (!fd.eof());
    }
    catch (const runtime_error &a) {
        cout << "Klaida: " << a.what() << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    cout << n<<" elementų nuskaitymas užtruko: "<< diff.count() << " s\n";
    ofstream fr("laikai.txt");
    fr<< diff.count() << endl;
}

void pabaiga(int n){
    //skaiciuojamas galutinis balas su mediana arba vidurkiu
    cout << "Ar norite galutinio balo vidurkio (1), ar medianos (2)? ";
    do {
        cin >> pasirinkimas;
        if (pasirinkimas != '1' && pasirinkimas != '2') cout << "Netinkamas pasirinkimas. Prašome pasirinkti 1 arba 2 - ";
    } while (pasirinkimas != '1' && pasirinkimas != '2');
    
    bool armediana = (pasirinkimas == '2'); //char pakeiciamas i bool argumenta
    
    //cout << endl << left << setw(15) << "Vardas" << setw(20) << "Pavarde" << setw(15) << (armediana ? "Galutinis (Med.)" : "Galutinis (Vid.)") << endl;
    //cout << "-------------------------------------------------------------------------------------" << endl;
    
    auto start2 = std::chrono::high_resolution_clock::now();
    studentai.sort(compareByName);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2-start2; // Skirtumas (s)
    cout <<n<<" elementų rikiavimas uztruko: "<< diff2.count() << " s\n";
    ofstream fr("laikai.txt", std::ios::app);
    fr << diff2.count() << endl;
    
    auto start = std::chrono::high_resolution_clock::now();
    
    list<Studentas> vargsiukai;
    list<Studentas> saunuoliai;
    
    ofstream fd("vargsiukai.txt");
    ofstream fm("saunuoliai.txt");
    
    for (auto it = studentai.begin(); it != studentai.end(); ++it) {
        double galutinis = pazymiai(list<int>(it->paz.begin(), it->paz.end()), armediana) * 0.4 + it->egz * 0.6;
        
        // spausd(*it, armediana, galutinis);
        
        if (galutinis < 5) {
            vargsiukai.push_back(*it);
        } else {
            saunuoliai.push_back(*it);
        }
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    cout << n << " elementų rūšiavimas užtruko: " << diff.count() << " s\n";
    fr << diff.count() << endl;
    
    for (auto it = vargsiukai.begin(); it != vargsiukai.end(); ++it) {
        double galutinis = pazymiai(list<int>(it->paz.begin(), it->paz.end()), armediana) * 0.4 + it->egz * 0.6;
        isved(fd, *it, armediana, galutinis);
    }
    
    for (auto it = saunuoliai.begin(); it != saunuoliai.end(); ++it) {
        double galutinis = pazymiai(list<int>(it->paz.begin(), it->paz.end()), armediana) * 0.4 + it->egz * 0.6;
        isved(fm, *it, armediana, galutinis);
    }
}


void isved(ofstream& fr, Studentas& temp, bool armediana, double galutinis) {
    fr << left << setw(15) << temp.vardas << setw(20) << temp.pavarde << fixed << setprecision(2) << setw(15) << galutinis << endl;
}

