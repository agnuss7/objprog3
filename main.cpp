#include <iostream>
#include <string>
#include <random>
#include <iomanip>
int main()
{
    std::string var, pav;
    int n;
    int egz;
    float total=0;
    std::random_device rd; //ant bibliotekos kompiuterio neveikia...
    std::mt19937 mt (rd());
    std::uniform_int_distribution<> d(1,10);
    std::cout<<"iveskit varda, tada enter, tada pavarde"<<std::endl;
    std::cin>>var>>pav;
    n=d(mt);
    egz=d(mt);
    int *paz= new int[n];
    int temp;
    std::cout<<"su vidurkiu ar mediana? 1-vidurkis, 2-mediana";
    do
    {
        std::cin>>temp;
    }
    while (temp!=1 && temp!=2);
    std::cout<<var<< "  "<<pav<<"  ";
    for(int i=0; i<n; i++)
    {
        paz[i]=d(mt);
        total=total+paz[i];
        std::cout<<paz[i]<<" ";
    }
    std::cout<<egz<<"  ";
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
    std::cout << std::setprecision(3) << total;
    return 0;
}
