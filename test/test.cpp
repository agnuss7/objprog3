#include "studentai.h"
#include "funkcijos.cpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "string"
#include "vector"


SCENARIO("studentu vidurkiai ir medianos skaiciuojami", "[studentai]")
{
    studentai a;
    GIVEN("studentu pazymiai suvedami")
    {
        std::vector<std::size_t> p{1,2,3,6,6,7,10};
        std::string n="wammu";
        std::string s="wammudsxc";
        std::size_t q=9;
        a.add(s,n,q,p);
        WHEN("suskaiciuojam vidurki")
        {
            a.vidurkis();
            THEN("tikrinam, ar teisingas nd balas ir galutinis ivertis")
            {
                REQUIRE(a.getVid()==5);
                REQUIRE(a.getGalV()==7.4f);
            }
        }
        WHEN("skaiciuojam mediana")
        {
            a.mediana();
            THEN("tikrinam, ar teisingas nd balas ir galutinis ivertis")
            {
                REQUIRE(a.getMed()==6);
                REQUIRE(a.getGalM()==7.8f);
            }
        }
    }
}
