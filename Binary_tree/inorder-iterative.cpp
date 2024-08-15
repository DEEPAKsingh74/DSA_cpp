#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*

2. Inorder Traversal (Iterative)

3. Time Complexity:
	5. O(N) where N is the number of nodes in the tree.

3. Space Complexity:
	5. O(N) where N is the number of nodes in the tree.

3. Time complexity using master theorem:
	5. T(n) = O(1) + T(n-1) = O(n)

3. DESCRIPTION:
	5. Inorder traversal is a tree traversal algorithm that traverses the tree in the following order: left, root, right.

3. APPROACH:
	5. Create a stack.
	5. While true, if the root is not NULL, push the root into the stack and move to the left child of the root.
	5. Else, if the stack is not empty, pop the top node from the stack, push its data into the answer vector, and move to the right child of the node.
	5. If the stack is empty, break the loop.
	5. Return the answer vector.

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

vector<int> inorderIterative(TreeNode<int> *root)
{
	vector<int> ans;
	stack<TreeNode<int> *> st;

	while (true)
	{
		if (root != NULL)
		{
			st.push(root);
			root = root->left;
		}
		else
		{

			if (st.empty() == true)
				break;
			ans.push_back(st.top()->data);
			st.pop();
			root = root->right;
		}
	}

	return ans;
}

int main()
{

	return 0;
}