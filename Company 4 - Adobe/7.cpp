#include <bits/stdc++.h>
using namespace std;
int helper(vector<int>& nums, vector<vector<int>>& dp, int s, int e)
{
    if(s>e)
        return dp[s][e]=0;
    if(s==e)
        return dp[s][e]=nums[s];
    if(dp[s][e] != -1)
        return dp[s][e];
        
    int l=nums[s] + min(helper(nums, dp, s+2, e), helper(nums, dp, s+1, e-1));
    int r=nums[e] + min(helper(nums, dp, s+1, e-1), helper(nums, dp, s, e-2));
    
    return dp[s][e]=max(l, r);
}

int solve(vector<int>&A,int n)
{
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return helper(A, dp, 0, n-1);
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<solve(a,n);
    return 0;
}