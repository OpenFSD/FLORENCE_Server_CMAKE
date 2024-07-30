#include "LaunchConcurrency.h"

class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency = nullptr;

FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrency::LaunchConcurrency(
    class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global,
    unsigned char* ptr_MyNumImplementedCores
)
{
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency = new class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency(ptr_Global, ptr_MyNumImplementedCores);
    while (ptr_Control_Of_LaunchConcurrency == nullptr) { /* wait untill created */ }
}

FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrency::~LaunchConcurrency()
{
    delete ptr_Control_Of_LaunchConcurrency;
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrency::concurrent_Thread_Start(
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
    unsigned char* ptr_concurrent_CoreId,
    class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global,
    unsigned char* ptr_NumImplementedCores
)
{
    ptr_Control_Of_LaunchConcurrency->launchEnable_Request(ptr_Control_Of_LaunchConcurrency, ptr_concurrent_CoreId, ptr_Global);
    ptr_Control_Of_LaunchConcurrency->launchQue_Update(ptr_Control_Of_LaunchConcurrency, ptr_NumImplementedCores);
    ptr_Control_Of_LaunchConcurrency->launchEnable_SortQue(ptr_Control_Of_LaunchConcurrency, ptr_Global, ptr_NumImplementedCores);
    ptr_Control_Of_LaunchConcurrency->launchEnable_Activate(ptr_Control_Of_LaunchConcurrency, ptr_Global);
    ptr_Control_Of_LaunchConcurrency->launchQue_Update(ptr_Control_Of_LaunchConcurrency, ptr_NumImplementedCores);
    ptr_Control_Of_LaunchConcurrency->launchEnable_SortQue(ptr_Control_Of_LaunchConcurrency, ptr_Global, ptr_NumImplementedCores);
    ptr_Control_Of_LaunchConcurrency->setFlag_PraisingLaunch(false);
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrency::thread_End(
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
    unsigned char* ptr_concurrent_CoreId,
    class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global
)
{
    while (ptr_Control_Of_LaunchConcurrency->getFlag_PraisingLaunch() == true)
    {

    }
    ptr_Control_Of_LaunchConcurrency->setFlag_PraisingLaunch(true);
    ptr_Control_Of_LaunchConcurrency->set_concurrent_CoreId_Index(*ptr_Control_Of_LaunchConcurrency->get_new_concurrent_CoreId_Index());
    if (*ptr_Control_Of_LaunchConcurrency->get_concurrent_CoreId_Index() == *ptr_concurrent_CoreId)
    {
        ptr_Control_Of_LaunchConcurrency->setFlag_ConcurrentCoreState(ptr_concurrent_CoreId, ptr_Global->getConst_Core_IDLE());
    }
    else
    {
        ptr_Control_Of_LaunchConcurrency->set_new_concurrent_CoreId_Index(*ptr_Control_Of_LaunchConcurrency->get_concurrent_CoreId_Index() + 1);

        if (*ptr_Control_Of_LaunchConcurrency->get_new_concurrent_CoreId_Index() == 3)//NUMBER OF CONCURNT CORES
        {
            ptr_Control_Of_LaunchConcurrency->set_new_concurrent_CoreId_Index(0);
        }
        ptr_Control_Of_LaunchConcurrency->setFlag_PraisingLaunch(false);
        thread_End(
            ptr_Control_Of_LaunchConcurrency,
            ptr_concurrent_CoreId,
            ptr_Global
        );
    }
}

class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrency::get_Control_Of_LaunchConcurrency()
{
    return ptr_Control_Of_LaunchConcurrency;
}