#include "nSIM.h"
using namespace std;
nSIM::nSIM(int n)
{
    data_memory = new int[mem_size];
    for (int i = 0; i < 1024; i++)
        data_memory[i] = 0;
    data_memory[1] = 2;
    data_memory[2] = 3;
    data_memory[4] = 6;
    for (int i = 0; i < n; i++)
        SIM_arr.push_back(SIM(data_memory, mutex_arr));
}

nSIM::~nSIM()
{
}