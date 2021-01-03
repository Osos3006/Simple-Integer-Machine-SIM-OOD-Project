#ifndef JMP_H
#define JMP_H
#include "instruction.h"

class JMP : public instruction
{

public:
    JMP(int out_addr) // flags to determine the type of the operands
    {
        JMP::out_addr = out_addr;
        instruction::name = "JMP";
    }

    void virtual execute()
    {
        out = out_addr - 1; // -1 to accomodate for the PC++ in the main program execution
    }

    int virtual get_out() { return out; }
    int virtual get_out_addr() { return out_addr; }
    ~JMP() {}

private:
    int out_addr;
    int out;
};

#endif
