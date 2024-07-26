#include <bits/stdc++.h>
using namespace std;
int n, k;
int ans = INT_MAX;
bool solve(int mid)
{
    int cnt = 0;
    for (int i = 1; i <= n ; i++)
    {
        cnt += min(n, mid / i);
    }
    if (cnt >= k)
        return true;
    else
    {
        return false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    int left = 1;
    int right = n * n;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (solve(mid))
        {
            right = mid - 1;
            ans = min(ans, mid);
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << ans;
    return 0;
}