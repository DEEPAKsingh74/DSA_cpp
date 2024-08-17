#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// 5 ---------------------------------   House Robber  ( Using DP ) ---------------------------------

/*

2. House Robber (Using DP)

3. Time Complexity:
	5. O(N) where N is the number of elements in the array.

3. Space Complexity:
	5. O(N) where N is the number of elements in the array.

3. Time complexity using master theorem:
	5. T(n) = O(1) + T(n-1) = O(n)

3. DESCRIPTION:
	5. You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
	5. Given a list of non-negative integers nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

3. APPROACH:
	5. If the number of houses is less than or equal to 1, return the amount of money in the house.
	5. Create a dp array of size n+1 and initialize it with -1.
	5. Recursively calculate the maximum amount of money that can be robbed from the houses.
	5. Return the maximum amount of money that can be robbed from the houses.

*/

int solve(vector<int> &dp, int n, vector<int> nums)
{
	if (n < 0)
		return 0;

	if (dp[n] != -1)
		return dp[n];

	int steal = nums[n] + solve(dp, n - 2, nums);
	int notSteal = solve(dp, n - 1, nums);

	return dp[n] = max(steal, notSteal);
}

int rob(vector<int> &nums)
{

	int n = nums.size();
	vector<int> dp(n + 1, -1);

	return solve(dp, n - 1, nums);
}

// 5 --------------------------------------  House Robber  ( Bottom up ) ----------------------------

/*

2. House Robber (Bottom up)

3. Time Complexity:
	5. O(N) where N is the number of elements in the array.

3. Space Complexity:
	5. O(N) where N is the number of elements in the array.

3. Time complexity using master theorem:
	5. T(n) = O(1) + T(n-1) = O(n)

3. DESCRIPTION:
	5. You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
	5. Given a list of non-negative integers nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

3. APPROACH:
	5. If the number of houses is less than or equal to 1, return the amount of money in the house.
	5. Create a dp array of size n+1.
	5. If the number of houses is 1, return the amount of money in the house.
	5. Iterate from 2 to n and calculate the maximum amount of money that can be robbed from the houses.
	5. Return the maximum amount of money that can be robbed from the houses.


*/

int rob(vector<int> &nums)
{
	int n = nums.size();
	vector<int> dp(n + 1, 0);

	if (n == 1)
		return nums[0];

	dp[0] = 0;
	dp[1] = nums[0];

	for (int i = 2; i <= n; i++)
	{
		int steal = nums[i - 1] + dp[i - 2];
		int notSteal = dp[i - 1];

		dp[i] = max(steal, notSteal);
	}

	return dp[n];
}

int main()
{

	return 0;
}