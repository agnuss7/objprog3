#include "studentai.h"
#include <fstream>
#include <iostream>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <deque>
using std::cout;

studentai::studentai (std::istream &in)
{
    read(in);
}

studentai::studentai (std::string name, std::string sname, std::size_t e, std::vector<std::size_t> p)
{
    var=name;
    pav=sname;
    egz=e;
paz=p;
}

void studentai::read (std::istream& in)
{
    char s;
    float q;
    in.get(s);
    while(s!='\t')
    {
        var.push_back(s);
        in.get(s);
    }
    in.get(s);
while(s=='\t')
{
in.get(s);
}
    while(s!='\t')
    {
        pav.push_back(s);
        in.get(s);
    }
    while (s!='\n')
    {
        in>>q;
        paz.push_back(q);
        in.get(s);
    }
paz.pop_back();
    egz=paz.back();
    paz.pop_back();
}

void studentai::mediana()
{
    std::sort(paz.begin(),paz.end());
    if(paz.size()%2==0)
{
mednd=(paz[paz.size()/2]+paz[paz.size()/2-1])/2;
}
else
{
mednd=paz[paz.size()/2];
}
medtotal=mednd*0.4+egz*0.6;
}

void studentai::vidurkis()
{
    vidnd=0;
    for(std::size_t i:paz)
{
    vidnd+=i;
}
vidnd=vidnd/paz.size();
vidtotal=vidnd*0.4+egz*0.6;
}
const float studentai::getVid()
{return vidnd;}
const float studentai::getMed()
{return mednd;}
void studentai::print(bool a)
{
if(a==1)
{
cout<<var<<"\t";
if(var.length()<8){cout<<"\t";}
cout<<pav<<"\t";
if(pav.length()<8){cout<<"\t";}
cout<<vidtotal<<"\t\t"<<medtotal<<"\n";
}
if(a==0)
{
cout<<var<<"\t";
if(var.length()<8){cout<<"\t";}
cout<<pav<<"\t";
if(pav.length()<8){cout<<"\t";}
cout<<vidnd<<"\t\t"<<mednd<<"\n";
}
}

const std::string studentai::getPav ()
{
return pav;
}

bool compare( studentai & e,  studentai & b)
{
return e.getPav()<b.getPav();
}

void cont2v (std::string p, const std::size_t N)
{
     std::ifstream df(p);
    char blarg;
    while(blarg!='\n')
    {
        df.get(blarg);
    }
    std::vector<studentai> a;
    a.reserve(N);
for(std::size_t i=0;i<N;i++){
a.resize(i+1);
a[i].read(df);
}
df.close();
std::vector<studentai> a2;
a2.reserve(N);

for(std::size_t i=0;i<a.size();i++){
        a[i].mediana();
        a[i].vidurkis();
        if(a[i].getMed()<6 || a[i].getVid()<6)
        {
            a2.resize(a2.size()+1);
            a2.back()=a[i];
            a.erase(a.begin()+i);
            i--;
        }
}
std::sort(a.begin(),a.end(),compare);
std::sort(a2.begin(),a2.end(),compare);
cout<<"The Kool Kidz\nvardas\t\tpavarde\t\tVid. gal.\tMed gal.\n";
for(std::size_t i=0;i<a.size();i++)
{
    a[i].print(1);
}
cout<<"the stoopid loosers:\nvardas\t\tpavarde\t\tVid. nd.\tMed. nd.\n";
for(std::size_t i=0;i<a2.size();i++)
{
    a2[i].print(0);
}
}
void cont3v(std::string p, const std::size_t N)
{
std::ifstream df(p);
    char blarg;
    while(blarg!='\n')
    {
        df.get(blarg);
    }
    std::vector<studentai> a;
    a.reserve(N);
for(std::size_t i=0;i<N;i++){
a.resize(i+1);
a[i].read(df);
}
df.close();
std::vector<studentai> a1;
std::vector<studentai> a2;
a1.reserve(N);
a2.reserve(N);
for(std::size_t i=0;i<N;i++){
        a[i].mediana();
        a[i].vidurkis();
        if(a[i].getMed()<6 || a[i].getVid()<6)
        {
            a2.resize(a2.size()+1);
            a2.back()=a[i];
        }
else
{
a1.resize(a1.size()+1);
            a1.back()=a[i];
}
}
std::sort(a1.begin(),a1.end(),compare);
std::sort(a2.begin(),a2.end(),compare);
cout<<"The Kool Kidz\nvardas\t\tpavarde\t\tVid. gal.\tMed gal.\n";
for(std::size_t i=0;i<a1.size();i++)
{
    a1[i].print(1);
}
cout<<"the stoopid loosers:\nvardas\t\tpavarde\t\tVid. nd.\tMed. nd.\n";
for(std::size_t i=0;i<a2.size();i++)
{
    a2[i].print(0);
}
}

