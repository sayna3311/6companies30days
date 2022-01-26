#include<bits/stdc++.h>
using namespace std;

bool can(vector<int> arr, int k, int mid)
{
    int r = 1;
    int sum = 0;
    for(int i=0; i<arr.size(); i++)
    {
        if(sum + arr[i] > mid) 
        {
            r++;
            sum = arr[i];
        }
        else
        {
            sum += arr[i];
        }
    }
    return r<=k;
}

int shipWithinDays(vector<int>& weights, int days)
{
    int maxi = 0;
    int summ = 0;
    int n = weights.size();
    int ans = INT_MAX;

    for(int i=0; i<n; i++)
    {
        maxi = max(maxi,weights[i]);
        summ += weights[i];
    }

    int start = maxi;
    int end = summ;

    while(start <= end)
    {
        int mid = (start + mid)/2;
        if(can(weights, days, mid))
        {
            ans = min(ans,mid);
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}