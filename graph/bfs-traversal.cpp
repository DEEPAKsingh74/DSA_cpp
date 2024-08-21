#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*

2. BFS Traversal of a graph

3. Time Complexity:
	5. O(V+E) where V is the number of vertices and E is the number of edges in the graph.

3. Space Complexity:
	5. O(V) where V is the number of vertices in the graph.

3. DESCRIPTION:
	5. Given an undirected graph, we have to traverse the graph using BFS.

3. APPROACH:
	5. We will use BFS to traverse the graph.
	5. We will maintain a queue to store the nodes.
	5. We will maintain a vector to store the visited nodes.
	5. We will start from the source node and push it into the queue.
	5. While the queue is not empty, do the following:
		5. Pop the front node from the queue.
		5. For each adjacent node of the node, do the following:
			5. If the node is not visited, push it into the queue.
	5. Return the vector containing the BFS traversal of the graph.

*/

vector<int> bfsTraversal(vector<int> adj[], int V)
{
	int vis[V] = {0};
	vis[0] = 1;
	queue<int> q;
	q.push(1); // 1 asumming its 1 based indexing graph..

	vector<int> bfs;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		bfs.push_back(node);

		for (auto i : adj[node])
		{
			if (!vis[i])
			{
				q.push(i);
				vis[i] = 1;
			}
		}
	}

	return bfs;
}

int main()
{

	return 0;
}