#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*

2. Max Path Sum in a Binary Tree

3. Time Complexity:
	5. O(N) where N is the number of nodes in the binary tree.

3. Space Complexity:
	5. O(1)

3. DESCRIPTION:
	5. Given a binary tree, we have to find the maximum path sum in the binary tree.
	5. A path is a sequence of nodes in the tree where no node is connected to its parent node.
	5. The path sum of a path is the sum of the values of the nodes in the path.
	5. The maximum path sum is the maximum path sum among all the paths in the tree.

3. APPROACH:
	5. We will use recursion to solve this problem.
	5. We will maintain a variable maxi to store the maximum path sum.
	5. We will call the maxPathSum function recursively on the left and right subtrees.
	5. We will update the maxi with the maximum of the left path sum, right path sum, and the sum of the current node.
	5. We will return the maximum of the left path sum and right path sum plus the current node value.

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

int maxPathSum(TreeNode<int> *root, int &maxi)
{

	if (root == NULL)
		return 0;

	int lPathSum = maxPathSum(root->left, maxi);
	int rPathSum = maxPathSum(root->right, maxi);

	maxi = max(maxi, lPathSum + rPathSum + root->data);

	return max(lPathSum, rPathSum) + root->data;
}

int main()
{

	return 0;
}