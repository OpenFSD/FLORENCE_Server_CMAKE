#pragma once
#include "Global.h"

namespace FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace
{
    unsigned char* Control_Of_WriteEnable::ptr_coreId_For_WritePraise_Index = NULL;
    int* Control_Of_WriteEnable::ptr_count_CoreId_WriteActive[4] = { NULL, NULL, NULL, NULL };//NUMBER OF CORES
    int* Control_Of_WriteEnable::ptr_count_CoreId_WriteIdle[4] = { NULL, NULL, NULL, NULL };//NUMBER OF CORES
    int* Control_Of_WriteEnable::ptr_count_CoreId_WriteWait[4] = { NULL, NULL, NULL, NULL };//NUMBER OF CORES
    bool Control_Of_WriteEnable::flag_WriteState[4][2] = { bool(false), bool(false), bool(false), bool(false), bool(false), bool(false), bool(false), bool(false) };//NUMBER OF CORES
    unsigned char* Control_Of_WriteEnable::ptr_new_coreId_For_WritePraise_Index = NULL;
    bool Control_Of_WriteEnable::praisingWrite = bool(false);
    unsigned char* Control_Of_WriteEnable::ptr_que_CoreToWrite[4] = { NULL, NULL, NULL, NULL };//NUMBER OF CORES

    class Control_Of_WriteEnable
    {
        static unsigned char* Control_Of_WriteEnable::ptr_coreId_For_WritePraise_Index;
        static int* Control_Of_WriteEnable::ptr_count_CoreId_WriteActive[4];//NUMBER OF CORES
        static int* Control_Of_WriteEnable::ptr_count_CoreId_WriteIdle[4];//NUMBER OF CORES
        static int* Control_Of_WriteEnable::ptr_count_CoreId_WriteWait[4];//NUMBER OF CORES
        static bool Control_Of_WriteEnable::flag_WriteState[4][2];//NUMBER OF CORES
        static unsigned char* Control_Of_WriteEnable::ptr_new_coreId_For_WritePraise_Index;
        static bool Control_Of_WriteEnable::praisingWrite;
        static unsigned char* Control_Of_WriteEnable::ptr_que_CoreToWrite[4];//NUMBER OF CORES

    public:
        Control_Of_WriteEnable(
            FLORENCE::Framework::Server::Global* ptr_Global,
            unsigned char* ptr_MyNumImplementedCores
        );
        ~Control_Of_WriteEnable();
        void writeEnable_Activate(
            unsigned char* ptr_coreId,
            FLORENCE::Framework::Server::Global* ptr_Global,
            unsigned char* ptr_MyNumImplementedCores
        );
        void Control_Of_WriteEnable::writeEnable_SortQue(
            unsigned char* ptr_MyNumImplementedCores,
            FLORENCE::Framework::Server::Global* ptr_Global
        );
        void Control_Of_WriteEnable::writeEnable_Request(
            unsigned char* ptr_coreId,
            unsigned char* ptr_MyNumImplementedCores,
            FLORENCE::Framework::Server::Global* ptr_Global
        );
        void Control_Of_WriteEnable::writeQue_Update(
            unsigned char* ptr_MyNumImplementedCores
        );

        unsigned char* Control_Of_WriteEnable::get_coreIdForWritePraiseIndex();
        int* Control_Of_WriteEnable::get_count_WriteActive(unsigned char* ptr_coreId);
        int* Control_Of_WriteEnable::get_count_WriteIdle(unsigned char* ptr_coreId);
        int* Control_Of_WriteEnable::get_count_WriteWait(unsigned char* ptr_coreId);
        unsigned char* Control_Of_WriteEnable::getFlag_CoreId_WriteEnable();
        unsigned char* Control_Of_WriteEnable::get_new_coreIdForWritePraiseIndex();
        unsigned char* Control_Of_WriteEnable::get_que_CoreToWrite(unsigned char* ptr_coreId);

        void Control_Of_WriteEnable::set_count_WriteActive(unsigned char* ptr_coreId, int value);
        void Control_Of_WriteEnable::set_count_WriteIdle(unsigned char* ptr_coreId, int value);
        void Control_Of_WriteEnable::set_count_WriteWait(unsigned char* ptr_coreId, int value);
        void Control_Of_WriteEnable::setFlag_readWrite_Open(bool value);
        void Control_Of_WriteEnable::setFlag_writeState(unsigned char* ptr_coreId, unsigned char index, bool value);
        void Control_Of_WriteEnable::set_new_coreIdForWritePraiseIndex(unsigned char value);
        void Control_Of_WriteEnable::set_que_CoreToWrite(unsigned char* index, unsigned char value);

    protected:

    private:
        void Control_Of_WriteEnable::dynamicStagger(
            unsigned char* ptr_coreId
        );
        void Control_Of_WriteEnable::writeEnable_ShiftQueValues(
            unsigned char* concurrent_CoreId_A,
            unsigned char* concurrent_CoreId_B
        );

        bool Control_Of_WriteEnable::getFlag_readWrite_Open();
        bool Control_Of_WriteEnable::getFlag_writeState(unsigned char* ptr_coreId, unsigned char index);

        void Control_Of_WriteEnable::set_coreIdForWritePraiseIndex(unsigned char value);        
    };
}