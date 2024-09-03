#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// 5 ------------------------------------  Trapping Rain Water   -------------------------------

/*

2. Trapping Rain Water

3. Time Complexity:
	5. O(N) where N is the number of elements in the height array.

3. Space Complexity:
	5. O(1)

3. DESCRIPTION:
	5. Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

3. APPROACH:
	5. We will use two pointers approach.
	5. We will maintain two variables leftMax and rightMax.
	5. We will iterate from left to right and maintain the leftMax.
	5. We will iterate from right to left and maintain the rightMax.
	5. We will take the minimum of leftMax and rightMax and subtract the height of the current bar.
	5. We will add the result to the answer.

*/

int trap(vector<int> &height)
{
	int n = height.size();
	int leftMax = height[0];
	int rightMax = height[n - 1];
	int ans = 0;
	int i = 0, j = n - 1;
	while (i < j)
	{
		leftMax = max(leftMax, height[i]);
		rightMax = max(rightMax, height[j]);
		if (leftMax < rightMax)
		{
			ans += abs(leftMax - height[i]);
			i++;
		}
		else
		{
			ans += abs(rightMax - height[j]);
			j--;
		}
	}

	return ans;
}

int main()
{

	return 0;
}