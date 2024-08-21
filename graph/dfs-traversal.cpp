#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*

2. DFS Traversal of a graph

3. Time Complexity:
	5. O(V+E) where V is the number of vertices and E is the number of edges in the graph.

3. Space Complexity:
	5. O(V) where V is the number of vertices in the graph.

3. DESCRIPTION:
	5. Given an undirected graph, we have to traverse the graph using DFS.

3. APPROACH:
	5. We will use DFS to traverse the graph.
	5. We will maintain a vector to store the visited nodes.
	5. We will start from the source node and push it into the vector.
	5. For each adjacent node of the node, do the following:
		5. If the node is not visited, push it into the vector.
	5. Return the vector containing the DFS traversal of the graph.


*/

void solve(vector<int> &vis, int node, vector<int> adj[], vector<int> &ls)
{
	vis[node] = 1;

	ls.push_back(node);

	for (auto it : adj[node])
	{
		if (vis[node] == 0)
		{
			solve(vis, it, adj, ls);
		}
	}
}

vector<int> dfsTraversal(int V, vector<int> adj[], vector<int> vis)
{
	vector<int> ls;
	vector<int> vis(V + 1, 0);

	solve(vis, 0, adj, ls);

	return ls;
}

int main()
{

	return 0;
}