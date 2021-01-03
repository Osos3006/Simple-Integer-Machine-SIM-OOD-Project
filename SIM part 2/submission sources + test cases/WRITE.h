#ifndef WRITE_H
#define WRITE_H
#include "instruction.h"

class WRITE : public instruction
{

public:
    WRITE(int out_addr, bool is_addr, int *data_ptr) // flags to determine the type of the operands
    {
        WRITE::out_addr = out_addr;
        WRITE::data_ptr = data_ptr;
        WRITE::is_addr = is_addr;
        instruction::name = "WRITE";
    }

    void virtual execute()
    {
        if (is_addr)
            cout << data_ptr[out_addr] << endl; //prints an endl after the address
        else
            cout << out_addr << endl;
    }

    int virtual get_out() { return out_addr; }
    int virtual get_out_addr() { return out_addr; }
    virtual ~WRITE() {}

private:
    int out_addr;
    bool is_addr;
    int *data_ptr;
};

#endif