void cont2d(std::string p, const std::size_t N)
{
    std::ifstream df(p);
    char blarg;
    while(blarg!='\n')
    {
        df.get(blarg);
    }
    std::deque<studentai> a;
for(std::size_t i=0;i<N;i++){
a.resize(i+1);
a[i].read(df);
}
df.close();
std::deque<studentai> a2;
for(std::size_t i=0;i<a.size();i++){
        a[i].mediana();
        a[i].vidurkis();
        if(a[i].getMed()<6 || a[i].getVid()<6)
        {
            a2.resize(a2.size()+1);
            a2.back()=a[i];
            a.erase(a.begin()+i);
            i--;
        }
}
std::sort(a.begin(),a.end(),compare);
std::sort(a2.begin(),a2.end(),compare);
cout<<"The Kool Kidz\nvardas\t\tpavarde\t\tVid. gal.\tMed gal.\n";
for(std::size_t i=0;i<a.size();i++)
{
    a[i].print(1);
}
cout<<"the stoopid loosers:\nvardas\t\tpavarde\t\tVid. nd.\tMed. nd.\n";
for(std::size_t i=0;i<a2.size();i++)
{
    a2[i].print(0);
}
}
void cont3d(std::string p, const std::size_t N)
{
std::ifstream df(p);
    char blarg;
    while(blarg!='\n')
    {
        df.get(blarg);
    }
    std::deque<studentai> a;
for(std::size_t i=0;i<N;i++){
a.resize(i+1);
a[i].read(df);
}
df.close();
std::deque<studentai> a1;
std::deque<studentai> a2;
for(std::size_t i=0;i<N;i++){
        a[i].mediana();
        a[i].vidurkis();
        if(a[i].getMed()<6 || a[i].getVid()<6)
        {
            a2.resize(a2.size()+1);
            a2.back()=a[i];
        }
else
{
a1.resize(a1.size()+1);
            a1.back()=a[i];
}
}
std::sort(a1.begin(),a1.end(),compare);
std::sort(a2.begin(),a2.end(),compare);
cout<<"The Kool Kidz\nvardas\t\tpavarde\t\tVid. gal.\tMed gal.\n";
for(std::size_t i=0;i<a1.size();i++)
{
    a1[i].print(1);
}
cout<<"the stoopid loosers:\nvardas\t\tpavarde\t\tVid. nd.\tMed. nd.\n";
for(std::size_t i=0;i<a2.size();i++)
{
    a2[i].print(0);
}
}
void cont2l(std::string p, const std::size_t N)
{
    std::ifstream df(p);
    char blarg;
std::size_t n=N;
std::size_t k=0;
    while(blarg!='\n')
    {
        df.get(blarg);
    }
    std::list<studentai> a;
std::list<studentai> a2;
    for(std::size_t i=1;i<=n;i++)
{
a.resize(i);
(a.back()).read(df);
(a.back()).mediana();
(a.back()).vidurkis();
if(a.back().getVid()<6 || a.back().getMed()<6)
{
k++;
a2.resize(k);
a2.back()=a.back();
a.pop_back();
i--;
n--;
}
}
df.close();
a.resize(n);
a.sort(compare);
a2.sort(compare);
cout<<"The Kool Kidz\nvardas\t\tpavarde\t\tVid. gal.\tMed gal.\n";
while(!a.empty())
{
    a.front().print(1);
    a.pop_front();
}
cout<<"the stoopid loosers:\nvardas\t\tpavarde\t\tVid. nd.\tMed. nd.\n";
while(!a2.empty())
{
    a2.front().print(0);
    a2.pop_front();
}

}
void cont3l(std::string p, const std::size_t N)
{
std::ifstream df(p);
    char blarg;
std::size_t k1=0;
std::size_t k2=0;
    while(blarg!='\n')
    {
        df.get(blarg);
    }
    std::list<studentai> a;
    std::list<studentai> a1;
    std::list<studentai> a2;
    for(std::size_t i=1;i<=N;i++)
{
a.resize(i);
(a.back()).read(df);
(a.back()).mediana();
(a.back()).vidurkis();
if(a.back().getVid()<6 || a.back().getMed()<6)
{
k2++;
a2.resize(k2);
a2.back()=a.back();
}
else
{
k1++;
a1.resize(k1);
a1.back()=a.back();
}
}
df.close();






a1.sort(compare);
a2.sort(compare);
cout<<"The Kool Kidz\nvardas\t\tpavarde\t\tVid. gal.\tMed gal.\n";
while(!a1.empty())
{
    a1.front().print(1);
    a1.pop_front();
}
cout<<"the stoopid loosers:\nvardas\t\tpavarde\t\tVid. nd.\tMed. nd.\n";
while(!a2.empty())
{
    a2.front().print(0);
    a2.pop_front();
}
}
