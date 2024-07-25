#include <bits/stdc++.h>
using namespace std;
int ans;
int n;
int arr[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        ans += arr[i];
        if (ans <= 0)
        {
            ans = 0;
        }
    }
    cout<<ans;
    return 0;
}