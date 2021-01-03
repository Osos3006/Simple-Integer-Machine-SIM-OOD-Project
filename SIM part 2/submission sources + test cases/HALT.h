#ifndef HALT_H
#define HALT_H
#include "instruction.h"

class HALT : public instruction
{

public:
    HALT() // flags to determine the type of the operands
    {
        instruction::name = "HALT";
    }

    void virtual execute()
    {
        out = 1024;
    }

    int virtual get_out() { return out; }
    int virtual get_out_addr() { return out; }
    virtual ~HALT() {}

private:
    int out;
};

#endif
