1) how to compile the simulator:
It is preferred to run the simulation using visual studio.
the main file is : nSIMtest.cpp
Exclude "simTest".cpp from build.

2) To change the testfile :

in load_program function in the simTest.cpp file -> set the name of the program you want to load_program
-> it is a must to load the program manually in each sim file in the main function using load_program function.

3) How to use?

addresses are preceeded by : $
values/constants are preceeded by : #

--> if it is mentioned in the requirements that the value can only hold an address, the simulation treats it as an address
automatically. however, if it can hold either values, the simulator checks whether it is a value or an address.

--> ALERT : not following the specified format of the file causes the program to crash (enters an infinite loop then stops) [May be handelled later]

--> the simulator prints the current instruction in execution and it is address in the instruction memory. moreoever, it prints the fields of each instruction when loading the program(can be disabled if needed)
--> the simulator follows the fetch, decode, execute cycle. hence, it loads the whole program to the instruction memory first, then it executes the program.

--> ALERT:
The output of multiple threads overlaps. this can be solved by creating a stringstream from the <<sstream>> header and outputing the output of each stringstream that is created
locally for each thread using cout in the end. 

for example:

Test case 8 increments one in address 0 using 10 simulations.
