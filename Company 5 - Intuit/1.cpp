#include <bits/stdc++.h>
using namespace std;

int findMin(int arr[], int n)
{
    int sum = accumulate(arr, arr+n, 0);

    bool dp[n+1][sum+1];

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=sum; j++)
        {
            if(i==0)
                dp[i][j] = true;
            else if(j==0)
                dp[i][j] = false;
            else if(arr[i-1]<= j)
                dp[i][j] = dp[i][j-arr[i-1]] | dp[i-1][j];
            else    
                dp[i][j] = dp[i-1][j];
        }
    }
    int diff = INT_MAX;

    for(int j=sum/2; j>=0; j--)
    {
        if(dp[n][j]==true)
        {
            diff = sum - 2 * j;
            break;
        }
    }
    return diff;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout << findMin(arr, n);
    return 0;
}