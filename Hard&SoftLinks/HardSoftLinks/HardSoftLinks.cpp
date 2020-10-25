// HardSoftLinks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

using namespace std;

int main(){
	BOOL bHFile;
	bHFile = CreateHardLink(
		L"C:\\SP\\HardLink.txt",
		L"C:\\SP\\File.txt",
		NULL
	);
	if (bHFile == FALSE) {
		cout << "Create hard link was failed & Error no = " << GetLastError() << endl;
	}else{
		cout << "Create hard link success" << endl;
	}

	bHFile = CreateSymbolicLink(
		L"C:\\SP\\SymbolicLink.txt",
		L"C:\\SP\\File.txt",
		0
	);
	if (bHFile == FALSE) {
		cout << "Create symbolic link failde & Error no = " << GetLastError() << endl;
	}else {
		cout << "Create symbolic link success" << endl;

	}
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
