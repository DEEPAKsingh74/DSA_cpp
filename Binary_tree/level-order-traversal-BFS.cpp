#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*

2. Level Order Traversal (BFS)

3. Time Complexity:
	5. O(N) where N is the number of nodes in the tree.

3. Space Complexity:
	5. O(N) where N is the number of nodes in the tree.

3. Time complexity using master theorem:
	5. T(n) = O(1) + T(n-1) = O(n)

3. DESCRIPTION:
	5. Level order traversal is a tree traversal algorithm that traverses the tree level by level.

3. APPROACH:
	5. Create a queue and push the root node into the queue.
	5. While the queue is not empty, pop the front node from the queue.
	5. Push the data of the front node into the answer vector.
	5. If the left child of the front node exists, push it into the queue.
	5. If the right child of the front node exists, push it into the queue.

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

vector<int> levelOrder(TreeNode<int> *root)
{
	vector<int> ans;

	if (root == NULL)
	{
		return ans; // Return an empty vector if the tree is empty.
	}

	queue<TreeNode<int> *> q;
	q.push(root);

	while (!q.empty())
	{
		TreeNode<int> *front = q.front(); // Corrected the queue type to TreeNode<int>*
		q.pop();

		ans.push_back(front->data);

		if (front->left)
		{
			q.push(front->left);
		}

		if (front->right)
		{
			q.push(front->right);
		}
	}

	return ans;
}

int main()
{

	return 0;
}