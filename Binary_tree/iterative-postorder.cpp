#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*

2. Postorder Traversal (Iterative)

3. Time Complexity:
	5. O(N) where N is the number of nodes in the tree.

3. Space Complexity:
	5. O(N) where N is the number of nodes in the tree.

3. Time complexity using master theorem:
	5. T(n) = O(1) + T(n-1) = O(n)

3. DESCRIPTION:
	5. Postorder traversal is a tree traversal algorithm that traverses the tree in the following order: left, right, root.

3. APPROACH:
	5. Create two stacks st1 and st2.
	5. Push the root node into st1.
	5. While st1 is not empty, pop the top node from st1.
	5. Push the top node into st2.
	5. If the left child of the top node exists, push it into st1.
	5. If the right child of the top node exists, push it into st1.
	5. While st2 is not empty, pop the top node from st2 and push its data into the answer vector.

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

vector<int> iterativePostOrder1(TreeNode<int> *root)
{

	stack<TreeNode<int> *> st1;
	stack<TreeNode<int> *> st2;
	vector<int> ans;

	if (!root)
		return;
	st1.push(root);

	while (!st1.empty())
	{
		TreeNode<int> *top = st1.top();
		st1.pop();

		st2.push(top);

		if (top->left)
		{
			st1.push(top->left);
		}

		if (top->right)
		{
			st1.push(top->right);
		}
	}

	while (!st2.empty())
	{
		ans.push_back(st2.top()->data);
		st2.pop();
	}

	return ans;
}

vector<int> iterativePostOrder2(TreeNode<int> *root)
{

	stack<TreeNode<int> *> st;
	TreeNode<int> *curr = root;
	vector<int> ans;

	while (curr != NULL || !st.empty())
	{

		if (curr != NULL)
		{
			st.push(curr);
			curr = curr->left;
		}
		else
		{
			TreeNode<int> *temp = st.top()->right;

			if (temp == NULL)
			{
				temp = st.top();
				st.pop();

				ans.push_back(temp->data);

				while (!st.empty() && temp == st.top()->right)
				{
					temp = st.top();
					st.pop();
					ans.push_back(temp->data);
				}
			}
			else
			{
				curr = temp;
			}
		}
	}
}

int main()
{

	return 0;
}