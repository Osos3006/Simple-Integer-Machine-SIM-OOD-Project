#ifndef nSIM_H
#define nSIM_H
#include "SIM.h"
#include <mutex>
#include <vector>
using namespace std;
#define mem_size 1024

class nSIM
{

public:
    nSIM(int n);
    ~nSIM();

    vector<SIM> SIM_arr;

private:
    int *data_memory;
    mutex mutex_arr[mem_size];
};

#endif
