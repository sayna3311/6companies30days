#include<bits/stdc++.h>
using namespace std;

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    vector<pair<float,int>> adj[n];
    vector<bool> vis(n, false);
    int i=0;
    for(auto x: edges)
    {
        adj[x[0]].push_back({succProb[i], x[1]});
        adj[x[1]].push_back({succProb[i], x[0]});
        i++;
    }

    priority_queue<pair<float,int>> pq;

    for(auto i: adj[start])
    {
        pq.push(i);
    }

    while(!pq.empty())
    {
        auto t = pq.top();
        pq.pop();

        vis[t.second] = true;

        if(t.second==end)
        {
            return t.first;
        }

        for(auto i: adj[t.second])
        {
            if(vis[i.second]==false)
                pq.push({t.first*i.first,i.second});
        }
    }
    return 0;
}