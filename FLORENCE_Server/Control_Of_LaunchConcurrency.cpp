#include "Control_Of_LaunchConcurrency.h"

unsigned char* ptr_concurrent_CoreId_Index = nullptr;
int* ptr_count_LaunchActive_For[3] = { nullptr, nullptr, nullptr };//NUMBER OF CONCURNT CORES
int* ptr_count_LaunchIdle_For[3] = { nullptr, nullptr, nullptr };//NUMBER OF CONCURNT CORES
bool flag_ConcurrentCoreState[3] = { false, false, false };//NUMBER OF CONCURRENT CORES
unsigned char* ptr_new_concurrent_CoreId_Index = nullptr;
bool flag_praisingLaunch = false;
unsigned char* ptr_que_CoreToLaunch[3] = { nullptr, nullptr, nullptr };//NUMBER OF CONCURRENT CORES

FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::Control_Of_LaunchConcurrency(
    FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global,
    unsigned char* ptr_NumImplementedCores
)
{
    unsigned char* ptr_concurrent_CoreId_Index = new unsigned char(0);
    int* ptr_count_LaunchActive_For[3] = { new int(0), new int(0), new int(0) };//NUMBER OF CONCURNT CORES
    int* ptr_count_LaunchIdle_For[3] = { new int(0), new int(0), new int(0) };//NUMBER OF CONCURNT CORES
    bool flag_ConcurrentCoreState[3] = { bool(false), bool(false), bool(false) };//NUMBER OF CONCURNT CORES
    unsigned char* ptr_new_concurrent_CoreId_Index = new unsigned char(0);
    bool flag_praisingLaunch = false;
    unsigned char* ptr_que_CoreToLaunch[3] = { new unsigned char(0), new unsigned char(0), new unsigned char(0) };//NUMBER OF CONCURNT CORES
}

FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::~Control_Of_LaunchConcurrency()
{
    delete ptr_concurrent_CoreId_Index;
    for (int index = 0; index < 3; index++)
    {
        delete ptr_count_LaunchActive_For[index];
        delete ptr_count_LaunchIdle_For[index];
        delete ptr_que_CoreToLaunch[index];
    }//NUMBER OF CONCURRENT CORES
    delete ptr_new_concurrent_CoreId_Index;
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::launchEnable_Activate(
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
    class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global
)
{
    ptr_Control_Of_LaunchConcurrency->setFlag_ConcurrentCoreState(ptr_Control_Of_LaunchConcurrency->getFlag_CoreId_Of_CoreToLaunch(), ptr_Global->getConst_Core_ACTIVE());
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::launchEnable_Request(
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
    unsigned char* concurrent_CoreId,
    class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global
)
{
    while (ptr_Control_Of_LaunchConcurrency->getFlag_ConcurrentCoreState(ptr_Control_Of_LaunchConcurrency->getFlag_CoreId_Of_CoreToLaunch()) != ptr_Global->getConst_Core_IDLE())
    {

    }
    while (ptr_Control_Of_LaunchConcurrency->getFlag_PraisingLaunch() == true)
    {

    }
    ptr_Control_Of_LaunchConcurrency->setFlag_PraisingLaunch(true);
    ptr_Control_Of_LaunchConcurrency->set_concurrent_CoreId_Index(*ptr_Control_Of_LaunchConcurrency->get_new_concurrent_CoreId_Index());
    if (*get_concurrent_CoreId_Index() == *concurrent_CoreId)
    {

    }
    else
    {
        ptr_Control_Of_LaunchConcurrency->set_new_concurrent_CoreId_Index(*ptr_Control_Of_LaunchConcurrency->get_concurrent_CoreId_Index() + 1);
        if (*ptr_Control_Of_LaunchConcurrency->get_concurrent_CoreId_Index() == 3)
        {
            ptr_Control_Of_LaunchConcurrency->set_new_concurrent_CoreId_Index(0);
        }
        ptr_Control_Of_LaunchConcurrency->setFlag_PraisingLaunch(false);
        ptr_Control_Of_LaunchConcurrency->launchEnable_Request(
            ptr_Control_Of_LaunchConcurrency,
            concurrent_CoreId,
            ptr_Global
        );
    }
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::launchEnable_SortQue(
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
    class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global,
    unsigned char* ptr_NumImplementedCores
)
{
    for (unsigned char index_A = 0; index_A < *ptr_NumImplementedCores - 2; index_A++)
    {
        for (unsigned char index_B = index_A + 1; index_B < *ptr_NumImplementedCores - 1; index_B++)
        {
            if (ptr_Control_Of_LaunchConcurrency->getFlag_ConcurrentCoreState(ptr_Control_Of_LaunchConcurrency->get_que_CoreToLaunch(&index_A)) == ptr_Global->getConst_Core_ACTIVE())
            {
                if (ptr_Control_Of_LaunchConcurrency->getFlag_ConcurrentCoreState(ptr_Control_Of_LaunchConcurrency->get_que_CoreToLaunch(&index_B)) == ptr_Global->getConst_Core_IDLE())
                {
                    ptr_Control_Of_LaunchConcurrency->launchEnable_ShiftQueValues(ptr_Control_Of_LaunchConcurrency, &index_A, &index_B);
                }
                else if (ptr_Control_Of_LaunchConcurrency->getFlag_ConcurrentCoreState(ptr_Control_Of_LaunchConcurrency->get_que_CoreToLaunch(&index_B)) == ptr_Global->getConst_Core_ACTIVE())
                {
                    if (ptr_Control_Of_LaunchConcurrency->get_count_LaunchActive_For(&index_A) > ptr_Control_Of_LaunchConcurrency->get_count_LaunchActive_For(&index_B))
                    {
                        ptr_Control_Of_LaunchConcurrency->launchEnable_ShiftQueValues(ptr_Control_Of_LaunchConcurrency, &index_A, &index_B);
                    }
                }
            }
            else if (ptr_Control_Of_LaunchConcurrency->getFlag_ConcurrentCoreState(ptr_Control_Of_LaunchConcurrency->get_que_CoreToLaunch(&index_A)) == ptr_Global->getConst_Core_IDLE())

                if (ptr_Control_Of_LaunchConcurrency->getFlag_ConcurrentCoreState(ptr_Control_Of_LaunchConcurrency->get_que_CoreToLaunch(&index_B)) == ptr_Global->getConst_Core_IDLE())
                {
                    if (ptr_Control_Of_LaunchConcurrency->get_count_LaunchIdle_For(&index_A) < ptr_Control_Of_LaunchConcurrency->get_count_LaunchIdle_For(&index_B))
                    {
                        ptr_Control_Of_LaunchConcurrency->launchEnable_ShiftQueValues(ptr_Control_Of_LaunchConcurrency, &index_A, &index_B);
                    }
                }
        }
    }
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::launchQue_Update(
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
    unsigned char* ptr_NumImplementedCores
)
{
    for (unsigned char index = 0; index < *ptr_NumImplementedCores; index++)
    {
        switch (ptr_Control_Of_LaunchConcurrency->getFlag_ConcurrentCoreState(&index))
        {
        case false:
        {
            ptr_Control_Of_LaunchConcurrency->set_count_LaunchActive_For(&index, 0);
            ptr_Control_Of_LaunchConcurrency->set_count_LaunchIdle_For(&index, *ptr_Control_Of_LaunchConcurrency->get_count_LaunchIdle_For(&index) + 1);
            break;
        }
        case true:
        {
            ptr_Control_Of_LaunchConcurrency->set_count_LaunchActive_For(&index, *ptr_Control_Of_LaunchConcurrency->get_count_LaunchActive_For(&index) + 1);
            ptr_Control_Of_LaunchConcurrency->set_count_LaunchIdle_For(&index, 0);
            break;
        }
        }
    }
}

unsigned char* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::get_concurrent_CoreId_Index()
{
    return ptr_concurrent_CoreId_Index;
}

bool FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::getFlag_ConcurrentCoreState(unsigned char* concurrent_CoreId)
{
    return flag_ConcurrentCoreState[*concurrent_CoreId];
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::setFlag_PraisingLaunch(bool value)
{
    flag_praisingLaunch = value;
}

unsigned char* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::get_new_concurrent_CoreId_Index()
{
    return ptr_new_concurrent_CoreId_Index;
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::set_concurrent_CoreId_Index(unsigned char value)
{
    ptr_concurrent_CoreId_Index = &value;
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::setFlag_ConcurrentCoreState(unsigned char* concurrent_CoreId, bool value)
{
    flag_ConcurrentCoreState[*concurrent_CoreId] = &value;
}


bool FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::getFlag_PraisingLaunch()
{
    return flag_praisingLaunch;
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::set_new_concurrent_CoreId_Index(unsigned char value)
{
    ptr_new_concurrent_CoreId_Index = &value;
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::dynamicStagger(
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
    unsigned char* ptr_coreId
)
{
    if (*ptr_Control_Of_LaunchConcurrency->get_concurrent_CoreId_Index() == *ptr_coreId)
    {
        //exit early
    }
    else
    {
        int* ptr_count = new int(0);
        while (*ptr_count < 20)//todo time till flag change
        {

            ptr_count = ptr_count + 1;
        }
        delete ptr_count;
    }
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::launchEnable_ShiftQueValues(
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
    unsigned char* concurrent_CoreId_A,
    unsigned char* concurrent_CoreId_B
)
{
    int* ptr_temp_Int = new int(0);
    ptr_temp_Int = ptr_Control_Of_LaunchConcurrency->get_count_LaunchActive_For(concurrent_CoreId_A);
    ptr_Control_Of_LaunchConcurrency->set_count_LaunchActive_For(concurrent_CoreId_A, *ptr_Control_Of_LaunchConcurrency->get_count_LaunchActive_For(concurrent_CoreId_B));
    ptr_Control_Of_LaunchConcurrency->set_count_LaunchActive_For(concurrent_CoreId_B, *ptr_temp_Int);

    ptr_temp_Int = ptr_Control_Of_LaunchConcurrency->get_count_LaunchIdle_For(concurrent_CoreId_A);
    ptr_Control_Of_LaunchConcurrency->set_count_LaunchIdle_For(concurrent_CoreId_A, *ptr_Control_Of_LaunchConcurrency->get_count_LaunchIdle_For(concurrent_CoreId_B));
    ptr_Control_Of_LaunchConcurrency->set_count_LaunchIdle_For(concurrent_CoreId_B, *ptr_temp_Int);
    delete ptr_temp_Int;

    unsigned char* ptr_temp_UnnsignedChar = new unsigned char(0);
    ptr_temp_UnnsignedChar = ptr_Control_Of_LaunchConcurrency->get_que_CoreToLaunch(concurrent_CoreId_A);
    ptr_Control_Of_LaunchConcurrency->set_que_CoreToLaunch(concurrent_CoreId_A, *ptr_Control_Of_LaunchConcurrency->get_que_CoreToLaunch(concurrent_CoreId_B));
    ptr_Control_Of_LaunchConcurrency->set_que_CoreToLaunch(concurrent_CoreId_B, *ptr_temp_UnnsignedChar);
    delete ptr_temp_UnnsignedChar;
}

int* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::get_count_LaunchActive_For(unsigned char* concurrent_CoreId)
{
    return ptr_count_LaunchActive_For[*concurrent_CoreId];
}

int* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::get_count_LaunchIdle_For(unsigned char* concurrent_CoreId)
{
    return ptr_count_LaunchIdle_For[*concurrent_CoreId];
}

unsigned char* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::getFlag_CoreId_Of_CoreToLaunch()
{
    return ptr_que_CoreToLaunch[0];
}

unsigned char* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::get_que_CoreToLaunch(unsigned char* concurrent_CoreId)
{
    return ptr_que_CoreToLaunch[*concurrent_CoreId];
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::set_count_LaunchActive_For(unsigned char* concurrent_CoreId, int value)
{
    ptr_count_LaunchActive_For[*concurrent_CoreId] = &value;
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::set_count_LaunchIdle_For(unsigned char* concurrent_CoreId, int value)
{
    ptr_count_LaunchIdle_For[*concurrent_CoreId] = &value;
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::set_que_CoreToLaunch(unsigned char* concurrent_CoreId, unsigned char value)
{
    ptr_que_CoreToLaunch[*concurrent_CoreId] = &value;
}