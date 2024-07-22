#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    while (m--)
    {
        int left = 0;
        int right = n - 1;
        int target;
        int idx = -1;
        cin >> target;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] == target)
            {
                idx = mid + 1;
                break;
            }
            if (arr[mid] > target)
                right = mid - 1;
            else
            {
                left = mid + 1;
            }
        }
        cout << idx << "\n";
    }

    return 0;
}