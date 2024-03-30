#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

void thread() {
    string song[64] = {
    "\n\n",
    "\n",
    "\n",
    "\n",
    "Bells on bobtails ring",
    "Making spirits bright",
    "What fun it is to ride and sing",
    "A sleighing song tonight",
    "\n",
    "\n",
    "\n",
    "\n",
    "Jingle bells, jingle bells",
    "Jingle all the way",
    "Oh, what fun it is to ride",
    "In a one - horse open sleigh",
    "\n",
    "\n",
    "\n",
    "\n",
    "The horse was lean and lank",
    "Misfortune seemed his lot",
    "He got into a drifted bank",
    "And then we got upsot",
    "\n",
    "\n",
    "\n",
    "\n",
    "Jingle bells, jingle bells",
    "Jingle all the way",
    "Oh, what fun it is to ride",
    "In a one - horse open sleigh",
    "\n",
    "\n",
    "\n",
    "\n",
    "A gent was riding by",
    "In a one - horse open sleigh",
    "He laughed as there I sprawling lie",
    "But quickly drove away",
    "\n",
    "\n",
    "\n",
    "\n",
    "Jingle bells, jingle bells",
    "Jingle all the way",
    "Oh, what fun it is to ride",
    "In a one - horse open sleigh",
    "\n",
    "\n",
    "\n",
    "\n",
    "Just get a bobtailed bay",
    "Two forty as his speed",
    "Hitch him to an open sleigh",
    "And crack, you'll take the lead",
    "\n",
    "\n",
    "\n",
    "\n",
    "Jingle bells, jingle bells",
    "Jingle all the way",
    "Oh, what fun it is to ride",
    "In a one - horse open sleigh" };

    for (int i = 0; i < 63; i += 4) {
        cout << song[i] << endl;
        cout << song[i + 1] << endl;
        cout << song[i + 2] << endl;
        cout << song[i + 3] << endl;
        if (i + 4 > 63) i = 0;
        Sleep(2123);
    }
}

int main(int argc, char* argv[])
{
    HANDLE hProcess = GetCurrentProcess();
    
    cout << "\nProcess: " << hProcess << "\tPID: " << GetProcessId(hProcess) << endl;

    HANDLE hThread;
    hThread = (HANDLE)atoi(argv[1]);

    DWORD IDThread;

    char consoleapp5[180] = "C:\\Users\\NoI\\Desktop\\ConsoleApplication5\\x64\\Debug\\ConsoleApplication5.exe ";

    char lpszHandle2[20];

    STARTUPINFO si4;
    PROCESS_INFORMATION pi4;
    HANDLE hThread5 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread, NULL, 0, &IDThread);


    if (!SetHandleInformation( hThread5, HANDLE_FLAG_INHERIT, HANDLE_FLAG_INHERIT))
    {
        _cputs("\nInheritance failed.");
        _cputs("\nTap any key to complete.");
        _getch();
        return GetLastError();
    }

    ZeroMemory(&si4, sizeof(STARTUPINFO));
    si4.cb = sizeof(STARTUPINFO);

    _itoa_s((int)hThread5, lpszHandle2, 10);

    strcat_s(consoleapp5, lpszHandle2);

    if (!CreateProcess(NULL, consoleapp5, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si4, &pi4))
    {
        _cputs("\nA new process has not been created.");
        _cputs("\nPress any key to complete.");
        _getch();
        return GetLastError();
    }

    CloseHandle(pi4.hProcess);
    CloseHandle(pi4.hThread);
    _getch();

    CloseHandle(hThread5);

    _cputs("\nPress any key to exit.");
    _getch();

    TerminateThread(hThread, 0);
    CloseHandle(hThread);

    return 0;
}