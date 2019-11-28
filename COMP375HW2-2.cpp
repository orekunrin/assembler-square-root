// COMP375HW2-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This program finds the square root of a number
// Written by John Orekunrin

#include <iostream>

using namespace std;

int main()
{
	int lasttime, sqrt, number;
	cout << "Enter a number >";
	cin >> number;
	_asm {
		// write the following in assembler
		/*sqrt = number;
		do {
			lasttime = sqrt;
			sqrt = (sqrt + number / sqrt) / 2;
		} while (lasttime != sqrt);
		*/
		mov ebx, number
		mov sqrt, ebx
		mov ebx, 0
		doover:
		mov eax, sqrt
			mov lasttime, eax

			mov eax, number
			cdq
			idiv sqrt
			add eax, sqrt
			sar eax, 1
			mov sqrt, eax

			cmp eax, lasttime
			jne doover
	}
	cout << "The square root is " << sqrt << endl;
}