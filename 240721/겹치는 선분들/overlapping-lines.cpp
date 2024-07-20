#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> points;
int n,k, ans;
int st;
int ed;
int main()
{
    cin >> n>> k;
    for (int i = 0; i < n; i++)
    {
        int n1;
        char n2;
        cin >> n1 >> n2;
        if(n2=='R')
        {
            points.push_back(make_pair(st, +1));
            points.push_back(make_pair(st+n1, -1));
            st+=n1;
        }
        else{
            points.push_back(make_pair(st, -1));
            points.push_back(make_pair(st-n1, +1));
            st-=n1;
        }
    }
    sort(points.begin(), points.end());
    int sum = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        sum += points[i].second;
        if(sum>=k)
        {
            ans++;
        }
    }

    cout << ans;
    return 0;
}