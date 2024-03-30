#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;

void thread()
{
	string song[64] = {
	"\nDashing through the snow",
	"In a one - horse open sleigh",
	"O'er the fields we go",
	"Laughing all the way",
	"\n",
	"\n",
	"\n",
	"\n",
	"Oh!Jingle bells, jingle bells",
	"Jingle all the way",
	"Oh, what fun it is to ride",
	"In a one - horse open sleigh, hey",
	"\n",
	"\n",
	"\n",
	"\n",
	"A day or two ago",
	"I thought I'd take a ride",
	"And soon, Miss Fanny Bright",
	"Was seated by my side",
	"\n",
	"\n",
	"\n",
	"\n",
	"Hey, jingle bells, jingle bells",
	"Jingle all the way",
	"Oh, what fun it is to ride",
	"In a one - horse open sleigh, hey",
	"\n",
	"\n",
	"\n",
	"\n",
	"A day or two ago",
	"The story I must tell",
	"I went out on the snow",
	"And on my back I fell",
	"\n",
	"\n",
	"\n",
	"\n",
	"Jingle bells, jingle bells",
	"Jingle all the way",
	"Oh, what fun it is to ride",
	"In a one - horse open sleigh, hey",
	"\n",
	"\n",
	"\n",
	"\n",
	"Now the ground is white",
	"Go it while you're young",
	"Take the girls tonight",
	"And sing this sleighing song",
	"\n",
	"\n",
	"\n",
	"\n",
	"Jingle bells, jingle bells",
	"Jingle all the way",
	"Oh, what fun it is to ride",
	"In a one - horse open sleigh, hey",
	"\n",
	"\n",
	"\n",
	"\n" };

	for (int i = 0; i < 63; i += 4) {
		cout << song[i] << endl;
		cout << song[i + 1] << endl;
		cout << song[i + 2] << endl;
		cout << song[i + 3] << endl;
		if (i + 4 > 63) i = 0;
		Sleep(2123);
	}

}

int main()
{
	setlocale(LC_ALL, "ru");
	HANDLE hProcess;
	hProcess = GetCurrentProcess();
	cout << "Parent process: " << endl << "The descriptor: " << hProcess << "\tPID: " << GetProcessId(hProcess) << endl;

	char consoleapp2[180] = "C:\\Users\\NoI\\Desktop\\ConsoleApplication2\\x64\\Debug\\ConsoleApplication2.exe";

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	si.dwFlags = STARTF_USESTDHANDLES;
	si.hStdInput = si.hStdOutput = si.hStdError = GetStdHandle(STD_OUTPUT_HANDLE);

	if (!CreateProcess(NULL, consoleapp2, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi)) {
		cout << "\nAn error occurred when starting a child process." << endl;
		return 1;
	}


	string str;
	getline(cin, str);

	cout << "\nChild process 1: " << endl << "The descriptor: " << pi.hProcess << "\tPID: " << pi.dwProcessId << endl;
	cout << "\nHello, " << str << endl;

	WaitForSingleObject(pi.hProcess, INFINITE);

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);





	char consoleapp3[180] = "C:\\Users\\NoI\\Desktop\\ConsoleApplication3\\x64\\Debug\\ConsoleApplication3.exe";

	string strToSend;
	cout << "\nPlease enter an integer, and it will turn into 4: ";
	getline(cin, strToSend);
	string commandLineArg = "\"" + strToSend + "\"";

	STARTUPINFO si2;
	PROCESS_INFORMATION pi2;

	ZeroMemory(&si2, sizeof(si2));
	si2.cb = sizeof(si2);
	si2.dwFlags = STARTF_USESTDHANDLES;
	si2.hStdInput = si2.hStdOutput = si2.hStdError = GetStdHandle(STD_OUTPUT_HANDLE);

	string commandLine = string(consoleapp3) + " " + commandLineArg;

	if (!CreateProcess(NULL, LPSTR(commandLine.c_str()), NULL, NULL, TRUE, 0, NULL, NULL, &si2, &pi2)) {
		cout << "\nAn error occurred when starting a child process." << endl;
		return 1;
	}

	cout << "\nChild process 2: " << endl << "The descriptor: " << pi2.hProcess << "\tPID: " << pi2.dwProcessId << endl;

	WaitForSingleObject(pi2.hProcess, INFINITE);

	CloseHandle(pi2.hProcess);
	CloseHandle(pi2.hThread);



	char consoleapp4[180] = "C:\\Users\\NoI\\Desktop\\ConsoleApplication4\\x64\\Debug\\ConsoleApplication4.exe ";
	char lpszHandle[20];

	STARTUPINFO si3;
	PROCESS_INFORMATION pi3;

	HANDLE hThread, hInheritThread;
	DWORD IDThread;

	hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread, NULL,
		0, &IDThread);

	if (hThread == NULL)
		return GetLastError();

	if (!DuplicateHandle(GetCurrentProcess(), hThread, GetCurrentProcess(), &hInheritThread,0, TRUE, DUPLICATE_SAME_ACCESS))
	{
		_cputs("\nThe stream was not duplicated.");
		_cputs("\nPress any button to complete.");
		_getch();
		return GetLastError();
	}

	ZeroMemory(&si3, sizeof(si3));
	si3.cb = sizeof(si3);
	si3.dwFlags = STARTF_USESTDHANDLES;
	si3.hStdInput = si3.hStdOutput = si3.hStdError = GetStdHandle(STD_OUTPUT_HANDLE);

	_itoa_s((int)hInheritThread, lpszHandle, 10);
	strcat_s(consoleapp4, lpszHandle);

	if (!CreateProcess(NULL, consoleapp4, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si3, &pi3))
	{
		_cputs("\nThe process was not created.");
		_cputs("\nPress any button to complete.");
		_getch();
		return GetLastError();
	}

	cout << "\nChild process 3: " << endl << "The descriptor: " << pi3.hProcess << "\tPID: " << pi3.dwProcessId << endl << endl;
	cout << "\nJingle Bells!" << endl;

	_getch();

	CloseHandle(pi3.hProcess);
	CloseHandle(pi3.hThread);
	CloseHandle(hThread);

	return 0;
}