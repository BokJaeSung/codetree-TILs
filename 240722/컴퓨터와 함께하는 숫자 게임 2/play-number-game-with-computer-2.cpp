#include <bits/stdc++.h>
#define int long long
using namespace std;
int m, a, b;
int maXimum, miNimum;
int ans;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m;
    cin >> a >> b;
    miNimum = m;
    for (int target = a; target <= b; target++)
    {
        int cnt = 0;
        int left = 1;
        int right = m;
        while (left <= right)
        {
            cnt++;
            int mid = (left + right) / 2;
            if (mid == target)
            {
                break;
            }
            if (mid > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        maXimum = max(cnt, maXimum);
        miNimum = min(cnt, miNimum);
    }
    cout << miNimum << " " << maXimum;
    return 0;
}