#include <bits/stdc++.h>
using namespace std;

int n;
// int size;
int s1, s2, e1, e2;
int temp_row = 1;
int arr_row = 1;
int arr[101];
int temp[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    cin >> e1 >> s1 >> e2 >> s2;
    for (int i = e1; i <= s1; i++)
        arr[i] = 0;
    for (int i = 1; i <= n; i++)
        if (arr[i] != 0)
        {
            temp[temp_row++] = arr[i];
        }
    for (int i = e2; i <= s2; i++)
        temp[i] = 0;
    for (int i = 1; i < temp_row; i++)
        if (temp[i] != 0)
        {
            arr[arr_row++] = temp[i];
        }
    cout << arr_row - 1 << "\n";
    if (arr_row == 1)
        return 0;
    for (int i = 1; i < arr_row; i++)
        cout << arr[i] << "\n";
    return 0;
}