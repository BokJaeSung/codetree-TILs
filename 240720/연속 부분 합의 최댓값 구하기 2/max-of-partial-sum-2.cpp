#include <iostream>
using namespace std;
int n;
int sum;
int arr[100001];
int main() {
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
        if(sum<0)
        {
            if(i==n-1)
            {
                sum=arr[i];
            }
            else{
                sum=0;
            }
        }
    }
    cout<<sum;
     return 0;
}