#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
int first_num, last_num;
vector<pair<int, int>> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        v.push_back({n1, n2});
    }
    sort(v.begin(), v.end());
    first_num = v[0].first;
    last_num = v[0].second;
    for (int i = 0; i < n; i++)
    {
        if (v[i].first <= last_num)
            last_num = max(last_num, v[i].second);
        else
        {
            ans +=last_num-first_num ;
            first_num = v[i].first;
            last_num = v[i].second;
        }
    }
            ans +=last_num-first_num ;
    cout << ans;
    return 0;
}