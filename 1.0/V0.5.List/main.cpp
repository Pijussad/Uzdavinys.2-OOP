#include "mylib.h"

int main() {
    int n = 0;
    double sum;
    cout << "Ar norite nuskaityti duomenis iš failo? Jei taip, įveskite 1, jei ne, įveskite 2: ";
    do{
        cin >> pasirinkimas;
        if (pasirinkimas != '1' && pasirinkimas != '2') cout << "Neteisinga įvestis, įveskite 1 arba 2.";
    }while(pasirinkimas != '1' && pasirinkimas != '2');
    
    if (pasirinkimas == '1') {
        //Pasirinkimas ar generuoti faila
        cout << "Ar norite sugeneruoti failą? Jei taip, įveskite 1, jei ne, įveskite 2: ";
        char pasirinkimas2;
        do{
            cin >> pasirinkimas2;
            if (pasirinkimas2 != '1' && pasirinkimas2 != '2') cout << "Neteisinga įvestis, įveskite 1 arba 2.";
        }while(pasirinkimas2 != '1' && pasirinkimas2 != '2');
        
        if (pasirinkimas2== '1' ){
            for(int i=1000; i<11000000; i=i*10){
                sum=0;
                n=0;
                auto start = std::chrono::high_resolution_clock::now();
                generateFile(i);
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> diff = end-start; // Skirtumas (s)
                cout<< i<<" elementų užpildymas užtruko: "<< diff.count() << " s\n";
                ofstream fr("laikai.txt");
                fr<< diff.count() << endl;
            }
        }
        if (pasirinkimas2== '2' ){
            cout<<"ar naudoti kursiokai.txt, ar atsitiktinai sugeneruota faila? Jei kursiokai spauskite 1, jei atsitiktinai 2. ";
            do{
                cin >> pasirinkimas2;
                if (pasirinkimas2 != '1' && pasirinkimas2 != '2') cout << "Neteisinga įvestis, įveskite 1 arba 2.";
            }while(pasirinkimas2 != '1' && pasirinkimas2 != '2');
            
            if(pasirinkimas2== '1' ){
                ifstream fd("kursiokai.txt");
                isfailo(fd, n);
                pabaiga(n);}
               if(pasirinkimas2== '2' ){
                for(int i=1000; i<11000000; i=i*10){
                    sum=0;
                    n=0;
                    ifstream fd("studentai_" + std::to_string(i) + ".txt");
                    isfailo(fd, n);
                    pabaiga(n);
                    ifstream fl("laikai.txt");
                    double b;
                    for(int i=0; i<4; i++){
                        fl>>b;
                        sum=b+sum;
                    }
                    cout<<"Visas laikas - "<<sum<<endl<<endl;
                }
            }
               }
               }
               
               else{
                iskonsoles (n);
                pabaiga(n);
            }
               return 0;
               }
