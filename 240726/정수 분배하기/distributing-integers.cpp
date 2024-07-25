#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, ans;
int arr[10001];
bool func(int k)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += arr[i] / k;
    }
    if (cnt >= m)
        return true;
    return false;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int left = 1;
    int right = 10000000000;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (func(mid))
        {
            left = mid + 1;
            ans = max(ans, mid);
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << ans;

    return 0;
}