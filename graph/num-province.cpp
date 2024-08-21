#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*

2. Number of Provinces

3. Time Complexity:
	5. O(V+E) where V is the number of vertices and E is the number of edges in the graph.

3. Space Complexity:
	5. O(V) where V is the number of vertices in the graph.

3. Description:
	5. Given a graph, we have to find the number of provinces.
	5. A province is a group of connected nodes.
	5. Two nodes are connected if there is an edge between them.

3. Approach:
	5. We will use DFS to solve this problem.
	5. We will traverse the graph.
	5. If we find a node that is not visited, we will increment the count of provinces and call the solve function.
	5. In the solve function, we will mark the current node as visited.
	5. We will traverse the adjacent nodes of the current node.
	5. If the adjacent node is not visited, we will call the solve function recursively.
	5. We will return the count of provinces.

*/

int solve(vector<int> adj[], vector<int> &vis, int node)
{
	vis[node] = 1;

	for (auto it : adj[node])
	{
		if (vis[it] == 0)
		{
			solve(adj, vis, it);
		}
	}
}

int numOfProvinces(vector<int> adj[], int V)
{
	int count = 0;
	vector<int> vis(V + 1, 0);

	for (int i = 0; i < V; i++)
	{
		if (!vis[i])
		{
			count++;
			solve(adj, vis, i);
		}
	}

	return count;
}

int main()
{

	return 0;
}