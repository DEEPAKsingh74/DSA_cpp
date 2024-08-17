#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

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

// 5. -------------------------   METHOD 1 (Using 2 stacks)   -------------------------

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
	5. Create 2 stacks.
	5. Push the root into the first stack.
	5. While the first stack is not empty, do the following:
		5. Pop the top node from the first stack and push it into the second stack.
		5. If the left child of the node is not NULL, push it into the first stack.
		5. If the right child of the node is not NULL, push it into the first stack.
	5. While the second stack is not empty, push the data of the top node into the answer vector.
	5. Return the answer vector.



*/

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

// 5. -------------------------   METHOD 2 (Using 1 stack)   -------------------------

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
	5. Create a stack.
	5. While the current node is not NULL or the stack is not empty, do the following:
		5. If the current node is not NULL, push the current node into the stack and move to the left child of the current node.
		5. Else, pop the top node from the stack and store it in a temporary node.
		5. If the right child of the temporary node is NULL, push the data of the temporary node into the answer vector.
		5. While the stack is not empty and the temporary node is the right child of the top node of the stack, do the following:
			5. Pop the top node from the stack and store it in a temporary node.
			5. Push the data of the temporary node into the answer vector.
		5. If the right child of the temporary node is not NULL, push the temporary node into the stack.

	5. Return the answer vector.

*/

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