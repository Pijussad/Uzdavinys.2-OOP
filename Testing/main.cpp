#define CATCH_CONFIG_MAIN

#include <iostream>
#include "../mylib.h"
#include "catch_amalgamated.hpp"




TEST_CASE("Studento konstruktorius"){
    vector<int> paz{1,2,3};
    Studentas studentas("vardas1", "pavarde1", paz, 9);
    CHECK(studentas.vardas() == "vardas1");
    REQUIRE(studentas.pavarde() == "pavarde1");
    REQUIRE(studentas.egz() == 9);
}

TEST_CASE("Studento move priskyrimo operatorius"){
    vector<int> paz{1,2,3};
    Studentas s1("Vardas","Pavarde",paz,4);
    Studentas s5;
    s5 = std::move(s1);
    REQUIRE(s5.vardas() == "Vardas");
    REQUIRE(s5.pavarde() == "Pavarde");
    REQUIRE(s5.egz() == 4);

}
TEST_CASE("Studento copy testavimas") {
    vector<int> paz {1, 2, 3};
    Studentas s1("Vardas", "Pavarde", paz, 4);
    Studentas s5;
    s5 = s1;
    REQUIRE(s5.vardas() == "Vardas");
    REQUIRE(s5.pavarde() == "Pavarde");
    REQUIRE(s5.egz() == 4);
}
