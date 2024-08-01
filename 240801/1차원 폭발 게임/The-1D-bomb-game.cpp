#include <bits/stdc++.h>
using namespace std;
int n, m, end_of_array, end_of_temp;
int arr[101];
int temp[101];
int solve(int start, int cur)
{
    int end = start + 1;
    while (end <= end_of_array)
    {
        if (arr[end] == cur)
            end++;
        else
        {
            break;
        }
    }
    return end - 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    end_of_array = n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    bool did_explode;
    do
    {
        
        did_explode = false;
        for (int i = 1; i <= end_of_array; i++)
        {
              if(arr[i] == 0) { 
                continue;
            }
           int  end = solve(i, arr[i]);
            if (end - i + 1 >= m)
            {
                for (int j = i; j <= end; j++)
                    arr[j] = 0;
                did_explode = true;
            }
        }
        end_of_temp = 0;
        for (int i = 1; i <= end_of_array; i++)
            if (arr[i] != 0)
                temp[end_of_temp++] = arr[i];
        end_of_array = end_of_temp;

        for (int i = 1; i <= end_of_array; i++)
            arr[i] = temp[i];
    }while (did_explode); 
     cout << end_of_array << endl;
    for(int i = 1; i <= end_of_array; i++)
        cout << arr[i] << endl;

    return 0;
}