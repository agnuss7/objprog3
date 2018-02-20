#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
int main()
{
    std::ifstream df ("duom.txt");
    std::string var, pav;
    std::size_t n=8; //tiesiog prilyginu ne nuliui
    int egz;
    float total=0;
    char b;
    std::vector<int> paz;
    while(b!='\n')
    {
        df.get(b);
    }
    df.get(b);
    while(b!=' ')
    {
        var.push_back(b);
        df.get(b);
    }
    df.get(b);
    while(b!=' ')
    {
        pav.push_back(b);
        df.get(b);
    }
    while (b!='\n')
    {
        df>>n;
        paz.push_back(n);
        df.get(b);
    }
    egz=paz.back();
    paz.pop_back();
    int temp;
    std::cout<<"su vidurkiu ar mediana? 1-vidurkis, 2-mediana";
    do
    {
        std::cin>>temp;
    }
    while (temp!=1 && temp!=2);
    std::cout<<"Vardas: "<<var<<"\n"<<"Pavarde: "<<pav<<"\n";
    n=paz.size();
    for(int i=0; i<n; i++)
    {
        total=total+paz[i];
        std::cout<<"ND"<<i+1<<": "<<paz[i]<<"\n";
    }
    std::cout<<"Egzaminas: "<<egz<<"\n";
    if(temp==1)
    {
        total=total/n*0.4+egz*0.6;
    }
    else
    {
        for(int i=0; i<n-1; i++)        //isrikiuoju nuo did iki maz
        {
            if(paz[i]<paz[i+1])
            {
                paz[i]=paz[i]+paz[i+1];
                paz[i+1]=paz[i]-paz[i+1];
                paz[i]=paz[i]-paz[i+1];
                i=-1;
            }
        }
        if(n%2==0)
        {
            total=(paz[n/2-1]+paz[n/2])/2;
        }
        else
        {
            total=paz[n/2];
        }
        total=total*0.4+egz*0.6;
    }
    std::cout <<"Galutinis balas:  "<< std::setprecision(3) << total;
    return 0;
}
