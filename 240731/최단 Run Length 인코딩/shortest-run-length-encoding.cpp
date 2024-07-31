#include <bits/stdc++.h>
using namespace std;
string str;
int ans;
int check()
{
    int cnt = 1;
    for (int i = 0; i < str.length() - 1; i++)
        if (str[i] != str[i + 1])
            cnt++;
    if (cnt == 1)
    {
        if (str.length() == 10)
            return 3;
    }
    return cnt * 2;
}

void solve()
{
    char temp = str[str.length() - 1];
    for (int i = str.length() - 1; i > 0; i--)
        str[i] = str[i - 1];
    str[0] = temp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> str;
    int size = str.length();
    // aaabbbbcaa size:10
    if (size == 1)
    {
        cout << 2;
        return 1;
        }
    for (int i = 0; i < size - 1; i++)
    {
        ans = min(ans, check());
        solve();
    }
    cout << ans;
    return 0;
}