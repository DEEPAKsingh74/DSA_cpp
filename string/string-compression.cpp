#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*

2. String Compression

3. Time Complexity:
	5. O(N) where N is the number of characters in the input string.

3. Space Complexity:
	5. O(1) as we are using constant space.

3. DESCRIPTION:
	5. Given an array of characters, we have to compress it in-place.
	5. The length after compression must always be smaller than or equal to the original array.
	5. After modifying the original array, return the new length of the array.

3. APPROACH:
	5. We will use two pointers to solve this problem.
	5. We will maintain a variable index to store the index of the current character.
	5. We will start from the first character and iterate over the array.
	5. We will maintain a variable count to store the count of the current character.
	5. If the current character is equal to the next character, we will increment the count.
	5. Otherwise, we will store the current character at the index and increment the index.
	5. If the count is greater than 1, we will convert the count to a string and store it in the array.
	5. Finally, we will return the index.

*/

int compress(vector<char> &chars)
{

	int n = chars.size();
	int i = 0, index = 0;

	while (i < n)
	{
		char current_char = chars[i];
		int count = 0;

		while (i < n && current_char == chars[i])
		{
			count++;
			i++;
		}

		chars[index++] = current_char;
		if (count > 1)
		{
			string num = to_string(count);
			for (char ch : num)
			{
				chars[index++] = ch;
			}
		}
	}
	return index;
}

int main()
{

	return 0;
}