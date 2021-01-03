#ifndef ASS_H
#define ASS_H
#include "instruction.h"

class ASS : public instruction
{

public:
    ASS(int rs1, int out_addr, bool rs1_addr, int *data_ptr) // flags to determine the type of the operands
    {
        ASS::rs1 = rs1;
        ASS::out_addr = out_addr;
        ASS::rs1_addr = rs1_addr;
        ASS::data_ptr = data_ptr;
        instruction::name = "ASS";
    }

    void virtual execute()
    {
        if (rs1_addr)
            rs1 = data_ptr[rs1];
        out = rs1;
    }

    int virtual get_out() { return out; }
    int virtual get_out_addr() { return out_addr; }
    ~ASS() {}

private:
    int rs1;
    int out;
    int out_addr;
    bool rs1_addr;
    int *data_ptr;
};

#endif
