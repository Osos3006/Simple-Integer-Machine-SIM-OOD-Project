#ifndef MUL_H
#define MUL_H
#include "instruction.h"

class MUL : public instruction
{

public:
    MUL(int rs1, int rs2, int out_addr, bool rs1_addr, bool rs2_addr, int *data_ptr)
    {
        MUL::rs1 = rs1;
        MUL::rs2 = rs2;
        MUL::out_addr = out_addr;
        MUL::rs1_addr = rs1_addr;
        MUL::rs2_addr = rs2_addr;
        MUL::data_ptr = data_ptr;
        instruction::name = "MUL";
    }

    void virtual execute()
    {
        if (rs1_addr == true)
            rs1 = data_ptr[rs1];

        if (rs2_addr == true)
            rs2 = data_ptr[rs2];

        out = rs1 * rs2;
    }

    int virtual get_out() { return out; }
    int virtual get_out_addr() { return out_addr; }
    ~MUL() {}

private:
    int rs1;
    int rs2;
    int out;
    int out_addr;
    bool rs1_addr;
    bool rs2_addr;
    int *data_ptr;
};

#endif
