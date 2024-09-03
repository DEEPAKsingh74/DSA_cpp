#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// 5 ------------------------------------  Root to Node Path   -------------------------------

/*

2. Root to Node Path

3. Time Complexity:
	5. O(N) where N is the number of nodes in the tree.

3. Space Complexity:
	5. O(N) where N is the number of nodes in the tree.

3. DESCRIPTION:
	5. Given a binary tree and a value, we have to find the path from the root to the node with the given value.

3. APPROACH:
	5. We will find the node to root path for the given value.
	5. We will return the path.

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

bool solve(TreeNode *root, int value, vector<int> &path)
{
	if (root == NULL)
		return false;

	path.push_back(root->data);
	if (root->data == value)
		return true;

	if (solve(root->left, value, path) || solve(root->right, value, path))
	{
		return true;
	}

	path.pop_back();
	return false;
}

vector<int> rootToNode(TreeNode *root, int value)
{
	vector<int> path;
	if (root == NULL)
		return path;

	solve(root, value, path);

	return path;
}

int main()
{

	return 0;
}