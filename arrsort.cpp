// Include standard library files
#include <iostream>
#include <fstream>
using namespace std;

#pragma pack(1)
    struct Group {
        short value;
        unsigned char flag[13];
    };

int main()
{
    Group r;
    FILE *f;
	  f = fopen("input_stream.bin", "rb");

    for (int i=0; i<99; i++)
    {
        fread(&r, sizeof(struct Group),1,f);
        cout << r.value << ",";
        for (int j = 0; j < 13; j++)
        {
            printf("%02x", r.flag[12-j]);
        }
        cout << endl;
    }

    return 0;
}