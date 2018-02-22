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
    int n;
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
        std::cout<<a[j].var;
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
        std::cout<<"Vardas: "<<a[j].var<<"\n"<<"Pavarde: "<<a[j].pav<<"\n";
        n=a[j].paz.size();
        for(int i=0; i<n; i++)
        {
            a[j].total=a[j].total+a[j].paz[i];
            std::cout<<"ND"<<i+1<<": "<<a[j].paz[i]<<"\n";
        }
        std::cout<<"Egzaminas: "<<a[j].egz<<"\n";
        if(temp==1)
        {
            a[j].total=a[j].total/n*0.4+a[j].egz*0.6;
        }
        else
        {
            for(int i=0; i<n-1; i++)        //isrikiuoju nuo did iki maz
            {
                if(a[j].paz[i]<a[j].paz[i+1])
                {
                    a[j].paz[i]=a[j].paz[i]+a[j].paz[i+1];
                    a[j].paz[i+1]=a[j].paz[i]-a[j].paz[i+1];
                    a[j].paz[i]=a[j].paz[i]-a[j].paz[i+1];
                    i=-1;
                }
            }
            if(n%2==0)
            {
                a[j].total=(a[j].paz[n/2-1]+a[j].paz[n/2])/2;
            }
            else
            {
                a[j].total=a[j].paz[n/2];
            }
            a[j].total=a[j].total*0.4+a[j].egz*0.6;
        }
        std::cout <<"Galutinis balas:  "<< std::setprecision(3) << a[j].total;
    }
    return 0;
}
