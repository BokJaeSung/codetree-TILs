#include <bits/stdc++.h>
using namespace std;
int board[21][21];
int n, m, ans;
int solve(int x, int y, int k)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (abs(x - i) + abs(y - j) <= k)
                cnt += board[i][j];
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
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k <= 2 * (n - 1); k++){
                 if (solve(i,j,k) * m >= k * k + (k + 1) * (k + 1))
                    ans = max(ans,solve(i,j,k));
            }
    cout << ans;
    return 0;
}