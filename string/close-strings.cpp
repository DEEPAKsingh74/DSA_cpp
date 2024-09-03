#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// 5 ------------------------------------  Close Strings   -------------------------------

/*

2. Close Strings

3. Time Complexity:
	5. O(N) where N is the length of the strings.

3. Space Complexity:
	5. O(1)

3. DESCRIPTION:
	5. Given two strings, we have to check if they are close strings or not.
	5. Two strings are close if they are of the same length and have the same set of characters.

3. APPROACH:
	5. We will maintain two arrays of size 26.
	5. We will iterate over the strings and increment the count of the characters in the arrays.
	5. At the end, we will sort the arrays and check if they are equal or not.

*/

bool closeStrings(string word1, string word2)
{
	vector<int> word1Arr(26, 0);
	vector<int> word2Arr(26, 0);

	if (word1.length() != word2.length())
		return false;

	for (int i = 0; i < word1.length(); i++)
	{
		word1Arr[word1[i] - 'a'] += 1;
		word2Arr[word2[i] - 'a'] += 1;
	}

	for (int i = 0; i < 26; i++)
	{
		if (word1Arr[i] != 0 && word2Arr[i] == 0)
			return false;
		if (word1Arr[i] == 0 && word2Arr[i] != 0)
			return false;
	}

	sort(begin(word1Arr), end(word1Arr));
	sort(begin(word2Arr), end(word2Arr));

	return word1Arr == word2Arr;
}

int main()
{

	return 0;
}