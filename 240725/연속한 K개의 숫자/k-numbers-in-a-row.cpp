#include <bits/stdc++.h>
using namespace std;
int n, k, b;
int arr[100001];
int S[100001];
int ans = 1000000;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k >> b;
    while (b--)
    {
        int num;
        cin >> num;
        arr[num] = 1;
    }
    S[1] = arr[1];
    for (int i = 2; i <= n; i++)
    {
        S[i] = arr[i] + S[i - 1];
    }
    for (int i = k; i <= n; i++)
    {
        ans = min(ans, S[i] - S[i - k + 1]);
    }
    cout << ans;
    return 0;
}