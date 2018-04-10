#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <list>
#include <chrono>
#include <algorithm>
#include "studentai.h"
const std::size_t n=20;
typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::milliseconds TimeType;
using std::cout;



bool compare (studentai const & a, studentai const & b)
{
    if (a.pav<b.pav)
        return true;
    else
        return false;
}


int main()

{
    char b;
    const std::size_t R = 100000;
    std::chrono::high_resolution_clock::time_point t1;
    std::chrono::high_resolution_clock::time_point t2;

    t1=Clock::now();
    std::list<studentai> G;
    std::list<studentai> G1;
    std::list<studentai> G2;
    std::ifstream gf ("5.txt");
    gf.get(b);
    while(b!='\n')
    {
        gf.get(b);
    }
    for(std::size_t i=1; i<=R; i++)
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
        for(std::size_t j=0; j<n; j++)
        {
            gf>>G.back().paz[j];
        }
        std::sort(G.back().paz.begin(),G.back().paz.end());
        gf>>G.back().egz>>G.back().vidtotal;
        gf.get(b);
        G.back().vidnd=0;
        for(std::size_t o=0; o<n; o++)
        {
            G.back().vidnd=G.back().vidnd+G.back().paz[o];
        }
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
    }

    gf.close();


    std::size_t g=0;
    std::size_t d=0;

    std::list<studentai>::iterator it;

    for(std::size_t i=0; i<R; i++)
    {
        it = std::next(G.begin(), i);

        if((it->mednd<6) || (it->vidnd<6))
        {
            d++;
            G2.resize(d);
            G2.back().var=it->var;
            G2.back().pav=it->pav;
            G2.back().mednd=it->mednd;
            G2.back().vidnd=it->vidnd;

        }
        else
        {
            g++;
            G1.resize(g);
            G1.back().var=it->var;
            G1.back().pav=it->pav;
            G1.back().medtotal=it->medtotal;
            G1.back().vidtotal=it->vidtotal;

        }
    }



    G1.sort(compare);
    G2.sort(compare);

    if(g>0)
    {
        cout<<"The Kool Kidz:\nVardas\t\tpavarde\t\tGal.(vidurkis)\tGal.(mediana)\n";

        for(std::size_t i=0; i<g; i++)
        {
            it = std::next(G1.begin(), i);
            cout<<it->var;
            if ((it->var).length()>7)
            {
                cout<<"\t";
            }
            else
                cout<<"\t\t";
            cout<<it->pav;
            if ((it->pav).length()>7)
            {
                cout<<"\t";
            }
            else
                cout<<"\t\t";
            cout<<it->vidtotal<<"\t\t"<<it->medtotal<<"\n";
        }
    }
    if(d>0)
    {
        cout<<"da stoopid loosers:\nVardas\t\tpavarde\t\tnd(vidurkis)\tnd(mediana)\n";

        for(std::size_t i=0; i<d; i++)
        {
            it = std::next(G2.begin(), i);
            cout<<it->var;
            if ((it->var).length()>7)
            {
                cout<<"\t";
            }
            else
                cout<<"\t\t";
            cout<<it->pav;
            if ((it->pav).length()>7)
            {
                cout<<"\t";
            }
            else
                cout<<"\t\t";
            cout<<it->vidnd<<"\t\t"<<it->mednd<<"\n";
        }
    }

    t2=Clock::now();
    cout<<(std::chrono::duration_cast<TimeType>(t2 - t1)).count()<<"\n\n";
    return 0;
}