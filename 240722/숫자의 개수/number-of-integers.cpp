#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[1000001];

int UpperBound(int target)
{
    int left = 0;      // 첫 번째 원소의 위치로 설정합니다.
    int right = n - 1; // 마지막 원소의 위치로 설정합니다.
    int min_idx = n;   // 최소이므로, 답이 될 수 있는 값보다 더 큰 값으로 설정합니다.
    while (left <= right)
    {                                 // [left, right]가 유효한 구간이면 계속 수행합니다.
        int mid = (left + right) / 2; // 가운데 위치를 선택합니다.
        if (arr[mid] > target)
        {                                // 만약에 선택한 원소가 target보다 크다면
            right = mid - 1;             // 왼쪽에 조건을 만족하는 숫자가 더 있을 가능성 때문에 right를 바꿔줍니다.
            min_idx = min(min_idx, mid); // 큰 값들의 위치 중 최솟값을 계속 갱신해줍니다.
        }
        else
            left = mid + 1; // 같거나 작은 경우라면 left를 바꿔줍니다.
    }

    return min_idx; // 조건을 만족하는 최소 index 값을 반환합니다.
}
int LowerBound(int target)
{
    int left = 0;      // 첫 번째 원소의 위치로 설정합니다.
    int right = n - 1; // 마지막 원소의 위치로 설정합니다.
    int min_idx = n;   // 최소이므로, 답이 될 수 있는 값보다 더 큰 값으로 설정합니다.
    while (left <= right)
    {                                 // [left, right]가 유효한 구간이면 계속 수행합니다.
        int mid = (left + right) / 2; // 가운데 위치를 선택합니다.
        if (arr[mid] >= target)
        {                                // 만약에 선택한 원소가 target보다 같거나 크다면
            right = mid - 1;             // 왼쪽에 조건을 만족하는 숫자가 더 있을 가능성 때문에 right를 바꿔줍니다.
            min_idx = min(min_idx, mid); // 같거나 큰 값들의 위치 중 최솟값을 계속 갱신해줍니다.
        }
        else
            left = mid + 1; // 작은 경우라면 left를 바꿔줍니다.
    }

    return min_idx; // 조건을 만족하는 최소 index 값을 반환합니다.
}

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
        int target;
        cin >> target;
        cout << UpperBound(target) - LowerBound(target) << "\n";
    }

    return 0;
}