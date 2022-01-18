#include<bits/stdc++.h>
using namespace std;

bool solve(int n, int a[], int summ)
{
    bool dp[n+1][summ+1];
    for(int i=0; i<=n; i++)
    {
        dp[i][0] = true;
    }
    for(int j=0; j<=summ; j++)
    {
        dp[0][j] = false;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=summ; j++)
        {
            if(a[i-1]>=j)
                dp[i][j] = dp[i-1][j]|| dp[i-1][j-a[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][summ];
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int summ = accumulate(a,a+n,0);
    if(summ%2) cout<<0;
    else cout<<solve(n,a,summ/2);
    return 0;
}