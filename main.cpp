#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <iomanip>
#include <chrono>
#include "studentai.h"
#include "sukeist_v.h"
const std::size_t n=20;
typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::nanoseconds TimeType;
using std::cout;
int main()

{
    char b;
    std::vector<studentai> A;
    cout<<"skaiciuojam 10000 studentu vectoryje laika\n\n";
    std::ifstream df("2.txt");
    df.get(b);
    while(b!='\n')
    {
        df.get(b);
    }
    int R = 100;
    //skaiciuok
    std::chrono::high_resolution_clock::time_point t1=Clock::now();
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
            i=18446744073709551615;
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
                    o=18446744073709551615;
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
        for(f; f<R; f++)
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
        }}
//iki cia
std::chrono::high_resolution_clock::time_point t2=Clock::now();
cout<<"\n";
cout<<(std::chrono::duration_cast<TimeType>(t2 - t1)).count()<<"\n";


































   /* std::chrono::high_resolution_clock::time_point t1=Clock::now();

    for(int i=1; i<=n; i++)
    {
        rf<<"nd"<<i<<"\t";
    }
    rf<<"egzaminas\tgalutinis balas\n";
    for(int j=0; j<10; j++)
    {
        pav="pavarde"+std::to_string(j+1);
        var="vardas"+std::to_string(j+1);
        rf<<var;
        if(var.length()>=8)
        {
            rf<<"\t";
        }
        else
            rf<<"\t\t";
        rf<<pav;
        if(pav.length()>=8)
        {
            rf<<"\t";
        }
        else
            rf<<"\t\t";
        egz=d(mt);
        total=0;
        for(int i=0; i<n; i++)
        {
            paz=d(mt);
            rf<<paz<<"\t";
            total=total+paz;
        }

        rf<<egz<<"\t\t";
        total=total/n*0.4+egz*0.6;
        rf << std::setprecision(3) << total << '\n';
    }




    std::chrono::high_resolution_clock::time_point t2 = Clock::now();
    std::cout<<(std::chrono::duration_cast<TimeType>(t2 - t1)).count()<<"\n";





    //antras failas
    t1=Clock::now();
    rf.open("2.txt");
    rf<<"vardas\t\tpavarde\t\t";
    for(int i=1; i<=n; i++)
    {
        rf<<"nd"<<i<<"\t";
    }
    rf<<"egzaminas\tgalutinis balas\n";
    for(int j=0; j<100; j++)
    {
        pav="pavarde"+std::to_string(j+1);
        var="vardas"+std::to_string(j+1);
        rf<<var;
        if(var.length()>=8)
        {
            rf<<"\t";
        }
        else
            rf<<"\t\t";
        rf<<pav;
        if(pav.length()>=8)
        {
            rf<<"\t";
        }
        else
            rf<<"\t\t";
        egz=d(mt);
        total=0;
        for(int i=0; i<n; i++)
        {
            paz=d(mt);
            rf<<paz<<"\t";
            total=total+paz;
        }

        rf<<egz<<"\t\t";
        total=total/n*0.4+egz*0.6;
        rf << std::setprecision(3) << total << '\n';
    }
    rf.close();
    t2 = Clock::now();
    std::cout<<std::chrono::duration_cast<TimeType>(t2 - t1).count()<<"\n";


    //trecias failas
    t1 = Clock::now();
    rf.open("3.txt");
    rf<<"vardas\t\tpavarde\t\t";
    for(int i=1; i<=n; i++)
    {
        rf<<"nd"<<i<<"\t";
    }
    rf<<"egzaminas\tgalutinis balas\n";
    for(int j=0; j<1000; j++)
    {
        pav="pavarde"+std::to_string(j+1);
        var="vardas"+std::to_string(j+1);
        rf<<var;
        if(var.length()>=8)
        {
            rf<<"\t";
        }
        else
            rf<<"\t\t";
        rf<<pav;
        if(pav.length()>=8)
        {
            rf<<"\t";
        }
        else
            rf<<"\t\t";
        egz=d(mt);
        total=0;
        for(int i=0; i<n; i++)
        {
            paz=d(mt);
            rf<<paz<<"\t";
            total=total+paz;
        }

        rf<<egz<<"\t\t";
        total=total/n*0.4+egz*0.6;
        rf << std::setprecision(3) << total << '\n';
    }
    rf.close();
    t2 = Clock::now();
    std::cout<<std::chrono::duration_cast<TimeType>(t2 - t1).count()<<"\n";

    //ketvirtas failas
    t1 = Clock::now();
    rf.open("4.txt");
    rf<<"vardas\t\tpavarde\t\t";
    for(int i=1; i<=n; i++)
    {
        rf<<"nd"<<i<<"\t";
    }
    rf<<"egzaminas\tgalutinis balas\n";
    for(int j=0; j<10000; j++)
    {
        pav="pavarde"+std::to_string(j+1);
        var="vardas"+std::to_string(j+1);
        rf<<var;
        if(var.length()>=8)
        {
            rf<<"\t";
        }
        else
            rf<<"\t\t";
        rf<<pav;
        if(pav.length()>=8)
        {
            rf<<"\t";
        }
        else
            rf<<"\t\t";
        egz=d(mt);
        total=0;
        for(int i=0; i<n; i++)
        {
            paz=d(mt);
            rf<<paz<<"\t";
            total=total+paz;
        }

        rf<<egz<<"\t\t";
        total=total/n*0.4+egz*0.6;
        rf << std::setprecision(3) << total << '\n';
    }
    rf.close();
    t2 = Clock::now();
    std::cout<<std::chrono::duration_cast<TimeType>(t2 - t1).count()<<"\n";


    //penktas failas
    t1=Clock::now();
    rf.open("5.txt");
    rf<<"vardas\t\tpavarde\t\t";
    for(int i=1; i<=n; i++)
    {
        rf<<"nd"<<i<<"\t";
    }
    rf<<"egzaminas\tgalutinis balas\n";
    for(int j=0; j<100000; j++)
    {
        pav="pavarde"+std::to_string(j+1);
        var="vardas"+std::to_string(j+1);
        rf<<var;
        if(var.length()>=8)
        {
            rf<<"\t";
        }
        else
            rf<<"\t\t";
        rf<<pav;
        if(pav.length()>=8)
        {
            rf<<"\t";
        }
        else
            rf<<"\t\t";
        egz=d(mt);
        total=0;
        for(int i=0; i<n; i++)
        {
            paz=d(mt);
            rf<<paz<<"\t";
            total=total+paz;
        }

        rf<<egz<<"\t\t";
        total=total/n*0.4+egz*0.6;
        rf << std::setprecision(3) << total << '\n';
    }
    rf.close();
    t2 = Clock::now();
    std::cout<<std::chrono::duration_cast<TimeType>(t2 - t1).count()<<"\n";*/
    return 0;
}
