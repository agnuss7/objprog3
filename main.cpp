#include "studentai.h"
#include "funkcijos.cpp"
#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
using std::cout;
using std::cin;
typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::milliseconds TimeType;
int main()
{
    std::chrono::high_resolution_clock::time_point t1;
    std::chrono::high_resolution_clock::time_point t2;
    std::string P;
    std::size_t N=0;
    std::size_t M=20;
    do {
            cout<<"Pasirinkite norima operacija:\n1 - ivesti studentus ranka.\n2 - generuokim studentu pazymius\n3 - skaiciuoti laika\n0 - noredami baigti programa\n";
            cin>>M;

    if(M==1)
    {
        cout<<"sekite instrukcijom. iveskit varda, tada Tab, pavarde, vel tab, tada atskirdami\ntarpais veskit pazymius, paskutinis skaicius bus \negzamino pazymys, tada pereikit i kita eitute ir kartokit.\nnoredami baigti, naujoj eilutej dekit - zenkla ir enter.\n";
    std::ofstream rf("cheatycheat.txt");
    N=0;
    P.clear();
    while(P.back()!='-'){std::getline(cin,P);
    rf<<P<<"\n";N++;}
N--;N--;
rf.close();
std::vector<studentai> x;
x.reserve(N);
x.resize(N);
std::ifstream df ("cheatycheat.txt");
df.ignore();
cout<<"vardas\t\tpavarde\t\tVid. gal.\tMed gal.\n";
for(std::size_t i=0;i<N;i++)
   {
    x[i].read(df);
    x[i].vidurkis();
    x[i].mediana();

   }
   std::sort(x.begin(),x.end(),compare);
   for(std::size_t i=0;i<N;i++)
   {
x[i].print(1);
   }

    }
    else if(M==2)
    {
    std::mt19937_64 rd(std::random_device{}());
    std::uniform_int_distribution<std::size_t> dist(0, 10);
    std::string Name;
    std::string Sname;
    std::vector<std::size_t> mark;
    mark.reserve(30);
    std::size_t exam;
    int s;
    studentai X;
    int kk=0;
   std::string stupid[]={"1.txt","2.txt","3.txt","4.txt","5.txt"};
  for(std::size_t t=10;t<=100000;t*=10){

t1=Clock::now();
    s=rd()%30+1;
    mark.resize(s);
    std::ofstream gf(stupid[kk]);
    gf<<"Vardas\t\tPavarde\t\t";
    for(std::size_t i=1;i<=s;i++)
    {
        gf<<"ND"<<i<<"\t";
    }
    gf<<"egz\n";
    for(std::size_t i=0;i<t;i++)
    {
        Name="Vardas"+std::to_string(i+1);
        Sname="Pavarde"+std::to_string(i+1);
        for(int l=0;l<s;l++)
        {
            mark[l]=dist(rd);
        }
        exam=dist(rd);
        X.add(Name,Sname,exam,mark);
        gf<<X;
    }
    kk++;
    gf.close();
    t2=Clock::now();
    cout<<t<<" studentu uztruko: "<<(std::chrono::duration_cast<TimeType>(t2 - t1)).count()<<" milisekundes \n";
    }
    }
    else if(M==3)
    {
        int q, w;
        cout<<"koki konteineri norit naudot?\n1 - vector\n2 - deque\n3 - list\n";
        do
        {
            cin>>q;
        } while (q>3 || q<1);
        cout<<"keliuose konteineriuose? 2 arba 3\n";
        do
        {
            cin>>w;
        } while (w>3 || w<1);
        cout<<"kiek studentu perskaityt?\n";
        do
        {
            cin>>N;
        } while (N>100000);
        if(q==1)
        {
            if(w==2)
            {
                t1=Clock::now();
                cont2v("5.txt",N);
                t2=Clock::now();
                cout<<(std::chrono::duration_cast<TimeType>(t2 - t1)).count()<<" milisekundes \n";
            }
            else if(w==3)
            {
                t1=Clock::now();
                cont3v("5.txt",N);
                t2=Clock::now();
                cout<<(std::chrono::duration_cast<TimeType>(t2 - t1)).count()<<" milisekundes \n";
            }
        }
        else if(q==2)
        {
            if(w==2)
            {
                t1=Clock::now();
                cont2d("5.txt",N);
                t2=Clock::now();
                cout<<(std::chrono::duration_cast<TimeType>(t2 - t1)).count()<<" milisekundes \n";
            }
            else if(w==3)
            {
                t1=Clock::now();
                cont3d("5.txt",N);
                t2=Clock::now();
                cout<<(std::chrono::duration_cast<TimeType>(t2 - t1)).count()<<" milisekundes \n";
            }
        }
        else if(q==3)
        {
            if(w==2)
            {
                t1=Clock::now();
                cont2l("5.txt",N);
                t2=Clock::now();
                cout<<(std::chrono::duration_cast<TimeType>(t2 - t1)).count()<<" milisekundes \n";
            }
            else if(w==3)
            {
                t1=Clock::now();
                cont3l("5.txt",N);
                t2=Clock::now();
                cout<<(std::chrono::duration_cast<TimeType>(t2 - t1)).count()<<" milisekundes \n";
            }
        }

    }}while(M!=0);

    return 0;
}
