#include <bits/stdc++.h>
using namespace std;
int board[21][21];
int n, ans;
bool IN_range(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y <n;
}
int solve(int x, int y, int l, int k)
{
    int dx[4] = {-1, -1, 1, 1};
    int dy[4] = {1, -1, -1, 1};
    int num[4] = {l, k, l, k};
    int cnt = 0;
    for (int dir = 0; dir < 4; dir++)
        for (int p = 0; p < num[dir]; p++)
        {
            x += dx[dir];
            y += dy[dir];
            if (!IN_range(x, y))
                return 0;
            cnt += board[x][y];
        }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int l = 1; l < n; l++)
                for (int k = 1; k < n; k++)
                    ans = max(ans, solve(i, j, l, k));
    cout << ans;

    return 0;
}