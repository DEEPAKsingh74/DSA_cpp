#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// 5 ------------------------------------  Slowest Key   -------------------------------

/*

2. Slowest Key

3. Time Complexity:
	5. O(N) where N is the number of elements in the releaseTimes array.

3. Space Complexity:
	5. O(1)

3. DESCRIPTION:
	5. Given an array of releaseTimes and a string keysPressed, we have to find the slowest key pressed.

3. APPROACH:
	5. Iterate over the releaseTimes array and find the key which has the longest duration.
	5. If the duration is same, then we will take the key which has the maximum ASCII value.


*/

char slowestKey(vector<int> &releaseTimes, string keysPressed)
{
	char ans = keysPressed[0];
	int longestDuration = releaseTimes[0];
	int n = releaseTimes.size();
	for (int i = 1; i < n; i++)
	{
		if ((releaseTimes[i] - releaseTimes[i - 1]) > longestDuration)
		{
			ans = keysPressed[i];
			longestDuration = (releaseTimes[i] - releaseTimes[i - 1]);
		}
		else if ((releaseTimes[i] - releaseTimes[i - 1]) == longestDuration)
		{
			ans = (ans > keysPressed[i]) ? ans : keysPressed[i];
		}
	}

	return ans;
}

int main()
{

	return 0;
}