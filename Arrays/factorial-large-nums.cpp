#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// 5 ------------------------------------  Large Factorial   -------------------------------

/*

2. Large Factorial

3. Time Complexity:
	5. O(N) where N is the number for which we have to find the factorial.

3. Space Complexity:
	5. O(N) where N is the number for which we have to find the factorial.

3. DESCRIPTION:
	5. Given a number, we have to find the factorial of that number.

3. APPROACH:
	5. We will use the concept of multiplication of large numbers.
	5. We will maintain an array of size 10000 and initialize it with 0.
	5. We will start multiplying the number with the array and store the result in the array.
	5. We will keep track of the carry and update the array accordingly.

*/

void multiplier(int num, vector<int> &ans, int &size)
{
	int carry = 0;

	for (int i = 0; i < size; i++)
	{
		int res = num * ans[i];
		res = res + carry;

		ans[i] = res % 10;
		carry = res / 10;
	}

	while (carry > 0)
	{
		ans[size++] = carry % 10;
		carry = carry / 10;
	}
}

vector<int> largeFactorial(int num)
{

	vector<int> ans(10000, 0);
	int size = 1;
	ans[0] = 1;

	for (int i = 2; i <= num; i++)
	{
		multiplier(i, ans, size);
	}

	vector<int> result;
	for (int i = 0; i < size; i++)
	{
		result.push_back(ans[i]);
	}

	return result;
}

int main()
{

	return 0;
}