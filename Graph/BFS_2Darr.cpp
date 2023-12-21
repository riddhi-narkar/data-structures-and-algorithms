#include <bits/stdc++.h>
using namespace std;


// Direction vectors
int dRow[] = {-1, 0, 1, 0};
int dCol[] = {0, 1, 0, -1};

// Function to check if a cell
// is be visited or not
bool is_visited(bool* visited[][],
             int row, int col)
{
    // If cell lies out of bounds
    if (row < 0 || col < 0 || row >= ROW || col >= COL)
        return false;

    // If cell is already visited
    if (vis[row][col])
        return false;

    // Otherwise
    return true;
}

void BFS(int* grid, bool* visited, int row, int cols)
{
    queue<pair<int, int>> q; //indices of matrix

    q.push({row, cols});
    visited[row][cols] = true;

    while (!q.empty())
    {
        pair<int, int> element = q.front();
        int x = element.first;
        int y = element.second;

        // cout << grid[x][y] << " ";

        q.pop();

        // Go to the adjacent cells
        for (int i = 0; i < 4; i++)
        {

            int adjx = x + dRow[i];
            int adjy = y + dCol[i];

            if (isValid(visited, adjx, adjy))
            {
                q.push({adjx, adjy});
                visited[adjx][adjy] = true;
            }
        }
    }
}

int main()
{
    int rows, cols;
    cin >> rows >> cols;

    int arr[rows][cols];
    bool visited[rows][cols];
    memset(visited, false, sizeof(visited)); // initializing visited array with all false values

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> arr[i][j];

    BFS((int*)arr, (bool*)visited, 0, 0);

    return 0;
}