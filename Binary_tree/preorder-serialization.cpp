#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// 5 ------------------------------------  Preorder Serialization   -------------------------------

/*
2. Preorder Serialization

3. Time Complexity:
	5. O(N) where N is the number of elements in the preorder string.

3. Space Complexity:
	5. O(1)

3. DESCRIPTION:
	5. Given a string preorder, we have to check if the string is a valid preorder serialization of a binary tree.

3. APPROACH:
	5. We will maintain a count variable and iterate over the string.
	5. If the count becomes less than 0, then we will return false.
	5. If the character is a number, then we will increment the count by 1.
	5. If the character is a #, then we will decrement the count by 1.
	5. If the character is a comma, then we will continue.
	5. At the end, we will check if the count is 0 or not.
*/

bool isValidSerialization(string preorder)
{
	int count = 1;
	for (auto i : preorder)
	{
		if (count <= 0)
			return false;
		if (i == '#')
		{
			count--;
			cout << count << " ";
		}
		else if (i == ',')
		{
		}
		else
		{
			count++;
			cout << count << " ";
		}
	}

	return count == 0;
}

int main()
{

	cout << isValidSerialization("9,#,92,#,#");

	return 0;
}