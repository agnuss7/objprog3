#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>


int main()

{
    float total;
    std::ifstream df ("duom.txt");
    char b;
    std::vector<char> v[5];
    while(b!='\n')
    {
        b=df.get();
    }
    return 0;
}
