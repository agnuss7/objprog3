#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
int main()
{
    std::string var, pav;
    int n;
    int egz;
    float total=0;
    srand(time(NULL));
    std::cout<<"iveskit varda, tada enter, tada pavarde"<<std::endl;
    std::cin>>var>>pav;
    n=rand()%30+6;
    egz=rand()%10+1;
    for(int i=0;i<n;i++)
    {
        total=total+rand()%10+1;
        std::cout<<total<<"\n";
    }
    total=total/n*0.4+egz*0.6;
    std::cout << std::setprecision(3) << total << '\n';
    return 0;
}
