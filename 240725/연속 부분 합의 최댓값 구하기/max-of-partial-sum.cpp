#include <iostream>
#include <climits>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int n;

int a[MAX_N + 1];

// prefix_sum[i] : 1번째부터 i번째까지 
//                 a배열 원소의 합을 저장하고 있습니다. 
int prefix_sum[MAX_N + 1];

// 누적합 배열에 적절한 값을 채워줍니다.
void Preprocess() {
    prefix_sum[1] = a[1];
    
    for(int i = 2; i <= n; i++)
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
}

// 배열 a의 i번째 원소부터 j번째 원소까지의 합을 반환합니다.
int Sum(int i, int j) {
    return prefix_sum[j] - prefix_sum[i] + a[i];
}

int main() {
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    Preprocess();

    // 최댓값을 구해야 하는 문제이므로
    // 초기값을 INT_MIN으로 설정합니다.
    int ans = INT_MIN;

    // 모든 연속 부분수열 쌍에 대해 그들의 합 중
    // 최댓값을 계산합니다.
    // 연속 부분수열이 i로 시작해서 j로 끝나는 
    // (i, j)쌍을 전부 조사해야 합니다.
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            ans = max(ans, Sum(i, j));
    
    cout << ans;
}