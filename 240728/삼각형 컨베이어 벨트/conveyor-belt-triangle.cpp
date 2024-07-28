#include <bits/stdc++.h>
using namespace std;
int n, t;
int u[201];
int m[201];
int d[201];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> t;
    for (int i = 0; i < n; i++)
        cin >> u[i];
    for (int i = 0; i < n; i++)
        cin >> m[i];
    for (int i = 0; i < n; i++)
        cin >> d[i];
    while (t--)
    {
        int temp = u[n - 1];
        for (int i = n - 1; i >= 1; i--)
            u[i] = u[i - 1];
        u[0] = d[n - 1];
        int temp2 = m[n - 1];
        for (int i = n - 1; i >= 1; i--)
            m[i] = m[i - 1];
        m[0] = temp;
        for (int i = n - 1; i >= 1; i--)
            d[i] = d[i - 1];
        d[0] = temp2;
    }
    for (int i = 0; i < n; i++)
        cout << u[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; i++)
        cout << m[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; i++)
        cout << d[i] << " ";
    return 0;
}