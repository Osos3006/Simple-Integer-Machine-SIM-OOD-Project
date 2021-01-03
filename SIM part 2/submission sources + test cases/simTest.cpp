#include "SIM.h"
#include <iostream>
using namespace std;

int main()
{
    SIM processor = SIM();
    processor.load_program("test5.txt");
    //for (int i = 0; i < 3; i++)
    //processor.test_inst(i);
    //processor.get_inst_counter();
    processor.execute_program();
    processor.print_data_mem(21);
    return 0;
}
