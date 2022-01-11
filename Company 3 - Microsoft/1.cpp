#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> v, int n)
{
    int sum = accumulate(v.begin(),v.end(),0);
    bool dp[n+1][sum+1];
    vector<int> x(sum/2);
    int mn = INT_MAX;
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=sum+1; j++)
        {
            if(i==0||j==0)
                dp[i][j] = false;
            else
            {
                if(v[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j-v[i-1]] || dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    for(int i=0; i<=sum/2; i++)
    {
        if(dp[n][i]) v.push_back(i);
    }

    for(int i=0; i<v.size(); i++)
    {
        mn = min(mn, sum - 2*v[i]);
    }
    return mn;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    cout<<solve(v,n);
    return 0;
}