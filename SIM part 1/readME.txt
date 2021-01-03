1) how to compile the simulator:
run the following commands:
g++ simTest.cpp SIM.cpp -o simTest
./simTest

2) To change the testfile :

in load_program function in the simTest.cpp file -> set the name of the program you want to load_program

3) How to use?

addresses are preceeded by : $
values/constants are preceeded by : #

--> if it is mentioned in the requirements that the value can only hold an address, the simulation treats it as an address
automatically. however, if it can hold either values, the simulator checks whether it is a value or an address.

--> ALERT : not following the specified format of the file causes the program to crash (enters an infinite loop then stops) [May be handelled later]

--> the simulator prints the current instruction in execution and it is address in the instruction memory. moreoever, it prints the fields of each instruction when loading the program(can be disabled if needed)
--> the simulator follows the fetch, decode, execute cycle. hence, it loads the whole program to the instruction memory first, then it executes the program.