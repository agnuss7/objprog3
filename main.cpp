#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include "studentai.h"
#include "sukeist.h"
int main()
{
    std::ifstream df("kursiokai.txt");
    if(!df)
    {
        std::cout<<"failas neegzistuoja";
        return 0;
    }
    char b;
    std::size_t n;
    std::vector<studentai> a;
    a.resize(1);
    while(b!='\n')
    {
        df.get(b);
    }
    df.get(b);
    std::size_t j=0;
    while (isalpha(b)>0)
    {
        while(b!='\t')
        {
            a[j].var.push_back(b);
            df.get(b);
        }
        df.get(b);
        if(b=='\t')
        {
            df.get(b);
        }
        while(b!='\t')
        {
            a[j].pav.push_back(b);
            df.get(b);
        }
        try
        {
            while (b!='\n')
            {
                df>>n;
                a[j].paz.push_back(n);
                df.get(b);
            }
        }
        catch (std::exception& e)
        {
            std::cout<<"kursiokai.txt failas neteisingu formatu. greaiciausiai nera paciam gale perejimo i kita eilute.\n";
            return 0;
        }
        a[j].egz=a[j].paz.back();
        a[j].paz.pop_back();
        df.get(b);
        j++;
        a.resize(j+1);
    }
    df.close();
    a.resize(j);
    try
    {
        for(int i=0; i<j-1; i++)
        {
            if(a[i].pav>a[i+1].pav)
            {
                sukeist(a[i],a[i+1]);
                i=-1;
            }
        }
        for(std::size_t i=0; i<j; i++) //suskaiciuoja nd vidurkius/medianas
        {

            n=a[i].paz.size();
            a[i].vidnd=0;
            for(std::size_t o=0; o<n; o++)
            {
                a[i].vidnd=a[i].vidnd+a[i].paz[o];
            }
            a[i].vidnd=a[i].vidnd/n;
            for(int o=0; o<n-1; o++)        //isrikiuoju nuo did iki maz
            {
                if(a[i].paz[o]<a[i].paz[o+1])
                {
                    a[i].paz[o]=a[i].paz[o]+a[i].paz[o+1];
                    a[i].paz[o+1]=a[i].paz[o]-a[i].paz[o+1];
                    a[i].paz[o]=a[i].paz[o]-a[i].paz[o+1];
                    o=-1;
                }
            }
            if(n%2==0)
            {
                a[i].mednd=(a[i].paz[(n/2)-1]+a[i].paz[n/2])/2;
            }
            else
            {
                a[i].mednd=a[i].paz[n/2];
            }

        }
        std::size_t f=j; //f zymes kelintam elemente jau yra nelaike egzamino vaikai
        for(int i=0; i<j; i++)
        {
            if((a[i].vidnd<6 || a[i].mednd<6) && i<f)
            {
                for(int o=i; o<j-1; o++)
                {
                    sukeist(a[o],a[o+1]);
                }
                i--;
                f--;
            }
        }
        std::cout<<"The cool kidz:\n";
        std::cout<<"Vardas\t\tPavarde\t\tGal. vidurkis\tGal. mediana\n";
        for(std::size_t i=0; i<f; i++)
        {
            std::cout<<a[i].var;
            if (a[i].var.size()<8)
            {
                std::cout<<"\t\t";
            }
            else
            {
                std::cout<<"\t";
            }
            std::cout<<a[i].pav;
            if (a[i].pav.size()<8)
            {
                std::cout<<"\t\t";
            }
            else
            {
                std::cout<<"\t";
            }

            a[i].vidtotal=a[i].vidnd*0.4+a[i].egz*0.6;
            a[i].medtotal=a[i].mednd*0.4+a[i].egz*0.6;
            std::cout<<std::setprecision(3)<<a[i].vidtotal<<"\t\t";
            std::cout<<std::setprecision(3)<<a[i].medtotal<<"\n";

        }
        std::cout<<"Da stoopid loosers:\n";
        std::cout<<"Vardas\t\tPavarde\t\tGal. vidurkis\tGal. mediana\n";
        for(f; f<j; f++)
        {
            std::cout<<a[f].var;
            if (a[f].var.size()<8)
            {
                std::cout<<"\t\t";
            }
            else
            {
                std::cout<<"\t";
            }
            std::cout<<a[f].pav;
            if (a[f].pav.size()<8)
            {
                std::cout<<"\t\t";
            }
            else
            {
                std::cout<<"\t";
            }

            std::cout<<"neislaike ir nebuvo prileisti prie egzamino\n";
        }
    }
    catch (std::bad_alloc& e)
    {
        std::cout<<"negalime isrikiuot vardu.";
    }
    return 0;
}
