#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[100001];
int S[100001];
int ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    S[0]=arr[0];
    for(int i=1; i<n; i++)
    {
        S[i]=S[i-1]+arr[i];
    }
    ans=S[k-1];
    for(int i=0; i+k<n; i++)
    {
        ans=max(ans,S[i+k]-S[i]);
    }
    cout<<ans;
    return 0;
}