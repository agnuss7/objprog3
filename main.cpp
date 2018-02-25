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
        std::cout<<"Vardas\t\tPavarde\t\tGal. vidurkis\tGal. mediana\n";
        for(int i=0; i<j-1; i++)
        {
            if(a[i].pav>a[i+1].pav)
            {
                sukeist(a[i],a[i+1]);
                i=-1;
            }
        }
        for(std::size_t i=0; i<j; i++)
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
            n=a[i].paz.size();
            for(std::size_t o=0; o<n; o++)
            {
                a[i].total=a[i].total+a[i].paz[o];
            }

            a[i].total=a[i].total/n*0.4+a[i].egz*0.6;
            std::cout<<std::setprecision(3)<<a[i].total<<"\t\t";
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
                a[i].total=(a[i].paz[(n/2)-1]+a[i].paz[n/2])/2;
            }
            else
            {
                a[i].total=a[i].paz[n/2];
            }
            a[i].total=a[i].total*0.4+a[i].egz*0.6;
            std::cout<<std::setprecision(3)<<a[i].total<<"\n";
        }
    }
    catch (std::bad_alloc& e)
    {
        std::cout<<"negalime isrikiuot vardu.";
    }
    return 0;
}
