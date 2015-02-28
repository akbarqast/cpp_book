/*Write a program that converts a number entered in Roman numerals to a
decimal.Your program should consist of a class, say, romanType.An
object of type romanType should do the following :
a.Store the number as a Roman numeral.
b.Convert and store the number into decimal form.
c.Print the number as a Roman numeral or decimal number as requested
by the user.

The decimal values of the Roman numerals are :
M	1000
D	500
C	100
L	50
X	10
V	5
I	1

d.Test your program using the following Roman numerals : MCXIV,
CCCLIX, MDCLXVI */

#include<iostream>
#include<iomanip>
using namespace std;

class romanType
{
public:
	void userInput(char romanInput[15])
	{
		cout << "Roman Numerals mapping talbe:\n";
		cout << "  M  1000\n" << "  D  500\n" << "  C  100\n" << "  L  50\n" << "  X  10\n" << "  V  5\n" << "  I  1\n" << endl;
		cout << "Enter a roman numeral from avobe talbe to convert.\n";
		cin >> romanInput;

		for (int x = 0; x < 15; x++)
			romanInput[x] = toupper(romanInput[x]); // If user enter lower case roman rumeal

		romansArray(romanInput);
	}
	void romansArray(char romanInput[15])
	{
		int numeralValues[7] = { 1000, 500, 100, 50, 10, 5, 1 };
		char roman[7] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };
		int number = 0, max[15] = { 0 }, numLength = 0, x = 0;
		bool isInputRoman = false;

		for (x = 0; x < 15; x++)
		{
			if (romanInput[x] != '\0')
				numLength++; //Increment user input to fill array
			else
				x = 15;
		}

		for (x = 0; x < numLength; x++)
		{
			isInputRoman = false;


			for (int y = 0; y < 7; y++)
			{
				if (romanInput[x] == roman[y])
				{
					isInputRoman = true; // Read user input
				}
			}
			if (isInputRoman == false)
			{
				cout << "You entered an invalid entry. \n";
				return;
			}
		}
		for (int x = 0; x < numLength; x++)
		{
			//Convert user ruman input to numeral value
			for (int y = 0; y < 7; y++)
			{
				if (romanInput[x] == roman[y])
				{
					max[x] = numeralValues[y];
				}
			}
		}
		//Add numerals value
		for (int x = 0; x < numLength; x++)
		{
			if ((max[x + 1] > max[x]))
			{
				number += (max[x + 1] - max[x]);
				x++;
			}
			else
				number += max[x];
		}
		cout << "Your Roman Numerals values equeals to: " << number << endl << endl;
	}

};


int main()
{
	char choice[15];

	romanType romanObject;
	romanObject.userInput(choice);

	return 0;
}