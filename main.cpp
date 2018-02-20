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
     std::mt19937 mt(rd());
     std::uniform_int_distribution<> d(1,10);
     std::cout<<"iveskit varda, tada enter, tada pavarde"<<std::endl;
     std::cin>>var>>pav;
     n=d(mt);
     egz=d(mt);
     int paz;
     std::cout<<var<< "  "<<pav<<"  ";
     for(int i=0;i<n;i++)
     {
         paz=d(mt);
         total=total+paz;
         std::cout<<paz<<" ";
     }
     std::cout<<egz<<"  ";
     total=total/n*0.4+egz*0.6;
     std::cout << std::setprecision(3) << total << '\n';
     return 0;
}
