#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <list>
#include <chrono>
#include <stdint.h>
#include "studentai.h"
#include "sukeist_v.h"
const std::size_t n=20;
typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::milliseconds TimeType;
using std::cout;





bool compare (studentai const & a, studentai const & b)
{
    if (a.pav<b.pav)
        return true;
    else return false;
}


int main()

{
    char b;
    const std::size_t R = 100000;
std::chrono::high_resolution_clock::time_point t1;
std::chrono::high_resolution_clock::time_point t2;

t1=Clock::now();
std::list<studentai> G;
std::list<studentai> G2;
std::size_t temp=R;
std::ifstream gf ("5.txt");
gf.get(b);
    while(b!='\n')
    {
        gf.get(b);
    }
    std::size_t g=0;
for(std::size_t i=1;i<=temp;i++)
{
    G.resize(i);
    gf.get(b);
    while (b!='\t')
    {
        G.back().var.push_back(b);
        gf.get(b);
    }
    while(b=='\t')
    {
        gf.get(b);
    }
    while (b!='\t')
    {
        G.back().pav.push_back(b);
        gf.get(b);
    }
    G.back().paz.reserve(n);
    G.back().paz.resize(n);
    for(std::size_t j=0;j<n;j++)
    {
        gf>>G.back().paz[j];
    }
    for(std::size_t o=0; o<n-1; o++)        //isrikiuoju nuo did iki maz
            {
                if(G.back().paz[o]<G.back().paz[o+1])
                {
                    G.back().paz[o]=G.back().paz[o]+G.back().paz[o+1];
                    G.back().paz[o+1]=G.back().paz[o]-G.back().paz[o+1];
                    G.back().paz[o]=G.back().paz[o]-G.back().paz[o+1];
                    o=SIZE_MAX;
                }
            }
    gf>>G.back().egz>>G.back().vidtotal;
    gf.get(b);
    G.back().vidnd=0;
    for(std::size_t o=0;o<n;o++)
    {G.back().vidnd=G.back().vidnd+G.back().paz[o];}
    G.back().vidnd=G.back().vidnd/n;
    if(n%2==0)
    {
        G.back().mednd=(G.back().paz[n/2-1]+G.back().paz[n/2])/2;
    }
    else
        {
            G.back().mednd=G.back().paz[n/2];
        }
    G.back().medtotal=G.back().mednd*0.4+G.back().egz*0.6;
    if((G.back().mednd<6) || (G.back().vidnd<6))
    {
        g++;
        G2.resize(g);
        G2.back()=G.back();
        G.back().var.clear();
        G.back().pav.clear();
        i--;
        temp--;
    }

}

    gf.close();
    G.resize(temp);
    G.sort(compare);
    G2.sort(compare);
    std::list<studentai>::iterator it;
    if(temp>0)
    {
        cout<<"The Kool Kidz:\nVardas\t\tpavarde\t\tGal.(vidurkis)\tGal.(mediana)\n";

    for(std::size_t i=0;i<temp;i++)
    {
        it = std::next(G.begin(), i);
        cout<<it->var;
        if ((it->var).length()>7)
        {
            cout<<"\t";
        }
        else cout<<"\t\t";
        cout<<it->pav;
        if ((it->pav).length()>7)
        {
            cout<<"\t";
        }
        else cout<<"\t\t";
        cout<<it->vidtotal<<"\t\t"<<it->medtotal<<"\n";
    }}
    if(g>0)
    {
        cout<<"da stoopid loosers:\nVardas\t\tpavarde\t\tnd(vidurkis)\tnd(mediana)\n";

    for(std::size_t i=0;i<g;i++)
    {
        it = std::next(G2.begin(), i);
        cout<<it->var;
        if ((it->var).length()>7)
        {
            cout<<"\t";
        }
        else cout<<"\t\t";
        cout<<it->pav;
        if ((it->pav).length()>7)
        {
            cout<<"\t";
        }
        else cout<<"\t\t";
        cout<<it->vidnd<<"\t\t"<<it->mednd<<"\n";
    }}

t2=Clock::now();
cout<<(std::chrono::duration_cast<TimeType>(t2 - t1)).count()<<"\n\n";
    return 0;
}
