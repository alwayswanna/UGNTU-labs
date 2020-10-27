// ProcessThreads.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

using namespace std;

int main(){
	HANDLE hProcess;
	HANDLE hThread;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	DWORD dwProcessId = 0;
	DWORD dwThreadId = 0;

	ZeroMemory(&si, sizeof(si));
	ZeroMemory(&pi, sizeof(pi));


	BOOL bCreateProcess = CreateProcess(L"C:\\Windows\\System32\\calc.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
	if (bCreateProcess == FALSE){
			cout << "Create process failed & Error no - " << GetLastError() << endl;
		}else{
			cout << "Create process success" << endl;
			cout << "Process ID -> " << pi.dwProcessId << endl;
			cout << "Thread ID -> " << pi.dwThreadId << endl;
			cout << "GetProcess Id -> " << GetProcessId(pi.hProcess) << endl;
			cout << "GetThread Id -> " << GetThreadId(pi.hThread) << endl;

				WaitForSingleObject(pi.hProcess, INFINITE);
				CloseHandle(pi.hThread);
				CloseHandle(pi.hProcess);

			system("PAUSE");
				return 0;
		}
	}

