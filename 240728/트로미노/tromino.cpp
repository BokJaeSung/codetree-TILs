#include <bits/stdc++.h>
using namespace std;
int ans, n, m;
int board[201][201];
bool In_range(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}
int solve(int x, int y, int dir)
{
    int cnt = 0;
    switch (dir)
    {
    case 0:
        if (In_range(x, y + 1) && In_range(x - 1, y))
            cnt += board[x][y + 1] + board[x][y] + board[x - 1][y];
        else
        {
            return 0;
        }
        break;
    case 1:
        if (In_range(x, y - 1) && In_range(x + 1, y))
            cnt += board[x][y - 1] + board[x][y] + board[x + 1][y];
        else
        {
            return 0;
        }
        break;
    case 2:
        if (In_range(x, y + 1) && In_range(x + 1, y))
            cnt += board[x][y + 1] + board[x][y] + board[x + 1][y];
        else
        {
            return 0;
        }
        break;
    case 3:
        if (In_range(x, y - 1) && In_range(x - 1, y))
            cnt += board[x][y - 1] + board[x][y] + board[x - 1][y];
        else
        {
            return 0;
        }
        break;
    case 4:
        if (In_range(x + 1, y) && In_range(x - 1, y))
            cnt += board[x + 1][y] + board[x][y] + board[x - 1][y];
        else
        {
            return 0;
        }
        break;
    case 5:
        if (In_range(x, y + 1) && In_range(x , y-1)
            cnt += board[x][y + 1] + board[x][y] + board[x][y-1];
        else
        {
            return 0;
        }
        break;
    default:
        break;
    }
    return cnt;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    for (int i = 0; j < n; i++)
        for (int j = 0; j < n; j++)
            for (int dir = 0; dir < 6; dir++)
            {
                ans = max(ans, solve(i, j, dir));
            }
    return 0;
}