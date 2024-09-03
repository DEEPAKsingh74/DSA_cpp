#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// 5 ------------------------------------  Vertical Order traversal   -------------------------------

/*

2. Vertical Order Traversal

3. Time Complexity:
	5. O(N) where N is the number of nodes in the tree.

3. Space Complexity:
	5. O(N) where N is the number of nodes in the tree.

3. DESCRIPTION:
	5. Given a binary tree, we have to find the vertical order traversal of the tree.

3. APPROACH:
	5. We will maintain a map of map of multiset.
	5. We will maintain a queue of pair of TreeNode* and pair of int.
	5. We will push the root node with x=0 and y=0 in the queue.
	5. We will iterate over the queue and insert the nodes in the map.
	5. At the end, we will iterate over the map and store the nodes in the result vector.

*/
class TreeNode
{
public:
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

vector<vector<int>> verticalOrderTraversal(TreeNode *root)
{
	map<int, map<int, multiset<int>>> mp;
	queue<pair<TreeNode *, pair<int, int>>> q;

	q.push({root, {0, 0}});

	while (!q.empty())
	{
		auto node = q.front();
		q.pop();

		int x = node.second.first, y = node.second.second;
		mp[x][y].insert(node.first->data);

		if (node.first->left)
		{
			q.push({node.first->left, {x - 1, y + 1}});
		}
		if (node.first->right)
		{
			q.push({node.first->right, {x + 1, y + 1}});
		}
	}

	vector<vector<int>> result;
	for (auto it = mp.begin(); it != mp.end(); it++)
	{
		int x = it->first;
		auto &levels = it->second;
		vector<int> column;

		for (auto l = levels.begin(); l != levels.end(); l++)
		{
			int y = l->first;
			auto node = l->second;
			column.insert(column.end(), node.begin(), node.end());
		}
		result.push_back(column);
	}

	return result;
}

int main()
{

	return 0;
}