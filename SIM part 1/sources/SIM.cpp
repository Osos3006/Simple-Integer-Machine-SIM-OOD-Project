#include "SIM.h"
using namespace std;

SIM::SIM()
{

    inst_counter = 0;
    PC = 0;
    for (int i = 0; i < 1024; i++)
        data_memory[i] = 0;

    data_memory[1] = 2;
    data_memory[2] = 3;
}

void SIM::load_program(string path)
{
    ifstream source;
    string inst, out;
    string linefields[2];
    source.open(path.c_str());
    if (source.fail())
        cout << "failed to open the file";
    else
    {
        string line = "";
        string delimiter = ",";

        int pos = 0;
        int i = 0;
        while (getline(source, line))
        {
            cout << "instruction fields:" << endl;
            i = 0;
            pos = line.find(" ");
            inst = line.substr(0, pos);
            cout << "inst : " << inst << endl;
            line.erase(0, pos + 1);

            while ((pos = line.find(delimiter)) != string::npos)
            {
                string token = line.substr(0, pos);
                linefields[i] = token;
                cout << "in" << i << " :" << token << endl;
                i++;

                line.erase(0, pos + delimiter.length());
            }
            out = line;
            cout << "out " << out << endl;

            create_inst(inst, linefields, out);
        }
    }
}

void SIM::create_inst(string inst, string linefields[], string out)
{
    if (inst == "ADD")
    {

        int rs1, rs2, out_addr;
        bool rs1_addr, rs2_addr;
        address o(out);
        out_addr = o.get_addr();
        if (linefields[0][0] == '$')
        {
            string z = linefields[0].substr(1, linefields[0].length() - 1);
            rs1 = atoi(z.c_str());
            //rs1 = data_memory[rs1];
            rs1_addr = true;
        }

        else if (linefields[0][0] == '#')
        {
            string z = linefields[0].substr(1, linefields[0].length() - 1);
            rs1 = atoi(z.c_str());
            rs1_addr = false;
        }

        if (linefields[1][0] == '$')
        {
            string z = linefields[1].substr(1, linefields[1].length() - 1);
            rs2 = atoi(z.c_str());
            //rs2 = data_memory[rs2];
            rs2_addr = true;
        }

        else if (linefields[1][0] == '#')
        {
            string z = linefields[1].substr(1, linefields[1].length() - 1);
            rs2 = atoi(z.c_str());
            rs2_addr = false;
        }
        //ADD inst(rs1, rs2, out_addr);
        //cout << "answer: " << data_memory[out_addr] << endl;

        inst_memory[inst_counter] = new ADD(rs1, rs2, out_addr, rs1_addr, rs2_addr, data_memory);
        //cout << "inst: " << inst.name;
        //cout << "inst memory" << (*inst_memory[inst_counter]).name;
        //(*inst_memory[inst_counter]).execute();
        //cout << "inst mem out" << (*inst_memory[inst_counter]).get_out() << endl;
        //execute_inst(inst_memory[inst_counter]);

        inst_counter++;
    }
    else if (inst == "NEG")
    {
        int rs1, out_addr;
        bool rs1_addr;
        address o(out);
        out_addr = o.get_addr();
        if (linefields[0][0] == '$')
        {
            string z = linefields[0].substr(1, linefields[0].length() - 1);
            rs1 = atoi(z.c_str());
            rs1 = data_memory[rs1];
            rs1_addr = true;
        }

        else if (linefields[0][0] == '#')
        {
            string z = linefields[0].substr(1, linefields[0].length() - 1);
            rs1 = atoi(z.c_str());
            rs1_addr = false;
        }

        //NEG inst(rs1, out_addr);
        //inst.execute();
        inst_memory[inst_counter] = new NEG(rs1, out_addr, rs1_addr, data_memory);
        //execute_inst(inst_memory[inst_counter]);
        //data_memory[out_addr] = inst.get_out();
        //cout << "answer: " << data_memory[out_addr] << endl;
        //inst_memory[inst_counter] = &inst;
        inst_counter++;
    }
    else if (inst == "MUL")
    {
        int rs1, rs2, out_addr;
        bool rs1_addr, rs2_addr;
        address o(out);
        out_addr = o.get_addr();
        if (linefields[0][0] == '$')
        {
            string z = linefields[0].substr(1, linefields[0].length() - 1);
            rs1 = atoi(z.c_str());
            //rs1 = data_memory[rs1];
            rs1_addr = true;
        }

        else if (linefields[0][0] == '#')
        {
            string z = linefields[0].substr(1, linefields[0].length() - 1);
            rs1 = atoi(z.c_str());
            rs1_addr = false;
        }

        if (linefields[1][0] == '$')
        {
            string z = linefields[1].substr(1, linefields[1].length() - 1);
            rs2 = atoi(z.c_str());
            //rs2 = data_memory[rs2];
            rs2_addr = true;
        }

        else if (linefields[1][0] == '#')
        {
            string z = linefields[1].substr(1, linefields[1].length() - 1);
            rs2 = atoi(z.c_str());
            rs2_addr = false;
        }
        //MUL inst(rs1, rs2, out_addr);
        inst_memory[inst_counter] = new MUL(rs1, rs2, out_addr, rs1_addr, rs2_addr, data_memory);
        //execute_inst(inst_memory[inst_counter]);
        //inst_memory[inst_counter]->execute();
        //data_memory[out_addr] = inst_memory[inst_counter]->get_out();
        //data_memory[out_addr] = inst.get_out();
        //cout << "answer: " << data_memory[out_addr] << endl;
        //inst_memory[inst_counter] = inst;
        inst_counter++;
    }
    else if (inst == "JMP")
    {
        int out_addr;
        address o(out);
        out_addr = o.get_addr();
        inst_memory[inst_counter] = new JMP(out_addr);
        inst_counter++;
    }
    else if (inst == "JMP0")
    {
        int rs1, out_addr;
        bool rs1_addr;
        address o(out);
        out_addr = o.get_addr();
        if (linefields[0][0] == '$')
        {
            string z = linefields[0].substr(1, linefields[0].length() - 1);
            rs1 = atoi(z.c_str());
            //rs1 = data_memory[rs1];
            rs1_addr = true;
        }

        else if (linefields[0][0] == '#')
        {
            string z = linefields[0].substr(1, linefields[0].length() - 1);
            rs1 = atoi(z.c_str());
            rs1_addr = false;
        }
        inst_memory[inst_counter] = new JMP0(rs1, out_addr, rs1_addr, data_memory);
        inst_counter++;
    }
    else if (inst == "ASS")
    {
        int rs1, out_addr;
        bool rs1_addr;
        address o(out);
        out_addr = o.get_addr();
        if (linefields[0][0] == '$')
        {
            string z = linefields[0].substr(1, linefields[0].length() - 1);
            rs1 = atoi(z.c_str());
            //rs1 = data_memory[rs1];
            rs1_addr = true;
        }

        else if (linefields[0][0] == '#')
        {
            string z = linefields[0].substr(1, linefields[0].length() - 1);
            rs1 = atoi(z.c_str());
            rs1_addr = false;
        }

        inst_memory[inst_counter] = new ASS(rs1, out_addr, rs1_addr, data_memory);
        inst_counter++;
    }
    else if (inst == "LE")
    {
        int rs1, rs2, out_addr;
        bool rs1_addr, rs2_addr;
        address o(out);
        out_addr = o.get_addr();
        if (linefields[0][0] == '$')
        {
            string z = linefields[0].substr(1, linefields[0].length() - 1);
            rs1 = atoi(z.c_str());
            //rs1 = data_memory[rs1];
            rs1_addr = true;
        }

        else if (linefields[0][0] == '#')
        {
            string z = linefields[0].substr(1, linefields[0].length() - 1);
            rs1 = atoi(z.c_str());
            rs1_addr = false;
        }

        if (linefields[1][0] == '$')
        {
            string z = linefields[1].substr(1, linefields[1].length() - 1);
            rs2 = atoi(z.c_str());
            // rs2 = data_memory[rs2];
            rs2_addr = true;
        }

        else if (linefields[1][0] == '#')
        {
            string z = linefields[1].substr(1, linefields[1].length() - 1);
            rs2 = atoi(z.c_str());
            rs2_addr = false;
        }

        inst_memory[inst_counter] = new LE(rs1, rs2, out_addr, rs1_addr, rs2_addr, data_memory);
        inst_counter++;
    }
    else if (inst == "READ")
    {
        int out_addr;
        address o(out);
        out_addr = o.get_addr();
        inst_memory[inst_counter] = new READ(out_addr);
        inst_counter++;
    }
    else if (inst == "WRITE")
    {
        int out_addr;
        address o(out);
        out_addr = o.get_addr();
        //cout << "out_addr " << out_addr << endl;
        inst_memory[inst_counter] = new WRITE(out_addr, data_memory);
        inst_counter++;
    }
    else if (inst == "HALT")
    {
        inst_memory[inst_counter] = new HALT();
        inst_counter++;
    }
    else
    {
        cout << "invalid instruction " << endl;
    }
}

