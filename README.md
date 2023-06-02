### Mokinio pažymių skaičiuoklė
Kodas skirtas įvesti studentų duomenis, bei skaičiuoti galutinius balus naudojant vidurkį arba medianą. 
Galutinis balas skaičiuojamas pagal formulę `(0.4 * namų darbų vidurkis + 0.6 * egzamino pažymys)`.

Ši programa leidžia vartotojams įvesti mokinių duomenis ir apskaičiuoti galutinius pažymius naudojant vidurkį arba medianą. Pažymių ir mokinių skaičius neribojamas, o programa palaiko du pažymių saugojimo būdus: C masyvus ir std::vector.

### 0.1 versija
Funkcijos:
•	Įvesti mokinio vardą ir pavardę
•	Įvesti mokinio namų darbus ir egzamino pažymius
•	Pažymių ir studentų skaičius yra neribotas. Tai pasiekiama naudojant masyvus, `new`, `delete` metodą.
•	Apskaičiuokite galutinį balą naudodami vidurkio formulę (0,4 * vidutinis namų darbų įvertinimas + 0,6 * egzamino pažymys)
•	Rodyti galutinius balus ekrane

### 0.2 versija
Funkcijos:
•	Leisti nuskaityti duomenis iš failo (kursiokai.txt)
•	Išvestyje rūšiuokite mokinius pagal vardą (pirmą arba paskutinį).

### 0.3 versija
Funkcijos:
•	Kur reikia naudojamos struktūros
•	Perkeltos funkcijos ir duomenų tipai į atskirus antraščių failus (*.h)
•	Klaidų atvejais naudojamas išimčių tvarkymas

### 0.4 versija
Funkcijos:
•	Sukurtas failų generatorius, kad generuotų atsitiktinius studentų sąrašo failus
•	Generuoti skirtingų įrašų dydžių failus: 1000; 10 000; 100 000; 1 000 000; 10 000 000
•	Suskirsto mokinius į dvi kategorijas pagal galutinį balą: „vargšiukus“ (balas < 5,0) ir „šaunuolius“ (balas >= 5,0)
•	Duomenys išvedami suskirsčius mokinius į du naujus failus
•	Atlikta įvairių programos žingsnių greičio analizė

