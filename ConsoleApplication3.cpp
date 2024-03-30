#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2) 
	{
		cerr << "\nThe number of command line arguments is incorrect." << std::endl;
		return 1;
	}

	string str = argv[1];

	Sleep(1000);
	int result = stoi(str) * 2;
	cout << "Multiply this number by 2 and get: " << result << endl;

	result = result + 8;
	Sleep(4000);
	cout << "Add 8 to this number and we get: " << result << endl;

	result = result / 2;
	Sleep(4000);
	cout << "Divide this number by 2 and get: " << result << endl;

	result = result - stoi(str);
	Sleep(4000);
	cout << "And now we subtract the original number from this number and get: " << result << endl;

	Sleep(4000);

	return 0;
}
