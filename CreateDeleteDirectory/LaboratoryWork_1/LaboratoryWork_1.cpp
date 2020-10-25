// LaboratoryWork_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <Windows.h>

using namespace std;


int main()
{
    BOOL bDir;
    bDir = CreateDirectory(L"C:\\SP", NULL);
    if (bDir ==  FALSE){
        cout << "Create Directory Failed & Error no - " << GetLastError() << endl;
    }else{
        std::cout << "CreateDirectory Success\n";
    }
    bDir = RemoveDirectory(L"C:\\SP");
    if (bDir == FALSE) {
        cout << "Remove Directory Failed & Error no - " << GetLastError() << endl;
    }else{
        std::cout << "Remove Directory Success\n";
    }

}

