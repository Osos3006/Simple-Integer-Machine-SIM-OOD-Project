#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <string>
using namespace std;

class instruction
{

    friend class SIM;

public:
    virtual void execute() = 0;
    virtual int get_out() = 0;
    virtual int get_out_addr() = 0; 
    virtual ~instruction() {}

    string name;
};

#endif