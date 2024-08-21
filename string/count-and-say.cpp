#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*

2. Count and Say

3. Time Complexity:
	5. O(N * 2^N) where N is the input number.

3. Space Complexity:
	5. O(2^N) where N is the input number.

3. DESCRIPTION:
	5. The count-and-say sequence is a sequence of integers with the first five terms as following:
		5. 1. 1
		5. 2. 11
		5. 3. 21
		5. 4. 1211
		5. 5. 111221
	5. 1 is read off as "one 1" or 11.
	5. 11 is read off as "two 1s" or 21.
	5. 21 is read off as "one 2, then one 1" or 1211.
	5. Given an integer n where 1 <= n <= 30, generate the nth term of the count-and-say sequence.

3. APPROACH:
	5. We will use recursion to solve this problem.
	5. If n is 1, we will return "1".
	5. Otherwise, we will call the countAndSay function recursively with n-1.
	5. We will iterate over the string returned by the recursive call.
	5. We will count the number of occurrences of the current character.
	5. We will append the count and the character to the result string.
	5. We will return the result string.

*/

string countAndSay(int n)
{
	if (n == 1)
	{
		return "1";
	}

	string say = countAndSay(n - 1);

	string result = "";
	for (int i = 0; i < say.length(); i++)
	{
		char ch = say[i];
		int count = 1;
		while (i < say.length() - 1 && say[i] == say[i + 1])
		{
			i++;
			count++;
		}

		result += to_string(count) + string(1, ch);
	}

	return result;
}

int main()
{

	return 0;
}