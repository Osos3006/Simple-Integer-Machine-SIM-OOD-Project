#ifndef LE_H
#define LE_H
#include "instruction.h"

class LE : public instruction
{

public:
    LE(int rs1, int rs2, int out_addr, bool rs1_addr, bool rs2_addr, int *data_ptr) // flags to determine the type of the operands
    {
        LE::rs1 = rs1;
        LE::rs2 = rs2;
        LE::out_addr = out_addr;
        LE::rs1_addr = rs1_addr;
        LE::rs2_addr = rs2_addr;
        LE::data_ptr = data_ptr;
        instruction::name = "LE";
    }

    void virtual execute()
    {
        if (rs1_addr == true)
            rs1 = data_ptr[rs1];

        if (rs2_addr == true)
            rs2 = data_ptr[rs2];

        if (rs1 < rs2)
            out = 1;
        else
            out = 0;
    }

    int virtual get_out() { return out; }
    int virtual get_out_addr() { return out_addr; }
    ~LE() {}

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
