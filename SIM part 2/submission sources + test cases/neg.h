#ifndef NEG_H
#define NEG_H
#include "instruction.h"

class NEG : public instruction
{

public:
    NEG(int rs1, int out_addr, bool rs1_addr, int *data_ptr) // flags to determine the type of the operands
    {
        NEG::rs1 = rs1;
        NEG::out_addr = out_addr;
        NEG::rs1_addr = rs1_addr;
        NEG::data_ptr = data_ptr;
        instruction::name = "NEG";
    }

    void virtual execute()
    {
        if (rs1_addr)
            rs1 = data_ptr[rs1];
        out = -rs1;
    }

    int virtual get_out() { return out; }
    int virtual get_out_addr() { return out_addr; }
    virtual ~NEG() {}

private:
    int rs1;
    int out;
    int out_addr;
    bool rs1_addr;
    int *data_ptr;
};

#endif
