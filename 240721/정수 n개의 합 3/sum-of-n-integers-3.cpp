#include <bits/stdc++.h>
using namespace std;
int board[1025][1025];
int dp[1025][1025];
int n, k;
int ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> board[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j] +dp[i][j - 1] - dp[i - 1][j - 1] + board[i][j];
        }
    for(int i=1; i+k-1<=n; i++)
        for(int j=1; j+k-1<=n; j++)
        {
            ans=max(ans,dp[i+k-1][j+k-1]-dp[i-1][j+k-1]-dp[i+k-1][j-1]+dp[i-1][j-1]);
        }
    cout<<ans;
    return 0;
}