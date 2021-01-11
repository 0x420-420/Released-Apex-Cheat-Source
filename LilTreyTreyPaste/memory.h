#pragma once

#include "utils.h"
#include <cstdint>
#include <Windows.h>
#include <TlHelp32.h>
#include "utils.h"



DWORD ProcessID(const char* ProcessName)
{


	HANDLE SnapShot = (CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0));
	if (SnapShot != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 PIDENTRY;
		PIDENTRY.dwSize = sizeof(PIDENTRY);
		if (Process32First(SnapShot, &PIDENTRY))
		{
			do
			{
				if (!strcmp(PIDENTRY.szExeFile,ProcessName))
				{
					variables::PID = PIDENTRY.th32ProcessID;
					break;
				}

			} while (Process32Next(SnapShot, &PIDENTRY));
		}
	}

	CloseHandle(SnapShot);

	return variables::PID;
}

