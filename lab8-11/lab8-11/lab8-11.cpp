#include <iostream>

#include "Teste.h"

int main()
{
	cout << "Running tests..." << endl;
	teste();
	cout << "Passed!" << endl;

	cout << "Running LIVE tests..." << endl;
	testeLive();
	cout << "Passed!" << endl;
}
