#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

bool cmp(int a, int b)
{
    string A = to_string(a);
    string B = to_string(b);
    return A + B > B + A;
}

int main()
{
    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        cout << v[i];
    }

    return 0;
}