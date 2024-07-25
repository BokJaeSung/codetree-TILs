#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int arr[100001];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        cout << upper_bound(arr, arr + n, b) - lower_bound(arr, arr + n, a) << "\n";
    }

    return 0;
}