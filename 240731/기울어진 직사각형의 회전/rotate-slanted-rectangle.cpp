#include <bits/stdc++.h>
using namespace std;
int n, r, c, m1, m2, m3, m4;
int dx[4] = {-1, -1, +1, +1};
int dy[4] = {-1, +1, +1, -1};
int board[101][101];
void solve(int dir)
{

    int temp = board[r][c];
    int nx = r;
    int ny = c;
    int num_set[4] = {m2, m1, m2, m1};
    if (dir)
    {
        num_set[0] = num_set[2] = m1;
        num_set[1] = num_set[3] = m2;
        dx[0] = dx[1] = dy[1] = dy[2] = -1;
        dx[2] = dx[3] = dy[0] = dy[3] = 1;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < num_set[i]; j++)
        {
            board[nx][ny] = board[nx + dx[i]][ny + dy[i]];
            nx += dx[i];
            ny += dy[i];
        }
    }
    if (!dir)
        board[r - 1][c + 1] = temp;
    else if (dir)
        board[r - 1][c - 1] = temp;
}
int main()
{
    int dir;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> board[i][j];
    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;
    solve(dir);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }

    return 0;
}