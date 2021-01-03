#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <string>
using namespace std;

class instruction
{

    friend class SIM;

public:
    virtual void execute() {}
    virtual int get_out() {}
    virtual int get_out_addr() {}

    string name;
};

#endif