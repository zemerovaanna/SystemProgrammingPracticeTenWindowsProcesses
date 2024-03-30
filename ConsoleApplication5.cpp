#include <iostream>
#include <windows.h>
#include <conio.h> 
using namespace std;

DWORD WINAPI Summing(LPVOID param) {
	int a = (int)param;
	for (int i = 1; i < a + 1; i++) {
		a = a + i;
	}
	cout << "The result of the thread:" << a << endl;
	cout << "The summation thread is completed." << endl;
	return 0;
}

DWORD WINAPI Multiplying(LPVOID param) {
	int a = (int)param;
	for (int i = 1; i < a + 1; i++) {
		a = a * i;
	}
	cout << "The result of the thread:" << a << endl;
	cout << "The multiplication thread is complete." << endl;
	return 0;
}

DWORD WINAPI Substracting(LPVOID param) {
	int a = (int)param;
	for (int i = 1; i < a + 1; i++) {
		a = a / i;
	}
	cout << "The result of the thread:" << a << endl;
	cout << "The subtraction flow is complete." << endl;
	return 0;
}

DWORD WINAPI Dividing(LPVOID param) {
	int a = (int)param;
	for (int i = 1; i < a + 1; i++) {
		a = a - i;
	}
	cout << "The result of the thread:" << a << endl;
	cout << "The division thread is complete." << endl;
	return 0;
}

int main(int argc, char* argv[]) {

	HANDLE hThread, hProcess;
	hThread = (HANDLE)atoi(argv[1]);

	int a;

	cout << "Please enter an integer to be processed by the thread:"; //Пожалуйста, введите целое число для обработки потоком: 
	cin >> a;
	cout << endl;

	bool end = false;

	do {
		HANDLE hThread1, hThread2, hThread3, hThread4;

		char input;
		cout << "Select an action:" << endl;
		cout << "1 - Summing a number with all the numbers before it." << endl;
		cout << "2 - Multiplying a number with all the numbers before it." << endl;
		cout << "3 - Subtracting a number with all the numbers before it." << endl;
		cout << "4 - Dividing a number with all the numbers before it." << endl;
		cout << "0 - Leave thread control." << endl;
		cin >> input;

		if (!isdigit(input)) {
			input = NULL;
			cout << "\nNo number entered.";
		}
		else {
				int action = input - '0';
				switch (action)
				{
				case 0:
				{
					cout << "\nYou are leaving the thread control." << endl;
					end = true;
					break;
				}
				case 1:
				{
					cout << "\nStarting the Summing thread." << endl;
					hThread1 = CreateThread(NULL, 0, Summing, (LPVOID)a, 0, NULL);
					if (hThread1 == NULL) {
						return GetLastError();
					}
					WaitForSingleObject(hThread1, INFINITE);
					CloseHandle(hThread1);
					break;
				}
				case 2:
				{
					cout << "\nStarting the Multiplying thread." << endl;
					hThread2 = CreateThread(NULL, 0, Multiplying, (LPVOID)a, 0, NULL);
					if (hThread2 == NULL) {
						return GetLastError();
					}
					WaitForSingleObject(hThread2, INFINITE);
					CloseHandle(hThread2);
					break;
				}
				case 3:
				{
					cout << "\nStarting the Substracting thread." << endl;
					hThread3 = CreateThread(NULL, 0, Substracting, (LPVOID)a, 0, NULL);
					if (hThread3 == NULL) {
						return GetLastError();
					}
					WaitForSingleObject(hThread3, INFINITE);
					CloseHandle(hThread3);
					break;
				}
				case 4:
				{
					cout << "\nStarting the Dividing thread." << endl;
					hThread4 = CreateThread(NULL, 0, Dividing, (LPVOID)a, 0, NULL);
					if (hThread4 == NULL) {
						return GetLastError();
					}
					WaitForSingleObject(hThread4, INFINITE);
					CloseHandle(hThread4);
					break;
				}
				default:
				{
					cout << "\nAn unacceptable action." << endl;
					break;
				}
			}
		}

	} while (!end);

	char c;

	while (true)
	{
		_cputs("\nType 't' to end the inherited thread: ");
		c = _getch();
		if (c == 't')
		{
			_cputs("t\n");
			break;
		}
	}

	TerminateThread(hThread, 0);
	CloseHandle(hThread);
	_cputs("Press any key to exit.\n");
	_getch();


	return 0;
}