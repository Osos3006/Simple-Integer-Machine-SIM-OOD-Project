#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
#include <stdlib.h>
using namespace std;
class address
{

public:
    address(string x) // addresses are perceived by $
    {

        string z = x.substr(1, x.length() - 1);
        addr = atoi(z.c_str());
    }

    int get_addr() { return addr; }

private:
    int addr;
};

#endif