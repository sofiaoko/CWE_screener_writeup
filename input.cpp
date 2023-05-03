// Include standard library files
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    unsigned int userin = 0;
    unsigned int convert;
    // cin >> userin;

    while (true)
    {
        convert = (userin ^ 0x735) >> 4 ^ 0x6f0;
        if (convert == 12091906)
        {
            cout << userin;
            break;
        }
        else
        {
            userin++;
        }     
    }

    return 0;
}