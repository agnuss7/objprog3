#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
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
    std::vector<studentai> A;
    std::vector<studentai> A1;
    std::vector<studentai> A2;
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
    A1.reserve(R);
    A2.reserve(R);
    A.resize(R);

    for(std::size_t i=0; i<R; i++) //nuskaitom
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
        for(std::size_t j=0; j<n; j++)
        {
            df>>A[i].paz[j];
        }
        df>>A[i].egz>>A[i].vidtotal;
        df.get(b);
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
    df.close();
    std::size_t f = 0;
    std::size_t y=0;



    for(std::size_t i=0; i<R; i++)
    {
        if (A[i].vidnd>=6 && A[i].mednd>=6)
        {
            A1.resize(y+1);
            A1[y]=A[i];
            y++;
        }
        else
        {
            A2.resize(f+1);
            A2[f]=A[i];
            f++;
        }
    }






    std::sort(A2.begin(),A2.end(),compare);
    std::sort(A1.begin(),A1.end(),compare);
//spausdinam
    cout<<"The cool kidz:\n";
    cout<<"Vardas\t\tPavarde\t\tGal. vidurkis\tGal. mediana\n";
    for(std::size_t i=0; i<y; i++)
    {
        cout<<A1[i].var;
        if (A1[i].var.size()<8)
        {
            cout<<"\t\t";
        }
        else
        {
            cout<<"\t";
        }
        cout<<A1[i].pav;
        if (A1[i].pav.size()<8)
        {
            cout<<"\t\t";
        }
        else
        {
            cout<<"\t";
        }

        A1[i].vidtotal=A1[i].vidnd*0.4+A1[i].egz*0.6;
        A1[i].medtotal=A1[i].mednd*0.4+A1[i].egz*0.6;
        std::cout<<std::setprecision(3)<<A1[i].vidtotal<<"\t\t";
        std::cout<<std::setprecision(3)<<A1[i].medtotal<<"\n";

    }
    if(f>0)
    {
        cout<<"Da stoopid loosers:\n";
        cout<<"Vardas\t\tPavarde\t\tnd vidurkis\tnd mediana\n";
        for(std::size_t i=0; i<f; i++)
        {
            cout<<A2[i].var;
            if (A2[i].var.size()<8)
            {
                cout<<"\t\t";
            }
            else
            {
                cout<<"\t";
            }
            cout<<A2[i].pav;
            if (A2[i].pav.size()<8)
            {
                cout<<"\t\t";
            }
            else
            {
                cout<<"\t";
            }

            cout<<std::setprecision(3)<<A2[i].vidnd<<"\t\t"<<A2[i].mednd<<"\n";
        }
    }
//iki cia
    cout<<"\n";
    t2=Clock::now();
    cout<<(std::chrono::duration_cast<TimeType>(t2 - t1)).count()<<"\n\n";

    return 0;
}


