#include<bits/stdc++.h>
using namespace std;

int solve(int a1[], int a2[], int n, int m)
{
    int dp[n+1][m+1];

    for(int i=0; i<=n; i++)
    {
        dp[i][0] = 0;
    }

    for(int i=0; i<=m; i++)
    {
        dp[0][i] = 0;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a1[i-1]==a2[j-1])
                dp[i][j] = dp[i-1][j-1] +1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    return n+m-2*(dp[n][m]);
}

int main()
{
    int n, m;
    cin>>n>>m;
    int a1[n], a2[m];
    for(int i=0; i<n; i++)
    {
        cin>>a1[i];
    }

    for(int j=0; j<m; j++)
    {
        cin>>a2[j];
    }

    cout<<solve(a1,a2,n,m);
}