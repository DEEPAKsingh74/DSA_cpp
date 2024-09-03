#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// 5 ------------------------------------  Surrounded Regions   -------------------------------

/*

2. Surrounded Regions

3. Time Complexity:
	5. O(N*M) where N is the number of rows and M is the number of columns in the board.

3. Space Complexity:
	5. O(N*M) where N is the number of rows and M is the number of columns in the board.

3. DESCRIPTION:
	5. Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
	5. A region is captured by flipping all 'O's into 'X's in that surrounded region.

3. APPROACH:
	5. Traverse the boundary of the board and mark all 'O' and connected 'O' as visited.
	5. Traverse the board and replace all 'O' which are not visited by 'X'.

*/

int arr[4][2] = {
	{0, -1},
	{1, 0},
	{0, 1},
	{-1, 0}};

void dfs(vector<vector<char>> &board, vector<vector<int>> &vis, bool isReplace, int r, int c)
{

	if (r >= board.size() || r < 0 || c >= board[0].size() || c < 0 || vis[r][c] || board[r][c] == 'X')
	{
		return;
	}

	if (isReplace)
	{
		board[r][c] = 'X';
	}
	vis[r][c] = 1;

	// iterate in all four directions..
	for (int i = 0; i < 4; i++)
	{
		int newR = r + arr[i][0];
		int newC = c + arr[i][1];
		dfs(board, vis, isReplace, newR, newC);
	}
}

void solve(vector<vector<char>> &board)
{
	int r = board.size();
	int c = board[0].size();
	vector<vector<int>> vis(r, vector<int>(c, 0));

	// boundary traversal and mark all boundary and connected 'o' visited.
	for (int j = 0; j < c; j++)
	{
		if (board[0][j] == 'O' && !vis[0][j])
		{
			dfs(board, vis, false, 0, j);
		}
		if (board[r - 1][j] == 'O' && !vis[r - 1][j])
		{
			dfs(board, vis, false, r - 1, j);
		}
	}

	for (int j = 0; j < r; j++)
	{
		if (board[j][0] == 'O' && !vis[j][0])
		{
			dfs(board, vis, false, j, 0);
		}
		if (board[j][c - 1] == 'O' && !vis[j][c - 1])
		{
			dfs(board, vis, false, j, c - 1);
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (board[i][j] == 'O' && !vis[i][j])
			{
				dfs(board, vis, true, i, j);
			}
		}
	}
}

int main()
{

	return 0;
}