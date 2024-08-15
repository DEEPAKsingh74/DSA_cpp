#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*

2. Preorder Traversal (Iterative)

3. Time Complexity:
	5. O(N) where N is the number of nodes in the tree.

3. Space Complexity:
	5. O(N) where N is the number of nodes in the tree.

3. Time complexity using master theorem:
	5. T(n) = O(1) + T(n-1) = O(n)

3. DESCRIPTION:
	5. Preorder traversal is a tree traversal algorithm that traverses the tree in the following order: root, left, right.

3. APPROACH:
	5. Create a stack and push the root node into the stack.
	5. While the stack is not empty, pop the top node from the stack.
	5. Push the data of the top node into the answer vector.
	5. If the right child of the top node exists, push it into the stack.
	5. If the left child of the top node exists, push it into the stack.



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

vector<int> preorderIterative(TreeNode<int> *root)
{
	vector<int> ans;

	if (!root)
		return ans;
	stack<TreeNode<int> *> st;
	st.push(root);

	while (!st.empty())
	{
		TreeNode<int> *front = st.top();
		st.pop();

		ans.push_back(front->data);

		// 3 First move to right than to left.
		if (front->right)
		{
			st.push(front->right);
		}

		if (front->left)
		{
			st.push(front->left);
		}
	}

	return ans;
}

int main()
{

	return 0;
}