void SIM::execute_inst(instruction *inst)
{
    //cout << "in execute :" << inst.name << endl;

    //cout << inst->get_out();
    if (inst->name == "JMP")
    {
        inst->execute();
        if (inst->get_out() + 1 < inst_counter)
            PC = inst->get_out();
        else
        {
            cerr << "invalid jmp address" << endl; //basically doing nth
        }
    }
    else if (inst->name == "JMP0")
    {
        inst->execute();
        if (inst->get_out() + 1 < inst_counter)
        {
            if (inst->get_out() != -1)
                PC = inst->get_out();
        }
        else
        {
            cerr << "invalid jmp address" << endl; //basically doing nth
        }
    }
    else if (inst->name == "HALT")
    {
        inst->execute();
        PC = inst->get_out(); // PC jumps to address 1024 * out of bounds *
    }

    else if (inst->name == "WRITE")
    {
        inst->execute();
    }
    else
    {
        inst->execute();
        //cout << "answer : " << inst->get_out() << endl;
        data_memory[inst->get_out_addr()] = inst->get_out();
    }
    //cout << "answer" << data_memory[inst->get_out_addr()] << endl;
}

void SIM::test_inst(int n)
{

    //inst_memory[n].execute();
    //cout << "test inst out : " << inst_memory[n].get_out();
    //string r = inst_memory[0]->name;

    cout << inst_memory[n]->name
         << endl;
    //inst_memory[n]->execute();
    //cout << "inst out" << inst_memory[n]->get_out() << endl;
    //cout << inst_memory[n].get_out_addr() << endl;
}
void SIM::get_inst_counter()
{

    //inst_memory[n].execute();
    //cout << "test inst out : " << inst_memory[n].get_out();
    cout << inst_counter << endl;
}
void SIM::print_data_mem(int n)
{
    cout << "printing data memory until address " << n - 1 << " :\n";
    for (int i = 0; i < n; i++)
        cout << data_memory[i] << endl;
}

void SIM::execute_program()
{

    while (PC < inst_counter && PC != 1024)
    {
        cout << "executing inst @ " << PC << " the instruction is : " << inst_memory[PC]->name << endl;
        execute_inst(inst_memory[PC]);
        PC++;
    }
}
SIM::~SIM() {}