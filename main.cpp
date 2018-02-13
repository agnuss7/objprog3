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
    std::mt19937 mt();
    std::uniform_int_distribution d(1,10);
    std::cout<<"iveskit varda, tada enter, tada pavarde"<<std::endl;
    std::cin>>var>>pav;
    n=d(mt);
    egz=d(mt);
    for(int i=0;i<n;i++)
    {
        total=total+d(mt);
        std::cout<<total<<"\n";
    }
    total=total/n*0.4+egz*0.6;
    std::cout << std::setprecision(3) << total << '\n';
    return 0;
}
