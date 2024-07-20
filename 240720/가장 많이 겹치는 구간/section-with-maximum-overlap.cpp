#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> points;
int n, ans;
int arr[200001];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        points.push_back(make_pair(n1, +1));
        points.push_back(make_pair(n2, -1));
    }
    sort(points.begin(), points.end());
    int sum = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        sum += points[i].second;
        ans = max(sum, ans);
    }

    cout << ans;
    return 0;
}