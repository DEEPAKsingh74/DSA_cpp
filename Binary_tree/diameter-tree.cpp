#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*

2. Diameter of Binary Tree

3. Time Complexity:
	5. O(N) where N is the number of nodes in the tree.

3. Space Complexity:
	5. O(N) where N is the number of nodes in the tree.

3. Time complexity using master theorem:
	5. T(n) = O(1) + T(n-1) = O(n)

3. DESCRIPTION:
	5. The diameter of a binary tree is the number of nodes on the longest path between two leaves in the tree.

3. APPROACH:
	5. If the root is NULL, return 0.
	5. Recursively calculate the height of the left subtree.
	5. Recursively calculate the height of the right subtree.
	5. Update the maximum diameter of the tree.
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

int diameterBinaryTree(TreeNode<int> *root, int maxi)
{

	if (!root)
		return 0;

	int lh = diameterBinaryTree(root->left, maxi);
	int rh = diameterBinaryTree(root->right, maxi);

	maxi = max(maxi, lh + rh);

	return 1 + max(lh, rh);
}

int main()
{

	return 0;
}