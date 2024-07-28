#include <bits/stdc++.h>
using namespace std;
int n, m;
int grid[21][21];
int ans=-1;

int solve(int x1, int y1, int x2, int y2)
{
    int cnt = 0;
    for (int i = x1; i <= x2; i++)
        for (int j = y1; j <= y2; j++)
        {
            if (grid[i][j] < 0)
                return 0;
            cnt++;
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
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = i; k < n; k++)
                for (int l = j; l < m; l++)
                {
                    ans = max(ans, solve(i, j, k, l));
                }
    cout << ans;
    return 0;
}