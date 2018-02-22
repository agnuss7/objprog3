#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <cctype>

struct studentai
{
    std::string var;
    std::string pav;
    std::vector<size_t> paz;
    std::size_t egz;
    float total;
};
int main()
{
    std::ifstream df ("duom.txt");
    char b;
    std::size_t n;
    std::vector<studentai> a;
    a.resize(1);
    while(b!='\n')
    {
        df.get(b);
    }
    df.get(b);
    int j=0;
    while (isalpha(b)>0)
    {
        while(b!='\t')
        {
            a[j].var.push_back(b);
            df.get(b);
        }
        df.get(b);
        while(b!='\t')
        {
            a[j].pav.push_back(b);
            df.get(b);
        }
        while (b!='\n')
        {
            df>>n;
            a[j].paz.push_back(n);
            df.get(b);
        }
        a[j].egz=a[j].paz.back();
        a[j].paz.pop_back();
        df.get(b);
        j++;
        a.resize(j+1);
    }
    int temp;
    std::cout<<"su vidurkiu ar mediana? 1-vidurkis, 2-mediana";
    do
    {
        std::cin>>temp;
    }
    while (temp!=1 && temp!=2);
    for(int i=0; i<j; i++)
    {
        std::cout<<"Vardas: "<<a[i].var<<"\n"<<"Pavarde: "<<a[i].pav<<"\n";
        n=a[i].paz.size();
        for(int o=0; o<n; o++)
        {
            a[i].total=a[i].total+a[i].paz[o];
            std::cout<<"ND"<<i+1<<": "<<a[i].paz[o]<<"\n";
        }
        std::cout<<"Egzaminas: "<<a[i].egz<<"\n";
        if(temp==1)
        {
            a[i].total=a[i].total/n*0.4+a[i].egz*0.6;
        }
        else
        {
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
        }
        std::cout <<"Galutinis balas:  "<< std::setprecision(3) << a[i].total<<"\n";
    }
    return 0;
}
