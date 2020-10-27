// Thread.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

using namespace std;

int a[2];

DWORD WINAPI ThreadFun(LPVOID lpParam) {
	cout << "Thread running" << endl;

	int x, y, result;
	x = a[0];
	y = a[1];
	result = x + y;

	cout << "Sum numbers of massive is: "<< result << endl;

	return 0;

}

int main(){
	HANDLE hThread;
	DWORD ThreadID;
	//Masisve
	cout << "Enter first number: ";
	cin >> a[0];
	cout << "Enter second number: ";
	cin >> a[1];


	hThread = CreateThread(NULL, 0, ThreadFun, NULL, 0, &ThreadID);

	system("PAUSE");
	if (hThread == NULL) {
		cout << "Thread creation failed & Error no - " << GetLastError() << endl;
	}else {
		cout << "Thread creation success" << endl;

	}

	cout << "ThreadID -> " << ThreadID << endl;
	CloseHandle(hThread);


	system("PAUSE");
	return 0;

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
