#include <bits/stdc++.h>
using namespace std;

int n, m, q;
int board[101][101];
int grid[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool In_bound(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void solve(int x1, int x2, int y1, int y2)
{
    // Rotate the edges of the submatrix
    int temp = board[x1][y2];
    for (int i = y2; i > y1; i--)
        board[x1][i] = board[x1][i - 1];
    for (int j = x1; j < x2; j++)
        board[j][y1] = board[j + 1][y1];
    for (int i = y1; i < y2; i++)
        board[x2][i] = board[x2][i + 1];
    for (int j = x2; j > x1; j--)
        board[j][y2] = board[j - 1][y2];
    board[x1 + 1][y2] = temp;

    // Initialize grid to 0
    memset(grid, 0, sizeof(grid));

    // Calculate the new values for the grid
    for (int i = x1; i <= x2; i++)
        for (int j = y1; j <= y2; j++)
        {
            int cnt = 1;
            grid[i][j]+=board[i][j];
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (!In_bound(nx, ny))
                    continue;
                cnt++;
                grid[i][j] += board[nx][ny];
            }
            if (cnt > 0) // Avoid division by zero
                grid[i][j] /= cnt;
        }

    // Copy the new values from grid to board
    for (int i = x1; i <= x2; i++)
        for (int j = y1; j <= y2; j++)
    {
        board[i][j]=grid[i][j];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> board[i][j];

    while (q--)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        solve(x1, x2, y1, y2);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }

    return 0;
}