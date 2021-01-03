#ifndef WRITE_H
#define WRITE_H
#include "instruction.h"

class WRITE : public instruction
{

public:
    WRITE(int out_addr, int *data_ptr) // flags to determine the type of the operands
    {
        WRITE::out_addr = out_addr;
        WRITE::data_ptr = data_ptr;
        instruction::name = "WRITE";
    }

    void virtual execute()
    {
        cout << data_ptr[out_addr] << endl; //prints an endl after the address
    }

    int virtual get_out() {}
    int virtual get_out_addr() { return out_addr; }
    ~WRITE() {}

private:
    int out_addr;
    int *data_ptr;
};

#endif
