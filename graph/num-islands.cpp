#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

/*

2. Number of Islands

3. Time Complexity:
	5. O(m*n) where m is the number of rows and n is the number of columns in the matrix.

3. Space Complexity:
	5. O(1)

3. Description:
	5. Given a 2D matrix, we have to find the number of islands.
	5. An island is a group of connected 1s.
	5. Two 1s are connected if they are adjacent to each other horizontally or vertically.

3. Approach:
	5. We will use DFS to solve this problem.
	5. We will traverse the matrix.
	5. If we find a 1, we will increment the count of islands and call the solve function.
	5. In the solve function, we will mark the current cell as visited.
	5. We will traverse the adjacent cells of the current cell.
	5. If the adjacent cell is 1, we will call the solve function recursively.
	5. We will return the count of islands.

*/

int traversalM[4][2] = {
	{0, -1},
	{1, 0},
	{0, 1},
	{-1, 0}};

void solve(vector<vector<int>> &m, int r, int c, int nr, int nc)
{

	if (r < 0 || r >= nr || c < 0 || c >= nc || m[r][c] != 1)
	{
		return;
	}

	m[r][c] = -1;

	for (int i = 0; i < 4; i++)
	{
		int newR = r + traversalM[i][0];
		int newC = c + traversalM[i][1];

		solve(m, newR, newC, nr, nc);
	}
}

int numOfIslands(vector<vector<int>> &m)
{
	int count = 0;
	int r = m.size();
	int c = m[0].size();

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (m[i][j] == 1)
			{
				count++;
				solve(m, i, j, r, c);
			}
		}
	}

	return count;
}

int main()
{

	return 0;
}