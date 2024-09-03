#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// 5 ------------------------------------  Orderly Queue   -------------------------------
/*

2. Orderly Queue

3. Time Complexity:
	5. O(NlogN) where N is the length of the string.

3. Space Complexity:
	5. O(1)

3. DESCRIPTION:
	5. Given a string and an integer k, we have to find the lexicographically smallest string we can get by applying the operation any number of times.

3. APPROACH:
	5. If k > 1, then we can sort the string and return it.
	5. If k = 1, then we will find all the possible strings by rotating the string and return the lexicographically smallest string.
	5. We will take the minimum of all the strings.

*/

string orderlyQueue(string s, int k)
{
	if (k > 1)
	{
		sort(begin(s), end(s));
		return s;
	}
	string result = s;
	int n = s.length();
	for (int i = 1; i <= n - 1; i++)
	{
		string temp = s.substr(i) + s.substr(0, i);
		result = min(temp, result);
	}

	return result;
}

int main()
{

	return 0;
}