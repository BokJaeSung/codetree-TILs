#include <iostream>
#include <algorithm>
#define int long long
int s;
using namespace std;

signed main()
{
    int left = 1;           
    int right = 10000000000; 
    int max_num = 1;        
    cin >> s;
    while (left <= right)
    {                                 
        int mid = (left + right) / 2; 
        if (mid * (mid + 1) / 2 <= s)
        {                                
            left = mid + 1; 
            max_num = max(max_num, mid); 
        }
        else
            right = mid - 1;             
    }

    cout << max_num; 
    return 0;
}