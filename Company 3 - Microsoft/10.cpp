#include <bits/stdc++.h>
using namespace std;

int FindMaxSum(int a[], int n){
        // Your code here
        int dp[n+1] = {0};
        dp[1] = a[0];
        for(int i=1; i<n; i++){
            dp[i+1] = max(a[i]+dp[i-1], dp[i]);
        }
        return dp[n];
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n;i++)
    {
        cin>>a[i];
    }
    cout<<FindMaxSum(a,n);
    return 0;
}