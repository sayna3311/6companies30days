#include<bits/stdc++.h>
using namespace std;

int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        int ar[n+1];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int num=0;
            for(int j=n-1;j>=0;j--)
            {
                if(grid[i][j]==0)
                {
                    num++;
                }
                else
                {
                    break ;
                }
            }
            ar[i]=num;
        }
        for(int i=0;i<n;i++)
        {
            if(ar[i]>=n-i-1)
            {
                continue ;
            }
            int j=i+1;
            bool temp=false;
            for(;j<n;j++)
            {
                if(ar[j]>=n-i-1)
                {
                    temp=true;
                    break ;
                }
            }
            if(!temp)
            {
                return -1;
            }
            while(j!=i)
            {
                swap(ar[j],ar[j-1]);
                ans++;
                j--;
            }
        }
        return ans;
    }