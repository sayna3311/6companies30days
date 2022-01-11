#include<bits/stdc++.h>
using namespace std;

bool solve(int n, vector<pair<int,int>> v)
{
    vector<int> adj[n];
    for(auto it: v)
    {
        adj[it.first].push_back(it.second);
    }
    int c = 0;
    vector<int> indeg(n,0);
    for(int i=0; i<n; i++)
    {
        for(auto it: adj[i])
        {
            indeg[it]++;
        }
    }
    queue<int> q;
    for(int i=0; i<n; i++)
    {
        if(indeg[i]==0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        c++;
        for(auto it: adj[node])
        {
            indeg[it]--;
            if(indeg[it]==0) q.push(it);
        }
    }
    return (c==n);
}

int main()
{
    int n, p;
    cin>>n>>p;
    vector<pair<int,int>> v(p);
    for(int i=0; i<p; i++)
    {
        int x,y;
        cin>>x>>y;
        v[i] = {x,y};
    }
    cout<<solve(n,v);
}