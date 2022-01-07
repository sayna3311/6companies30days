#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> a, int n, int k)
{
    int dp[k+1][n];
    for(int i=0;i<=k;i++)
        {
            dp[i][0]=0;
        }
    for(int i=0;i<n;i++) 
    {
        dp[0][i]=0;
    }
    for(int i=1; i<=k; i++)
    {
        int prev = INT_MIN;
        for(int j=1; j<n; j++)
        {
            prev = max(prev,dp[i-1][j-1] - a[j-1]);
            dp[i][j] = max(dp[i][j-1],prev + a[j]);
        }
    }
    return dp[k][n-1];
}

int main()
{
    int k, n;
    cin>>k>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int res = solve(a,n,k);
    cout<<res;
    return 0;
}