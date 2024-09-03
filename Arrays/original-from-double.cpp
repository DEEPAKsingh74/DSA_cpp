#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// 5 ------------------------------------  Original From Double   -------------------------------

/*

2. Original From Double

3. Time Complexity:
	5. O(N) where N is the number of elements in the changed array.

3. Space Complexity:
	5. O(N) where N is the number of elements in the changed array.

3. DESCRIPTION:
	5. Given an array of integers changed, we have to find the original array from which the changed array was created.

3. APPROACH:
	5. We will use a map to store the frequency of each element in the changed array.
	5. We will iterate over the changed array and check if the element is present in the map and the double of the element is also present in the map.


 */

vector<int> findOriginalArray(vector<int> &changed)
{
	map<int, int> mp;
	if (changed.size() % 2 != 0)
		return {};
	for (auto i : changed)
	{
		mp[i]++;
	}

	for (auto i : mp)
	{
		cout << i.first << " " << i.second << endl;
	}
	vector<int> ans;
	for (auto num : changed)
	{
		if (mp[num] == 0)
			continue;

		if (mp.find(num * 2) == mp.end() || mp[num * 2] == 0)
		{
			continue;
		}

		cout << "NUMS: " << num << endl;

		ans.push_back(num);
		mp[num]--;
		mp[num * 2]--;
	}

	return ans;
}

int main()
{

	vector<int> c = {2, 1};
	vector<int> ans = findOriginalArray(c);
	for (auto i : ans)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}