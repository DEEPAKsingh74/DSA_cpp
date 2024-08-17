#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*

2. Inorder-postorder-preorder Traversal

3. Time Complexity:
	5. O(N) where N is the number of nodes in the tree.

3. Space Complexity:
	5. O(N) where N is the number of nodes in the tree.

3. Time complexity using master theorem:
	5. T(n) = O(1) + T(n-1) = O(n)

3. DESCRIPTION:
	5. Inorder, Preorder, and Postorder traversal using a single function.

3. APPROACH:
	5. Create a stack {Node, count}.
	5. while stack is not empty do the following:
		5. If count is 1, push the data of the node into the preorder vector and increment the count.
		5. If count is 2, push the data of the node into the inorder vector and increment the count.
		5. If count is 3, push the data of the node into the postorder vector.
	5. Return the vectors.

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

void allOrderTraversal(TreeNode<int> *root)
{
	stack<pair<TreeNode<int> *, int>> st;

	vector<int> in, pre, post;

	st.push({root, 1});

	while (!st.empty())
	{
		pair<TreeNode<int> *, int> p = st.top();
		st.pop();

		// 1 case-1 for preorder...
		if (p.second == 1)
		{
			pre.push_back(p.first->data);
			p.second++;
			st.push(p);

			if (p.first->left)
			{
				st.push({p.first->left, 1});
			}
		}
		// 1 case-2 for Inorder...
		else if (p.second == 2)
		{
			in.push_back(p.first->data);
			p.second++;
			st.push(p);

			if (p.first->right)
			{
				st.push({p.first->right, 1});
			}
		}
		// 1 case-3 for PostOrder...
		else
		{
			post.push_back(p.first->data);
		}
	}
}

int main()
{

	return 0;
}