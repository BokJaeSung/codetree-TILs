#include <bits/stdc++.h>
using namespace std;
int n, r, c;
int board[201][201];
int temp[201][201];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool In_bound(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= n;
}
void solve(int row, int col, int k)
{
    for (int i = 0; i < k; i++)
        for (int dir = 0; dir < 4; dir++)
        {
            if (!In_bound(row + i * dx[dir], col + i * dy[dir]))
                continue;
            board[row + i * dx[dir]][col + i * dy[dir]] = 0;
        }
    for (int j = 1; j <= n; j++)
    {
        int temp_row = n;
        bool pass = true;
        for (int i = n; i > 0; i--)
        {
            if (board[i][j] != 0)
                temp[temp_row--][j] = board[i][j];
            
        }
        for (int i = 1; i <= n; i++)
            board[i][j] = temp[i][j];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> board[i][j];
    cin >> r >> c;
    solve(r, c, board[r][c]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
    return 0;
}