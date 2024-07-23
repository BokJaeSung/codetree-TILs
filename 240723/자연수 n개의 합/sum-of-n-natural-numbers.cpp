#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int left = 1;                          // 가장 작은 숫자 값을 설정합니다.
    int right = 30;                        // 가장 큰 숫자 값을 설정합니다.
    int min_num = 31;                      // 최소이므로, 답이 될 수 있는 값보다 더 큰 값으로 설정합니다.
    while (left <= right) {                // [left, right]가 유효한 구간이면 계속 수행합니다.
        int mid = (left + right) / 2;      // 가운데 위치를 선택합니다.
        if(mid * (mid + 1) / 2 >= 100) {   // 1부터 n까지의 합이 100보다 같거나 크다면
            right = mid - 1;               // 왼쪽에 조건을 만족하는 숫자가 더 있을 가능성 때문에 right를 바꿔줍니다.
            min_num = min(min_num, mid);   // 답의 후보들 중 최솟값을 계속 갱신해줍니다.
        }
        else                               
            left = mid + 1;                // 100보다 작은 경우라면 left를 바꿔줍니다.
    }

    cout << min_num;                       // 조건을 만족하는 최소 n 값을 출력합니다.
    return 0;
}