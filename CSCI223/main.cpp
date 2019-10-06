//C++ User defined Header 
#include "Typename.h"

//C++
#include <iomanip>
#include <bitset>
#include <cstring>
#include <string>

void Display_Bits(int lhs, const char* shift_oper, int rhs)
{
	ios state(nullptr);
	bitset<32> bits;
	string expr;

	//Assign Expresions.
	if (!strcmp(shift_oper, "<<"))
		bits = lhs << rhs;
	else
		bits = lhs >> rhs;

	//OUTPUTS
	expr =  '[' + to_string(lhs) + shift_oper + to_string(rhs) + ']' + " : ";
	
	//OUTPUT Formats
	cout << setiosflags(ios::left)
		<< setw(13)
		<< expr
		<< setprecision(1);

	for (int i = bits.size() - 1; i >= 0; i--)
	{
		if (!(i % 4) && i != 0)
			cout << bits.test(i) << " ";
		else
			cout << bits.test(i);
	}

	//bits.to_ulong(): Converts the contents of the bitset to an unsigned long integer.
	/*
		Our target is print the value to signed integer types.
		So, First we converts bits to unsigned long integer, then convert signed int.
	*/
	cout << ", " << (int)bits.to_ulong() << endl;
}

int main()
{	
	Display_Bits(1, "<<", 31);
	Display_Bits(1, "<<" ,32);
	Display_Bits(1, "<<", 33);
	Display_Bits(-2, "<<", 31);
	Display_Bits(-256, ">>", 33);
	Display_Bits(-256, ">>", 31);

	return 0;
}