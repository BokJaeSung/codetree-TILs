#include <bits/stdc++.h>
using namespace std;
int arr[1002];
int S[1002];
int n, k;
int cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
     for (int i = 2; i <= n; i++)
    {
        S[i] = arr[i] + S[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
            if ((S[i] - S[j]) == k)
                cnt++;
    }
    cout << cnt;
    return 0;
}