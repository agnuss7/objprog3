#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <chrono>
#include <algorithm>
#include "studentai.h"
#include "sukeist.h"
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
    std::vector<studentai> A;
    std::ifstream df("5.txt");

    const std::size_t R = 100000;
    std::chrono::high_resolution_clock::time_point t1;
    std::chrono::high_resolution_clock::time_point t2;

    df.get(b);
    while(b!='\n')
    {
        df.get(b);
    }//skaiciuok
    t1=Clock::now();
    //nuo cia
    A.reserve(R);
    A.resize(R);
    for(std::size_t i=0;i<R;i++) //nuskaitom
    {
        A[i].paz.reserve(n);
        A[i].paz.resize(n);
        df.get(b);
        while (b!='\t')
        {
        A[i].var.push_back(b);
        df.get(b);
        }
        while (b=='\t')
        {
        df.get(b);
        }
        while (b!='\t')
        {
        A[i].pav.push_back(b);
        df.get(b);
        }
        for(std::size_t j=0;j<n;j++)
        {
            df>>A[i].paz[j];
        }
        df>>A[i].egz>>A[i].vidtotal;
        df.get(b);
    }
    df.close();
    std::sort(A.begin(),A.end(),compare);
    std::size_t f = R;
    std::size_t y=0;
    for(std::size_t i=0; i<f; i++) //suskaiciuoja nd vidurkius/medianas
        {
            A[i].vidnd=0;
            for(std::size_t o=0; o<n; o++)
            {
                A[i].vidnd=A[i].vidnd+A[i].paz[o];
            }
            A[i].vidnd=A[i].vidnd/n;
            std::sort(A[i].paz.begin(),A[i].paz.end());
            if(n%2==0)
            {
                A[i].mednd=(A[i].paz[(n/2)-1]+A[i].paz[n/2])/2;
            }
            else
            {
                A[i].mednd=A[i].paz[n/2];
            }
        }
        for(std::size_t i=0; i<f; i++)
        {
            if((A[i].vidnd<6 || A[i].mednd<6) && i<f)
            {
                for(std::size_t o=i; o<R-1; o++)
                {
                    sukeist(A[o],A[o+1]);
                }
                i--;
                f--;
            }
        }
//spausdinam
cout<<"The cool kidz:\n";
        cout<<"Vardas\t\tPavarde\t\tGal. vidurkis\tGal. mediana\n";
        for(std::size_t i=0; i<f; i++)
        {
            cout<<A[i].var;
            if (A[i].var.size()<8)
            {
                cout<<"\t\t";
            }
            else
            {
                cout<<"\t";
            }
            cout<<A[i].pav;
            if (A[i].pav.size()<8)
            {
                cout<<"\t\t";
            }
            else
            {
                cout<<"\t";
            }

            A[i].vidtotal=A[i].vidnd*0.4+A[i].egz*0.6;
            A[i].medtotal=A[i].mednd*0.4+A[i].egz*0.6;
            std::cout<<std::setprecision(3)<<A[i].vidtotal<<"\t\t";
            std::cout<<std::setprecision(3)<<A[i].medtotal<<"\n";

        }
        if(f<R){
        cout<<"Da stoopid loosers:\n";
        cout<<"Vardas\t\tPavarde\t\tnd vidurkis\tnd mediana\n";
        while (f<R)
        {
            cout<<A[f].var;
            if (A[f].var.size()<8)
            {
                cout<<"\t\t";
            }
            else
            {
                cout<<"\t";
            }
            cout<<A[f].pav;
            if (A[f].pav.size()<8)
            {
                cout<<"\t\t";
            }
            else
            {
                cout<<"\t";
            }

            cout<<std::setprecision(3)<<A[f].vidnd<<"\t\t"<<A[f].mednd<<"\n";
            f++;
        }}
//iki cia
cout<<"\n";
t2=Clock::now();
cout<<(std::chrono::duration_cast<TimeType>(t2 - t1)).count()<<"\n\n";

    return 0;
}