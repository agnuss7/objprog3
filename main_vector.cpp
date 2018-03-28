#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <chrono>
#include<stdint.h>
#include "studentai.h"
#include "sukeist_v.h"
const std::size_t n=20;
typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::milliseconds TimeType;
using std::cout;



int main()

{
    char b;
    std::vector<studentai> A;
    std::ifstream df("2.txt");

    const std::size_t R = 100;
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
    for(std::size_t i=0;i<R-1;i++)  //rusiuojam pagal pavardes
    {
        if(A[i].pav>A[i+1].pav)
        {
            sukeist(A[i],A[i+1]);
            i=SIZE_MAX;
        }
    }









    for(std::size_t i=0; i<R; i++) //suskaiciuoja nd vidurkius/medianas
        {
            A[i].vidnd=0;
            for(std::size_t o=0; o<n; o++)
            {
                A[i].vidnd=A[i].vidnd+A[i].paz[o];
            }
            A[i].vidnd=A[i].vidnd/n;
            for(std::size_t o=0; o<n-1; o++)        //isrikiuoju nuo did iki maz
            {
                if(A[i].paz[o]<A[i].paz[o+1])
                {
                    A[i].paz[o]=A[i].paz[o]+A[i].paz[o+1];
                    A[i].paz[o+1]=A[i].paz[o]-A[i].paz[o+1];
                    A[i].paz[o]=A[i].paz[o]-A[i].paz[o+1];
                    o=SIZE_MAX;
                }
            }
            if(n%2==0)
            {
                A[i].mednd=(A[i].paz[(n/2)-1]+A[i].paz[n/2])/2;
            }
            else
            {
                A[i].mednd=A[i].paz[n/2];
            }

        }
        std::size_t f=R; //f zymes kelintam elemente jau yra nelaike egzamino vaikai
        for(std::size_t i=0; i<R; i++)
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
