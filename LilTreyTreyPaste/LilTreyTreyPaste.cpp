

#include <iostream>
#include "utils.h"
#include "memory.h"
#include <thread>
#include "terrydriver.h"
#include "Functions.h"

mappedFileStruct mappedFile;
communicationStruct geo;






int main()
{
    variables::PID = ProcessID("r5apex.exe");

    SetConsoleTitleA("Terry Ware 1.0");
    printf("[-] Starting Paste\n");


    std::wstring l_Path = (L"\\.\PhysicalDrive0");

    mappedFile.hMappedFile = CreateFile2(l_Path.c_str(), GENERIC_READ | GENERIC_WRITE, 0, OPEN_EXISTING, NULL);

    bool l_ControlCheck = Driver::driverControl(CleanTraces);      // clean traces

    while (!variables::PID);
    {
        printf("[-] Start r5apex.exe\n");

        variables::PID = ProcessID("r5apex.exe");

    }

    std::cout << ("[+]Found Process Id -> ") << variables::PID << std::endl;
    //variables::Process = OpenProcess(PROCESS_ALL_ACCESS, NULL, variables::PID);

    variables::ModuleBase = Driver::initProcessContext(variables::PID, L"r5apex.exe", sizeof(L"r5apex.exe"), GetCurrentProcessId(),
        L"Nigger.exe", sizeof(L"Nigger.exe"));

    printf("[+] ModuleBase -> 0x%x\n", variables::ModuleBase);
    EntityLoop();



}

