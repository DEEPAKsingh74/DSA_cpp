#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*
2. Detect cycle in an undirected graph (Using BFS)
3. Time Complexity:
	5. O(V+E) where V is the number of vertices and E is the number of edges in the graph.
3. Space Complexity:
	5. O(V) where V is the number of vertices in the graph.
3. DESCRIPTION:
	5. Given an undirected graph, we have to detect if there is a cycle in the graph.
3. APPROACH:
	5. We will use BFS to detect the cycle in the graph.
	5. We will maintain a queue to store the nodes.
	5. We will maintain a vector to store the visited nodes.
	5. We will start from the source node and push it into the queue.
	5. While the queue is not empty, do the following:
		5. Pop the front node from the queue.
		5. For each adjacent node of the node, do the following:
			5. If the node is not visited, push it into the queue.
			5. If the node is visited and the parent of the node is not the current node, return true.
	5. Return false.
*/
bool detectBfs(vector<int> adj[], vector<int> &vis, int src)
{
	queue<pair<int, int>> q;
	q.push({src, -1});
	while (!q.empty())
	{
		int node = q.front().first;
		int parent = q.front().second;
		q.pop();
		for (auto n : adj[node])
		{
			if (!vis[n])
			{
				vis[n] = 1;
				q.push({n, node});
			}
			else if (parent != n)
			{
				return true;
			}
		}
	}
	return false;
}
bool isCycle(int V, vector<int> adj[])
{
	vector<int> vis(V + 1, 0);
	for (int i = 0; i < V; i++)
	{
		if (!vis[i])
		{
			if (detectBfs(adj, vis, i))
				return true;
		}
	}
	return false;
}

/*

2. Detect cycle in an undirected graph (Using DFS)
3. Time Complexity:
	5. O(V+E) where V is the number of vertices and E is the number of edges in the graph.
3. Space Complexity:
	5. O(V) where V is the number of vertices in the graph.
3. Time Complexity using master theorem:
	5. T(n) = O(1) + T(n-1) = O(n)
3. DESCRIPTION:
	5. Given an undirected graph, we have to detect if there is a cycle in the graph.
3. APPROACH:
	5. We will use DFS to detect the cycle in the graph.
	5. We will maintain a vector to store the visited nodes.
	5. We will start from the source node and call the DFS function.
	5. In the DFS function, we will mark the node as visited.
	5. For each adjacent node of the node, do the following:
		5. If the node is not visited, call the DFS function.
		5. If the node is visited and the parent of the node is not the current node, return true.
	5. Return false.
*/
bool detectDfs(vector<int> adj[], vector<int> &vis, int parent, int src)
{
	vis[src] = 1;
	for (auto an : adj[src])
	{
		if (!vis[an])
		{
			if (detectDfs(adj, vis, src, an))
				return true;
		}
		else if (parent != an)
		{
			return true;
		}
	}
	return false;
}
bool isCycle(int V, vector<int> adj[])
{
	vector<int> vis(V + 1, 0);
	for (int i = 0; i < V; i++)
	{
		if (!vis[i])
		{
			if (detectDfs(adj, vis, -1, i))
				return true;
		}
	}
	return false;
}

int main()
{

	return 0;
}