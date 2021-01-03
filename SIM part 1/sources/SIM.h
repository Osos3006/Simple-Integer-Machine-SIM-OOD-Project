#ifndef SIM_H
#define SIM_H
#include "instruction.h"
#include <fstream>
#include <string>
#include "instruction.h"
#include "address.h"
#include "value.h"
#include "add.h"
#include "neg.h"
#include "MUL.h"
#include "JMP.h"
#include "JMP0.h"
#include "ASS.h"
#include "LE.h"
#include "READ.h"
#include "WRITE.h"
#include "HALT.h"
using namespace std;
#define mem_size 1024

class SIM
{

public:
    SIM();
    ~SIM();
    void load_program(string path);
    void test_inst(int n);
    void get_inst_counter();
    void print_data_mem(int n); // prints until first n addresses of the data memory
    void execute_program();

private:
    instruction *inst_memory[mem_size];
    int data_memory[mem_size];
    int inst_counter;
    int PC;
    void execute_inst(instruction *inst);
    void create_inst(string inst, string linefields[], string out);
};

#endif
