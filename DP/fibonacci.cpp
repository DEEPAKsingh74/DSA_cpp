#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// 5 ------------------------------------  Fibonacci (Normal Recursion)   -------------------------------

/*

2. Fibonacci Series (Normal Recursion)

3. Time Complexity:
	5. O(2^N) where N is the number of elements in the series.

3. Space Complexity:
	5. O(N) where N is the number of elements in the series.

3. Time complexity using master theorem:
	5. T(n) = O(1) + T(n-1) + T(n-2) = O(2^N)

3. DESCRIPTION:
	5. Fibonacci series is a series of numbers in which each number is the sum of the two preceding ones.

3. APPROACH:
	5. If n is less than or equal to 1, return n.
	5. Recursively calculate the sum of the two preceding numbers.


*/

int solve(vector<int> &dp, int n)
{
	if (n <= 1)
		return n;

	if (dp[n] != -1)
		return dp[n];

	return dp[n] = solve(dp, n - 1) + solve(dp, n - 2);
}

int fib(int n)
{

	if (n <= 1)
		return n;
	vector<int> dp(n + 1, -1);
	return solve(dp, n);
}

// 5 -------------------------------------   Fibonacci (Bottom up)   -----------------------------------

/*

2. Fibonacci (Bottom up)

3. Time Complexity:
	5. O(N) where N is the number of elements in the series.

3. Space Complexity:
	5. O(N) where N is the number of elements in the series.

3. Time complexity using master theorem:
	5. T(n) = O(1) + T(n-1) + T(n-2) = O(N)

3. DESCRIPTION:
	5. Fibonacci series is a series of numbers in which each number is the sum of the two preceding ones.

3. APPROACH:
	5. If n is less than or equal to 1, return n.
	5. Create a dp array of size n+1.
	5. Initialize dp[0] = 0 and dp[1] = 1.
	5. Iterate from 2 to n and calculate dp[i] = dp[i-1] + dp[i-2].
	5. Return dp[n].


*/

int solve(vector<int> &dp, int n)
{
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

int fib(int n)
{

	if (n <= 1)
		return n;
	vector<int> dp(n + 1, -1);
	return solve(dp, n);
}

// 5 -------------------------------- Fibonacci (Bottom up without using extra space)  -----------

/*

2. Fibonacci (Bottom up without using extra space)

3. Time Complexity:
	5. O(N) where N is the number of elements in the series.

3. Space Complexity:
	5. O(1) where N is the number of elements in the series.

3. Time complexity using master theorem:
	5. T(n) = O(1) + T(n-1) + T(n-2) = O(N)

3. DESCRIPTION:
	5. Fibonacci series is a series of numbers in which each number is the sum of the two preceding ones.

3. APPROACH:
	5. If n is less than or equal to 1, return n.
	5. Initialize a = 0 and b = 1.
	5. Iterate from 2 to n and calculate c = a + b, a = b, b = c.
	5. Return c.


*/

int solve(int n)
{
	int a = 0;
	int b = 1;
	int c = 0;

	for (int i = 2; i <= n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}

	return c;
}

int fib(int n)
{

	if (n <= 1)
		return n;
	vector<int> dp(n + 1, -1);
	return solve(dp, n);
}

int main()
{

	return 0;
}