### 0.5 versija
Konteinerių testavimas
Išmatuotas programos našumas naudojant tris skirtingus konteinerių tipus:
•	std::vektorius
•	std::sąrašas
•	std::deque
Programa buvo išandyta su failais, kuriuose yra 1000; 10 000; 100 000; 1 000 000; ir 10 000 000 įrašų.
![Gauti duomenys](https://github.com/Pijussad/1-uzdavinys/blob/V0.5/Programavimo%20uzduotis/Screenshot%202023-04-06%20at%2016.31.36.png?raw=true)
Duomenys rodo, kiek laiko reikia trims skirtingoms duomenų struktūroms ("vektoriams", "sąrašams" ir "Deque") atlikti tris operacijas ("skaitymą", "rikiavimą" ir "rūšiavimą + išvedimą") su įvairaus dydžio įvesties duomenimis (1000, 10000, 100000, 1000000 ir 1000000 elementų). Testavimas buvo atliktas naudojant Macbook Air 2021 procesorius M1, atminties - 256gb, operatyviosios atminties - 8gb.

Remdamiesi duomenimis, galime padaryti šiuos pastebėjimus:

Skaitymo laikas: Skaitymo laikas visose duomenų struktūrose yra gana panašus ir, didėjant įvesties dydžiui, reikšmingai nedidėja.

Rūšiavimo laikas: Vektoriaus ir sąrašo rūšiavimo laikas yra gerokai trumpesnis nei Deque, o vektoriaus rūšiavimo laikas yra mažiausias.

Rūšiavimo ir išvedimo laikas: Ir vėl Vektoriaus ir Sąrašo laikas panašus, o Deque šios operacijos laikas šiek tiek trumpesnis.

Bendras laikas: Vektoriaus bendras laikas yra mažiausias visų įvesties dydžių atveju, o Deque bendras laikas yra didžiausias. Sąrašo bendras laikas yra gana panašus į vektoriaus, tik šiek tiek padidėja, kai įvesties dydžiai yra didesni.

Apibendrinant galima teigti, kad, remiantis pateiktais duomenimis, efektyviausia duomenų struktūra šioms operacijoms atlikti yra Vektoriai, po jos eina Sąrašai, o  Deque yra mažiausiai efektyvi struktūra. Tačiau verta pažymėti, kad šie rezultatai gali skirtis, kai atliekamos skirtingo tipo operacijos ir duomenų dydžiai.

Duomenys:
Vectors:

1000 elementų nuskaitymas užtruko: 0.00995642 s
1000 elementų rikiavimas uztruko: 0.00486162 s
1000 elementų rūšiavimas ir išvedimas užtruko: 0.0541491 s
Visas laikas - 0.0852501


10000 elementų nuskaitymas užtruko: 0.0394166 s
10000 elementų rikiavimas uztruko: 0.0506257 s
10000 elementų rūšiavimas ir išvedimas užtruko: 0.238057 s
Visas laikas - 0.385391


100000 elementų nuskaitymas užtruko: 0.389174 s
100000 elementų rikiavimas uztruko: 0.287582 s
100000 elementų rūšiavimas ir išvedimas užtruko: 2.32627 s
Visas laikas - 3.41165


1000000 elementų nuskaitymas užtruko: 4.13663 s
1000000 elementų rikiavimas uztruko: 2.96931 s
1000000 elementų rūšiavimas ir išvedimas užtruko: 25.7986 s
Visas laikas - 36.6666


10000000 elementų nuskaitymas užtruko: 41.4517 s
10000000 elementų rikiavimas uztruko: 34.768 s
10000000 elementų rūšiavimas ir išvedimas užtruko: 284.378 s
Visas laikas - 397.494



Lists:

1000 elementų nuskaitymas užtruko: 0.009739 s
1000 elementų rikiavimas uztruko: 0.00159208 s
1000 elementų rūšiavimas ir išvedimas užtruko: 0.0547159 s
Visas laikas - 0.0810231


10000 elementų nuskaitymas užtruko: 0.0389912 s
10000 elementų rikiavimas uztruko: 0.0213869 s
10000 elementų rūšiavimas ir išvedimas užtruko: 0.321853 s
Visas laikas - 0.429954


100000 elementų nuskaitymas užtruko: 0.38193 s
100000 elementų rikiavimas uztruko: 0.110093 s
100000 elementų rūšiavimas ir išvedimas užtruko: 3.06035 s
Visas laikas - 3.95126


1000000 elementų nuskaitymas užtruko: 3.84435 s
1000000 elementų rikiavimas uztruko: 0.867738 s
1000000 elementų rūšiavimas ir išvedimas užtruko: 30.5971 s
Visas laikas - 38.9686


10000000 elementų nuskaitymas užtruko: 39.4182 s
10000000 elementų rikiavimas uztruko: 9.62479 s
10000000 elementų rūšiavimas ir išvedimas užtruko: 371.635 s
Visas laikas - 458.3



Deque:

1000 elementų nuskaitymas užtruko: 0.00973883 s
1000 elementų rikiavimas uztruko: 0.0153382 s
1000 elementų rūšiavimas ir išvedimas užtruko: 0.046655 s
Visas laikas - 0.087133


10000 elementų nuskaitymas užtruko: 0.037029 s
10000 elementų rikiavimas uztruko: 0.0879386 s
10000 elementų rūšiavimas ir išvedimas užtruko: 0.252539 s
Visas laikas - 0.423342


100000 elementų nuskaitymas užtruko: 0.387741 s
100000 elementų rikiavimas uztruko: 0.626811 s
100000 elementų rūšiavimas ir išvedimas užtruko: 2.5014 s
Visas laikas - 3.90218


1000000 elementų nuskaitymas užtruko: 4.52041 s
1000000 elementų rikiavimas uztruko: 9.18467 s
1000000 elementų rūšiavimas ir išvedimas užtruko: 26.7792 s
Visas laikas - 44.2913

### 1.0 versija
Optimizavimas
Remiantis skirtingomis strategijomis, optimizuotas mokinių rūšiavimas ir padalijimas į dvi kategorijas („vargšiukus“ ir „šaunuolius“):
•	1 strategija: bendro mokinio konteinerio padalijimas į du naujus to paties tipo konteinerius
•	2 strategija: bendro mokinio konteinerio padalijimas naudojant tik vieną naują konteinerį
Išmatuotas programos našumas naudojant skirtingus konteinerių tipus (vektorių, sąrašą ir deque) ir palyginti rezultatai. Taip pat buvo pritaikyti tinkami algoritmai, kad būtų paspartintas studentų dalinimo procedūrą vektoriniame konteineryje.

Gauti greičių rezultatai:
V1.0.Vector be vektoriaus saunuoliai optimizuotas:
1000 elementų nuskaitymas užtruko: 0.016776 s
1000 elementų rikiavimas uztruko: 0.0059305 s
1000 elementų rūšiavimas užtruko: 0.00261258 s
Visas laikas - 0.0279317

10000 elementų nuskaitymas užtruko: 0.0667338 s
10000 elementų rikiavimas uztruko: 0.0390531 s
10000 elementų rūšiavimas užtruko: 0.011127 s
Visas laikas - 0.128041

100000 elementų nuskaitymas užtruko: 0.417466 s
100000 elementų rikiavimas uztruko: 0.208669 s
100000 elementų rūšiavimas užtruko: 0.0557232 s
Visas laikas - 0.737581



V1.0.Vector be vektoriaus saunuoliai:
1000 elementų nuskaitymas užtruko: 0.0164362 s
1000 elementų rikiavimas uztruko: 0.00562658 s
1000 elementų rūšiavimas užtruko: 0.0287362 s
Visas laikas - 0.0795352

10000 elementų nuskaitymas užtruko: 0.0576796 s
10000 elementų rikiavimas uztruko: 0.0377286 s
10000 elementų rūšiavimas užtruko: 1.20466 s
Visas laikas - 2.50473

100000 elementų nuskaitymas užtruko: 0.419422 s
100000 elementų rikiavimas uztruko: 0.213035 s
100000 elementų rūšiavimas užtruko: 117.502 s
Visas laikas - 235.636


V1.0.Vector
1000 elementų nuskaitymas užtruko: 0.0170906 s
1000 elementų rikiavimas uztruko: 0.00499308 s
1000 elementų rūšiavimas užtruko: 0.00281296 s
Visas laikas - 0.0277096

10000 elementų nuskaitymas užtruko: 0.0685214 s
10000 elementų rikiavimas uztruko: 0.0407972 s
10000 elementų rūšiavimas užtruko: 0.0118498 s
Visas laikas - 0.133018

100000 elementų nuskaitymas užtruko: 0.416091 s
100000 elementų rikiavimas uztruko: 0.22216 s
100000 elementų rūšiavimas užtruko: 0.0597769 s
Visas laikas - 0.757805


V1.0.List be vektoriaus saunuoliai:

1000 elementų nuskaitymas užtruko: 0.0149624 s
1000 elementų rikiavimas uztruko: 0.00222442 s
1000 elementų rūšiavimas užtruko: 0.00680925 s
Visas laikas - 0.0308053

10000 elementų nuskaitymas užtruko: 0.0681469 s
10000 elementų rikiavimas uztruko: 0.018267 s
10000 elementų rūšiavimas užtruko: 0.0368562 s
Visas laikas - 0.160126

100000 elementų nuskaitymas užtruko: 0.417779 s
100000 elementų rikiavimas uztruko: 0.103651 s
100000 elementų rūšiavimas užtruko: 0.179618 s
Visas laikas - 0.880666


V1.0.List:
1000 elementų nuskaitymas užtruko: 0.017573 s
1000 elementų rikiavimas uztruko: 0.00246679 s
1000 elementų rūšiavimas užtruko: 0.00716992 s
Visas laikas - 0.0343796

10000 elementų nuskaitymas užtruko: 0.0643827 s
10000 elementų rikiavimas uztruko: 0.0188411 s
10000 elementų rūšiavimas užtruko: 0.0390057 s
Visas laikas - 0.161235

100000 elementų nuskaitymas užtruko: 0.417796 s
100000 elementų rikiavimas uztruko: 0.106296 s
100000 elementų rūšiavimas užtruko: 0.193469 s
Visas laikas - 0.91103

V1.0.Deque be vektoriaus saunuoliai:
1000 elementų nuskaitymas užtruko: 0.0153742 s
1000 elementų rikiavimas uztruko: 0.00679471 s
1000 elementų rūšiavimas užtruko: 0.028565 s
Visas laikas - 0.0792989

10000 elementų nuskaitymas užtruko: 0.0468038 s
10000 elementų rikiavimas uztruko: 0.0494158 s
10000 elementų rūšiavimas užtruko: 1.09471 s
Visas laikas - 2.28564

100000 elementų nuskaitymas užtruko: 0.36504 s
100000 elementų rikiavimas uztruko: 0.290231 s
100000 elementų rūšiavimas užtruko: 106.608 s
Visas laikas - 213.871



V1.0.Deque:
1000 elementų nuskaitymas užtruko: 0.0146567 s
1000 elementų rikiavimas uztruko: 0.00710683 s
1000 elementų rūšiavimas užtruko: 0.00536538 s
Visas laikas - 0.0324943

10000 elementų nuskaitymas užtruko: 0.0560537 s
10000 elementų rikiavimas uztruko: 0.053945 s
10000 elementų rūšiavimas užtruko: 0.0231325 s
Visas laikas - 0.156264

100000 elementų nuskaitymas užtruko: 0.344874 s
100000 elementų rikiavimas uztruko: 0.320503 s
100000 elementų rūšiavimas užtruko: 0.168886 s
Visas laikas - 1.00315

Apibendrinimas:
Remdamiesi pateiktais duomenimis, galime padaryti šias išvadas:

"V1.0.Vector be vektoriaus "Šaunuoliai" optimizuotas" įgyvendinimas nuosekliai lenkia kitus įgyvendinimus pagal nuskaitymo, rūšiavimo ir bendrą laiką visų bandytų įvesties dydžių (1000, 10000 ir 100000 elementų) atveju. Jos laiko matavimai nuosekliai yra mažiausi tarp visų įgyvendinimų.

"VV1.0.Vector" įgyvendinimas veikia panašiai kaip "V1.0.List" įgyvendinimas. Abiejų jų nuskaitymo, rūšiavimo ir bendro laiko matavimai yra panašūs skirtingiems įvesties dydžiams. Tačiau "V1.0..List" įgyvendinimo rūšiavimo laikas šiek tiek ilgesnis, kai įvesties dydis yra didesnis.

"V1.0.Deque be vektoriaus 'Šaunuoliai'" ir "V1.0.Deque" realizacijų nuskaitymo, rūšiavimo ir bendro laiko matavimai, palyginti su "V1.0.Vector" ir "V1.0.List" realizacijomis, apskritai yra didesni. Rūšiavimo laikas ypač didesnis "V0.5.Deque" įgyvendinimuose, ypač didesnių įvesties dydžių atveju.

Įgyvendinimas be vektoriaus "Šaunuoliai" optimizavimo nuosekliai rodo didesnius rūšiavimo laikus, palyginti su optimizuotais įgyvendinimais, visose duomenų struktūrose (Vector, List ir Deque). Tai rodo, kad vektoriaus "Šaunuoliai" optimizavimas suteikia našumo naudos rūšiavimo operacijų atžvilgiu.

Nuskaitymo laikai visose realizacijose išlieka gana pastovūs esant skirtingiems įvesties dydžiams, o tai rodo, kad pačiai skenavimo operacijai duomenų struktūros pasirinkimas didelės įtakos neturi.

Apskritai geriausiai iš testuotų realizacijų veikia realizacija "V1.0.Vector be vektoriaus "Šaunuoliai" optimizavimo", po jos seka realizacijos "V1.0.Vector" ir "V1.0.List" "V1.0.Deque" ir realizacijos "be vektoriaus 'Šaunuoliai'" realizacijos pasižymi lėtesniu našumu, palyginti su jomis.

### 1.1 versija

Funkcijos
Pertvarkyta programa, kad mokinių duomenų saugojimui būtų naudojama klasė, o ne struktūra
Įgyvendinti klasę Studentas su atitinkamomis nario funkcijomis ir duomenų nariais
Atnaujinkite esamas funkcijas, kad jos veiktų su klase Studentas
Palyginkite programos našumą, kai ji įgyvendinama naudojant struktūrą ir klasę.
Atlikite eksperimentinę analizę su optimizavimo žymėmis (O1, O2, O3) ir užrašykite rezultatus.

Palyginimas programos su klasėm ir be klasių:
Apskaičiuokime kiekvieno duomenų taško vidutinį greičio skirtumą procentais:

1000 elementų:
Vektoriaus: 0,0278695 sekundės
Vektoriaus klasė: 0,0323071 sekundės
Greičio skirtumas: (0,0323071 - 0,0278695) / 0,0278695 * 100 = 16,02 %.

10 000 elementų:
Vektoriaus: 0,129048 sekundės
Vektoriaus klasė: 0,134685 sekundės
Greičio skirtumas: (0,134685 - 0,129048) / 0,129048 * 100 = 4,36 %.

100 000 elementų:
Vektoriaus: 0,737888 sekundės
Vektoriaus klasė: 0,788943 sekundės
Greičio skirtumas: (0,788943 - 0,737888) / 0,737888 * 100 = 6,92 %.

1 000 000 elementų:
Vektoriaus: 7,41399 sekundės
Vektoriaus klasė: 8,009 sekundės
Greičio skirtumas: (8,009 - 7,41399) / 7,41399 * 100 = 8,02 %.

10 000 000 000 elementų:
Vektoriaus: 79,9436 sekundės
Vektoriaus klasė: 85,8619 sekundės
Greičio skirtumas: (85,8619 - 79,9436) / 79,9436 * 100 = 7,40 %.

Dabar apskaičiuokime vidutinį greičio skirtumą procentais, imdami pirmiau nurodytų procentų vidurkį:

(16.02% + 4.36% + 6.92% + 8.02% + 7.40%) / 5 = 8.34%

Vidutiniškai Vektoriaus įgyvendinimas yra maždaug 8,34 % greitesnis už Vektoriaus klasės įgyvendinimą.


O1, O2, O3 palyginimas:

Dėl O1:
1000 elementų nuskaitymas iš viso užtruko 0,0123941 s.
10000 elementų nuskaitymas iš viso truko 0,0492116 s.
100000 elementų nuskaitymas iš viso truko 0,260296 s.
1000000 elementų nuskaitymas iš viso truko 2,27239 s.
Iš viso nuskaityti 10000000 elementų užtruko 23,831 s.
O2:

1000 elementų nuskaitymas iš viso truko 0,0105194 s.
10000 elementų nuskaitymas iš viso truko 0,0503393 s.
100000 elementų nuskaitymas iš viso truko 0,251007 s.
1000000 elementų nuskaitymas iš viso truko 2,23276 s.
10000000 elementų nuskaitymas iš viso truko 24,5592 s.
O3:

1000 elementų nuskaitymas iš viso truko 0,0116707 s.
10000 elementų nuskaitymas iš viso truko 0,0495248 s.
100000 elementų nuskaitymas iš viso truko 0,254567 s.
1000000 elementų nuskaitymas iš viso truko 2,24893 s.
10000000 elementų nuskaitymas iš viso truko 23,9312 s.
Remdamiesi šiais rezultatais, galime daryti tokią išvadą:
Bendras našumas: O1 nuolat lenkia O2 ir O3 pagal bendrą laiką, reikalingą elementams nuskaityti. O2 ir O3 našumo charakteristikos panašios.
Verta paminėti, kad visos trys operacijos susijusios su elementų rūšiavimu. Palyginti su O2 ir O3, O1 rūšiavimas nuolat užima daugiau laiko. Tai rodo, kad O1 rūšiavimo algoritmas gali būti mažiau efektyvus nei O2 ir O3 naudojami algoritmai.


1.2 versija

Funkcijos:
Įdiegti būtini operatoriai klasėje Studentas, kad pagerėtų programos našumas ir patogumas
Įdiegti tinkamus operatorius, atsižvelgiant į būsimų klasės Studentas naudotojų reikalavimus ir poreikius.
Užtikrinkite, kad būtų tinkamai įgyvendinta penkių taisyklių taisyklė, įskaitant kopijavimo konstruktorių, perkėlimo konstruktorių, kopijavimo priskyrimo operatorių, perkėlimo priskyrimo operatorių ir destruktorių

### 1.5 versija

Funkcijos
Sukurta bazinė klasė Žmogus, skirta apibūdinti žmogų apskritai
Klasė Human tapo abstrakčia klase (negalima kurti tipo Human objektų, tik išvestinius objektus)
Sukurta išvestinė klasė Student iš klasės Human, skirta studentui apibūdinti
Įdiegtos būtinos klasės Student narių funkcijos ir duomenų nariai

### 2.0 versija

Dokumentacija ir bandymai
Naudojant "Doxygen 1.5" sukurta dokumentacija, skirta projektui ir jo sudedamosioms dalims aprašyti.
Įkelta dokumentacija (kaip atskiras "doxygen" katalogas) į saugyklą
Įgyvendinti vienetų testai naudojant pageidaujamą C++ vienetų testavimo sistemą, kad būtų patikrintas programos funkcijų teisingumas
Sukurtas automatinis diegimo failas studentai.pkg
Sutvarkė saugyklą taip, kad joje būtų tik reikalingi šaltinio failai, pašalino visus su IDE susijusius failus
Įtraukė README.md failą, kuriame būtų aprašytos visos versijos, perdavimai ir rezultatų komentarai
Parengė instrukcijų vadovą, kuriame pateikti pagrindiniai README.md faile aprašyti veiksmai
Į README.md failą įtrauktos diegimo instrukcijos


Failų paaiškinimas:
•	`mylib.h`: antraštės failas, kuriame yra funkcijų deklaracijos ir duomenų struktūros
•	`makefile`: paleidimo failas
•	`mylib.cpp`: šaltinio failas su programos įgyvendinimu
•	`kursiokai.txt`: Duomenų failo pavyzdys
•	`README.md`: Readme failas, kuriame yra informacija apie programą ir jos versijas

Naudojimas:
1.	Sukompiliuokite programą naudodami pageidaujamą kompiliatorių.
2.	Paleiskite sukompiliuotą vykdomąjį failą.
3.	Vykdykite instrukcijas, kad įvestumėte mokinio duomenis arba skaitytumėte duomenis iš failo.
4.	Programa apskaičiuos galutinius pažymius ir parodys juos ekrane.
Testavimas
Programa buvo išbandyta naudojant įvairius įrašų dydžius ir konteinerių tipus, kad būtų užtikrintas jos veikimas ir funkcionalumas. Testavimo parametrai apima procesoriaus, RAM ir HDD specifikacijas.


Diegimas nuo:
Norėdami įdiegti ir paleisti programą, atlikite šiuos veiksmus:
1.	Atsisiųskite failą `studentai.pkg'.
2.	Failą atidarius turėtų pasirodyti instaliacijos langas, toliau sekite nurodomų komandų.


