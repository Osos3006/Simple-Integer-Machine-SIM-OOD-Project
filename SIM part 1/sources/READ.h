#ifndef READ_H
#define READ_H
#include "instruction.h"

class READ : public instruction
{

public:
    READ(int out_addr) // flags to determine the type of the operands
    {
        READ::out_addr = out_addr;
        instruction::name = "READ";
    }

    void virtual execute()
    {
        cin >> out;
    }

    int virtual get_out() { return out; }
    int virtual get_out_addr() { return out_addr; }
    ~READ() {}

private:
    int out_addr;
    int out;
};

#endif
