#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*

2. Check Balanced Binary Tree

3. Time Complexity:
	5. O(N) where N is the number of nodes in the tree.

3. Space Complexity:
	5. O(N) where N is the number of nodes in the tree.

3. Time complexity using master theorem:
	5. T(n) = O(1) + T(n-1) = O(n)

3. DESCRIPTION:
	5. A binary tree is said to be balanced if the difference between the heights of the left and right subtrees of every node in the tree is not more than 1.

3. APPROACH:
	5. If the root is NULL, return 0.
	5. Recursively check if the left subtree is balanced.
	5. If the left subtree is not balanced, return -1.
	5. Recursively check if the right subtree is balanced.
	5. If the right subtree is not balanced, return -1.
	5. If the difference between the heights of the left and right subtrees is more than 1, return -1.
	5. Return the maximum height of the left and right subtrees + 1.

*/

template <typename T>
class TreeNode
{
public:
	T data;
	TreeNode<T> *left;
	TreeNode<T> *right;

	TreeNode(T data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

int checkBalancedBinaryTree(TreeNode<int> *root)
{
	if (!root)
		return 0;

	int leftH = checkBalancedBinaryTree(root->left);
	if (leftH == -1)
		return -1;
	int rightH = checkBalancedBinaryTree(root->right);
	if (rightH == -1)
		return -1;

	if (abs(leftH - rightH) > 1)
		return -1;

	return max(leftH, rightH) + 1;
}

int main()
{

	return 0;
}