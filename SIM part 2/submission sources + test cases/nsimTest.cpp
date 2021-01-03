#include "nSIM.h"
#include <thread>
#include <iostream>
using namespace std;
int n = 2;
nSIM nprocessors(n);
int main()
{
    

    vector<thread> processor_threads;
    //programs should be initialized one by one here.
    nprocessors.SIM_arr[0].load_program("test5.txt");
    nprocessors.SIM_arr[1].load_program("test6.txt");
    for (int i = 0 ; i < n ; i++)
    processor_threads.push_back(
        thread([i]()
            {
                nprocessors.SIM_arr[i].execute_program();
            })
    );

    for (thread& t : processor_threads)
        t.join();
    //nprocessors.SIM_arr[0].load_program("test5.txt");
    //processor.load_program("test5.txt");
    //for (int i = 0; i < 3; i++)
    //processor.test_inst(i);
    //processor.get_inst_counter();
    //nprocessors.SIM_arr[0].execute_program();
    nprocessors.SIM_arr[0].print_data_mem(21);
    return 0;
}
