#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*

2. Integer to Roman

3. Time Complexity:
	5. O(1)

3. Space Complexity:
	5. O(1)

3. DESCRIPTION:
	5. Given an integer, we have to convert it into a roman numeral.

3. APPROACH:
	5. We will maintain two vectors, one for the values and the other for the symbols.
	5. We will iterate over the values vector.
	5. If the value is greater than the input number, we will skip it.
	5. Otherwise, we will append the symbol to the result string.
	5. We will return the result string.


*/

vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
vector<string> symbol = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

string intToRoman(int n)
{
	string result = "";

	for (int i = 0; i < 13; i++)
	{

		if (n == 0)
			break;
		int times = n / val[i];

		while (times--)
		{
			result += symbol[i];
		}

		n = n % val[i];
	}

	return result;
}

int main()
{

	return 0;
}