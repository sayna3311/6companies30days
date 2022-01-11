#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> v, int n, int m)
{
    if(v.empty()) return 0;
    int c = 0;
    queue<pair<pair<int,int>, int>> q;
    for (int i = 0; i < n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(v[i][j]==2)
            {
                q.push({{i,j},0});
            }
            if(v[i][j]==0) c++;
        }
    }
    int dirX[] = {-1,1,0,0}, dirY[] = {0,0,-1,1};
    int rot = 0, x,y,time = 0;
    pair<pair<int,int>,int> p;
    while(!q.empty())
    {
        p = q.front();
        x = p.first.first;
        y = p.first.second;
        time = p.second;
        q.pop();
        rot++;
        for(int i=0; i<4; i++)
        {
            int newX = x+dirX[i];
            int newY = y+dirY[i];
            if(newX >= 0 && newX<n && newY >=0 && newY<m && v[newX][newY]==1)
            {
                v[newX][newY] = 2;
                q.push({{newX,newY},time+1});
            }
        }
    }
    if(rot + c != n*m)
        return -1;
    return time;
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
