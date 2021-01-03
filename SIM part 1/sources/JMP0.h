#ifndef JMP0_H
#define JMP0_H
#include "instruction.h"

class JMP0 : public instruction
{

public:
    JMP0(int rs1, int out_addr, bool rs1_addr, int *data_ptr) // flags to determine the type of the operands
    {
        JMP0::rs1 = rs1;
        JMP0::out_addr = out_addr;
        JMP0::rs1_addr = rs1_addr;
        JMP0::data_ptr = data_ptr;
        instruction::name = "JMP0";
    }

    void virtual execute()
    {
        if (rs1_addr)
            rs1 = data_ptr[rs1];

        if (rs1 == 0)
            out = out_addr - 1; // -1 to accomodate for the PC++ in the main program execution
        else
            out = -1; //invalid jmp address
    }

    int virtual get_out() { return out; }
    int virtual get_out_addr() { return out_addr; }
    ~JMP0() {}

private:
    int rs1;
    int out_addr;
    int out;
    bool rs1_addr;
    int *data_ptr;
};

#endif
