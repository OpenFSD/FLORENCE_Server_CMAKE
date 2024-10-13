#include "Global.h"

namespace FLORENCE::FrameworkSpace::ServerSpace
{
    bool Global::flag_write_IDLE[2] = { NULL, NULL };
    bool Global::flag_write_WAIT[2] = { NULL, NULL };
    bool Global::flag_write_WRITE[2] = { NULL, NULL };
    bool Global::flag_core_IDLE = NULL;
    bool Global::flag_core_ACTIVE = NULL;
    unsigned char Global::ptr_num_Implemented_Cores = NULL;

    Global::Global()
    {
        this->false_core_ACTIVE = new bool(true);
        this->false_core_IDLE = new bool(false);
        this->ptr_num_Implemented_Cores = new unsigned char(4);//NUMBER OF CORES
        this->false_write_IDLE[2] = { bool(false), bool(false) };
        this->false_write_WAIT[2] = { bool(false), bool(true) };
        this->false_write_WRITE[2] = { bool(true), bool(false) };
    }

    Global::~Global()
    {
        delete ptr_num_Implemented_Cores;
    }

    bool Global::getConst_Core_ACTIVE()
    {
        return flag_core_ACTIVE;
    }
    bool Global::getConst_Core_IDLE()
    {
        return flag_core_IDLE;
    }
    unsigned char* Global::get_NumCores()
    {
        return ptr_num_Implemented_Cores;
    }
    bool Global::getConst_Write_IDLE(unsigned char index)
    {
        return flag_write_IDLE[index];
    }
    bool Global::getConst_Write_WAIT(unsigned char index)
    {
        return flag_write_WAIT[index];
    }
    bool Global::getConst_Write_WRITE(unsigned char index)
    {
        return flag_write_WRITE[index];
    }
}