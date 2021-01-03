#ifndef VALUE_H
#define VALUE_H
#include <string>
#include <stdlib.h>
using namespace std;
class value
{

public:
    value(string x) // values are perceived by #
    {

        string z = x.substr(1, x.length() - 1);
        v = atoi(z.c_str());
    }

    int get_value() { return v; }

private:
    int v;
};

#endif