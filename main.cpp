#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
int main()
{
    std::string var, pav;
    std::size_t n=8; //tiesiog prilyginu ne nuliui
    int egz;
    float total=0;
    std::vector<int> paz;
    std::cout<<"iveskit varda, tada enter, tada pavarde"<<std::endl;
    std::cin>>var>>pav;
    std::cout<<"veskit pazymius, kai baigsit, spauskit 0"<<"\n";
    while (n!=0)
    {
        std::cin>>n;
        paz.push_back(n);
    }
    paz.pop_back();
    std::cout<<"Egzamino rez?";
    std::cin>>egz;
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
