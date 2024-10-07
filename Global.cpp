#include "Global.h"

using FLORENCE::FrameworkSpace::ServerSpace::GlobalSpace;

bool flag_write_IDLE[2] = { false, false };
bool flag_write_WAIT[2] = { false, false };
bool flag_write_WRITE[2] = { false, false };
bool flag_core_IDLE = false;
bool flag_core_ACTIVE = false;
unsigned char* ptr_num_Implemented_Cores = nullptr;

Global()
{
    bool false_core_ACTIVE = new bool(true);
    bool false_core_IDLE = new bool(false);
    unsigned char* ptr_num_Implemented_Cores = new unsigned char(4);//NUMBER OF CORES
    bool false_write_IDLE[2] = { bool(false), bool(false) };
    bool false_write_WAIT[2] = { bool(false), bool(true) };
    bool false_write_WRITE[2] = { bool(true), bool(false) };
}

~Global()
{
    delete ptr_num_Implemented_Cores;
}

bool getConst_Core_ACTIVE()
{
    return flag_core_ACTIVE;
}
bool getConst_Core_IDLE()
{
    return flag_core_IDLE;
}
unsigned char* get_NumCores()
{
    return ptr_num_Implemented_Cores;
}
bool getConst_Write_IDLE(unsigned char index)
{
    return flag_write_IDLE[index];
}
bool getConst_Write_WAIT(unsigned char index)
{
    return flag_write_WAIT[index];
}
bool getConst_Write_WRITE(unsigned char index)
{
    return flag_write_WRITE[index];
}