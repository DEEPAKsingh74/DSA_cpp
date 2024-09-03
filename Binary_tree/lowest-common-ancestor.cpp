#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// METHOD-2 ->> Find the node to root path for both values and take the lowest node common between.

// 5 ------------------------------------  Lowest Common Ancestor   -------------------------------

/*

2. Lowest Common Ancestor

3. Time Complexity:
	5. O(N) where N is the number of nodes in the tree.

3. Space Complexity:
	5. O(N) where N is the number of nodes in the tree.

3. DESCRIPTION:
	5. Given a binary tree and two values v1 and v2, we have to find the lowest common ancestor of the two values.

3. APPROACH:
	5. We will find the node to root path for both values.
	5. We will take the lowest node common between the two paths.


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

TreeNode *lowestCommonAncestor(TreeNode *root, int v1, int v2)
{
	if (root == NULL)
		return NULL;
	if (root->data == v1 || root->data == v2)
		return root;

	TreeNode *left = lowestCommonAncestor(root->left, v1, v2);
	TreeNode *right = lowestCommonAncestor(root->right, v1, v2);

	if (left == NULL)
		return right;
	if (right == NULL)
		return left;

	return root;
}

int main()
{

	return 0;
}