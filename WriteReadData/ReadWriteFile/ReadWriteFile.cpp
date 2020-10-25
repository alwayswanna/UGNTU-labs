// ReadWriteFile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <Windows.h>
#include <iostream>

using namespace std;

int main(){
    HANDLE hFile;
    BOOL bfile;
    char chBuffer[] = "Program for write and read API";
    DWORD dwNoByteToWrite = strlen(chBuffer);
    DWORD dwNoByteWriten = 0;
    DWORD dwNoByteToRead = strlen(chBuffer);
    DWORD dwNoByteRead = 0;
    hFile = CreateFile(
        L"C:\\SP\\File.txt",
        GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_READ,
        NULL,
        CREATE_NEW,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );
    if (hFile == INVALID_HANDLE_VALUE){
        cout << "Create file failed & Error no = " << GetLastError() << endl;
    }else {
        cout << "Create file success" << endl;
    }
    
    bfile = WriteFile(
        hFile,
        chBuffer,
        dwNoByteToWrite,
        &dwNoByteWriten,
        NULL
    );
    if (bfile == FALSE) {
        cout << "Write file failed & Error no = " << GetLastError() << endl;
    }else {
        cout << "Write file success" << endl;
    }

    bfile = ReadFile(
        hFile,
        chBuffer,
        dwNoByteToRead,
        &dwNoByteRead,
        NULL
    );
    if (bfile == FALSE) {
        cout << "Read file & Error no = " << GetLastError() << endl;
    }else {
        cout << "Read file success" << endl;
    }
    cout << "Data read from file: " << chBuffer << endl;
    CloseHandle(hFile);
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
