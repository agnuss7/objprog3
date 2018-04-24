#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

class studentai

{

	private:
    std::string var;

    std::string pav;

    std::vector<std::size_t> paz;

    std::size_t egz;

    float vidnd;

    float mednd;

    float vidtotal;

    float medtotal;
public:
studentai() :egz(0) {}
studentai(std::istream &in);
studentai(std::string name, std::string sname, std::size_t e, std::vector<std::size_t> p); //cia kai irasinet ranka reikes
~studentai() {};
bool operator<(const studentai &x);
void read(std::istream& in);
void mediana();
void vidurkis();
const float getVid();
const float getMed();
const std::string getPav();
void print(bool a);
};
bool compare(studentai  e,  studentai  b);
void cont2v (std::string p, const std::size_t N);
void cont3v(std::string p, const std::size_t N);
void cont2d(std::string p, const std::size_t N);
void cont3d(std::string p, const std::size_t N);
void cont2l(std::string p, const std::size_t N);
void cont3l(std::string p, const std::size_t N);