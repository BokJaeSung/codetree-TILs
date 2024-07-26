#include <iostream>
#include <algorithm>
#include <climits>
#define int long long;
#define MAX_N 200000
#define MAX_NUM 1000000000

using namespace std;

// 변수 선언
int n, m;
int arr[MAX_N];

// 가장 인접한 두 물건의 거리를 dist로 한다 했을 때
// 물건을 m개 설치할 수 있을지를 판단합니다.
bool IsPossible(int mid)
{
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        cnt += mid / arr[i];
    }
    if (cnt >= n)
        return true;
    else
    {
        return false;
    }
}

signed main()
{
    // 입력
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> arr[i];

    // 물건의 위치를 정렬해줍니다.
    sort(arr, arr + m);

    int left = 1;        // 답이 될 수 있는 가장 작은 숫자 값을 설정합니다.
    int right = MAX_NUM; // 답이 될 수 있는 가장 큰 숫자 값을 설정합니다.
    int ans = MAX_NUM;   // 답을 저장합니다.

    while (left <= right)
    {                                 // [left, right]가 유효한 구간이면 계속 수행합니다.
        int mid = (left + right) / 2; // 가운데 위치를 선택합니다.
        if (IsPossible(mid))
        {
            right = mid - 1;
            ans = min(ans, mid);
        }
        else
            left = mid + 1;
    }

    cout << ans;
    return 0;
}