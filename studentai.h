#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

class zmogus {
protected:
    std::string var;
    std::string pav;
public:
    virtual inline std::string getPav() const=0;
    virtual void names(const std::string vv,const std::string pp)=0;
    virtual ~zmogus(){};

};

class studentai: public zmogus

{

	private:

    std::vector<std::size_t> paz;

    std::size_t egz;

    float vidnd;

    float mednd;

    float vidtotal;

    float medtotal;
public:
///cia default konstruktorius
studentai() :egz(0) {}
void names(const std::string vv,const std::string pp);
studentai(std::istream &in);
void add (const std::string & name,const std::string & sname, std::size_t & e, std::vector<std::size_t> & p);
~studentai() {};
std::istream& read(std::istream& in);
void mediana();
void vidurkis();
float getVid() const;
float getMed() const;
float getGalM() const;
float getGalV() const;
inline std::string getPav() const;
void print(bool a);
friend std::ostream& operator<<(std::ostream& out, const studentai& f);
};
bool negavoSkolos (const studentai & e);
bool compare(const studentai & e, const studentai & b);
void cont2v (std::string p, const std::size_t N);
void cont3v(std::string p, const std::size_t N);
void cont2d(std::string p, const std::size_t N);
void cont3d(std::string p, const std::size_t N);
void cont2l(std::string p, const std::size_t N);
void cont3l(std::string p, const std::size_t N);
