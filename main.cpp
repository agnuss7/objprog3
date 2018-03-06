#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <iomanip>
#include <chrono>
const int n=20;
typedef std::chrono::high_resolution_clock Clock;

int main()

{

    std::string var, pav;
    int egz;
    float total;
    int paz;
    //std::random_device rd;
    std::mt19937 mt (5468);//mt(rd());
    std::uniform_int_distribution<> d(1,10);
    auto t1=Clock::now();
    //pirmas failas
    std::ofstream rf("1.txt");
    rf<<"vardas\t\tpavarde\t\t";
    for(int i=1;i<=n;i++)
    {
        rf<<"nd"<<i<<"\t";
    }
    rf<<"egzaminas\tgalutinis balas\n";
    for(int j=0;j<10;j++)
    {
    pav="pavarde"+std::to_string(j+1);
    var="vardas"+std::to_string(j+1);
    rf<<var;
    if(var.length()>=8)
    {
        rf<<"\t";
    }
    else rf<<"\t\t";
    rf<<pav;
    if(pav.length()>=8)
    {
        rf<<"\t";
    }
    else rf<<"\t\t";
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
    auto t2 = Clock::now();
    std::cout<<std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()<<"\n";
    t1=Clock::now();

    //antras failas
    rf.open("2.txt");
    rf<<"vardas\t\tpavarde\t\t";
    for(int i=1;i<=n;i++)
    {
        rf<<"nd"<<i<<"\t";
    }
    rf<<"egzaminas\tgalutinis balas\n";
    for(int j=0;j<100;j++)
    {
    pav="pavarde"+std::to_string(j+1);
    var="vardas"+std::to_string(j+1);
    rf<<var;
    if(var.length()>=8)
    {
        rf<<"\t";
    }
    else rf<<"\t\t";
    rf<<pav;
    if(pav.length()>=8)
    {
        rf<<"\t";
    }
    else rf<<"\t\t";
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
    std::cout<<std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()<<"\n";

    t1 = Clock::now();
    //trecias failas
    rf.open("3.txt");
    rf<<"vardas\t\tpavarde\t\t";
    for(int i=1;i<=n;i++)
    {
        rf<<"nd"<<i<<"\t";
    }
    rf<<"egzaminas\tgalutinis balas\n";
    for(int j=0;j<1000;j++)
    {
    pav="pavarde"+std::to_string(j+1);
    var="vardas"+std::to_string(j+1);
    rf<<var;
    if(var.length()>=8)
    {
        rf<<"\t";
    }
    else rf<<"\t\t";
    rf<<pav;
    if(pav.length()>=8)
    {
        rf<<"\t";
    }
    else rf<<"\t\t";
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
    std::cout<<std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()<<"\n";
    t1 = Clock::now();
    //ketvirtas failas
    rf.open("4.txt");
    rf<<"vardas\t\tpavarde\t\t";
    for(int i=1;i<=n;i++)
    {
        rf<<"nd"<<i<<"\t";
    }
    rf<<"egzaminas\tgalutinis balas\n";
    for(int j=0;j<10000;j++)
    {
    pav="pavarde"+std::to_string(j+1);
    var="vardas"+std::to_string(j+1);
    rf<<var;
    if(var.length()>=8)
    {
        rf<<"\t";
    }
    else rf<<"\t\t";
    rf<<pav;
    if(pav.length()>=8)
    {
        rf<<"\t";
    }
    else rf<<"\t\t";
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
    std::cout<<std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()<<"\n";

    t1=Clock::now();

    //penktas failas
    rf.open("5.txt");
    rf<<"vardas\t\tpavarde\t\t";
    for(int i=1;i<=n;i++)
    {
        rf<<"nd"<<i<<"\t";
    }
    rf<<"egzaminas\tgalutinis balas\n";
    for(int j=0;j<100000;j++)
    {
    pav="pavarde"+std::to_string(j+1);
    var="vardas"+std::to_string(j+1);
    rf<<var;
    if(var.length()>=8)
    {
        rf<<"\t";
    }
    else rf<<"\t\t";
    rf<<pav;
    if(pav.length()>=8)
    {
        rf<<"\t";
    }
    else rf<<"\t\t";
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
    std::cout<<std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()<<"\n";

    return 0;
}
