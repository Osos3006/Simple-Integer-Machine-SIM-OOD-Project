#ifndef ADD_H
#define ADD_H
#include "instruction.h"
class ADD : public instruction
{

public:
    ADD(int rs1, int rs2, int out_addr, bool rs1_addr, bool rs2_addr, int *data_ptr) // flags to determine the type of the operands , not the best option to pass a pointer to the data memory
    {
        ADD::rs1 = rs1;
        ADD::rs2 = rs2;
        ADD::out_addr = out_addr;
        ADD::rs1_addr = rs1_addr;
        ADD::rs2_addr = rs2_addr;
        ADD::data_ptr = data_ptr;
        instruction::name = "ADD";
    }

    void virtual execute()
    {

        if (rs1_addr == true)
            rs1 = data_ptr[rs1];

        if (rs2_addr == true)
            rs2 = data_ptr[rs2];

        //cout << rs1 << rs2 << endl;
        out = rs1 + rs2;
    }

    int virtual get_out() { return out; }
    int virtual get_out_addr() { return out_addr; }
    virtual ~ADD() {}

private:
    int rs1;
    int rs2;
    bool rs1_addr;
    bool rs2_addr;
    int out;
    int *data_ptr;
    int out_addr;
};

#endif
