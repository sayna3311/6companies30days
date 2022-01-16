#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& v, int n, int m)
{
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int cnt = 0;
            if(v[i][j]==1) 
                dfs(v,n,m,cnt);
            ans = max(ans, cnt);
        }
    }
    return ans;
}

void dfs(vector<vector<int>>& grid, int i, int j, int &cnt)
{
    if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==0)
            return;
        cnt++;
        grid[i][j]=0;
        dfs(grid,i+1,j,cnt);
        dfs(grid,i-1,j,cnt);
        dfs(grid,i,j+1,cnt);
        dfs(grid,i,j-1,cnt);
        dfs(grid,i-1,j-1,cnt);
        dfs(grid,i+1,j-1,cnt);
        dfs(grid,i-1,j+1,cnt);
        dfs(grid,i+1,j+1,cnt);
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> v(n, vector<int> (m));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>v[i][j];
        }
    }

    cout<<solve(v,n,m);
    return 0;
}