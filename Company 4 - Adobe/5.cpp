#include<bits/stdc++.h>
using namespace std;

int solve(int n, int x)
{
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0] = dp[1] = 1;
    int maxi = pow(n,1.0/x);
    for(int i=2; i<=maxi; i++)
    {
        int curr = pow(i,x);
        for(int j=n; j>=curr; j--)
        {
            dp[j] += dp[j-curr];
        }
    }
    return dp[n];
}

int main()
{
    int n,x;
    cin>>n>>x;
    cout<<solve(n,x);
    return 0;
}