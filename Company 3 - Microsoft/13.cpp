#include<bits/stdc++.h>
using namespace std;

void dfs(int u,int par,vector<int> &vis,vector<int> adj[]){
    vis[u] = 1;
    for(auto it:adj[u]){
        if(!vis[it]){
            if(it != par){
                dfs(it,u,vis,adj);
            }
        }
    }
}
int isBridge(int V, vector<int> adj[], int c, int d) 
{
    
    vector<int>::iterator it1 = find(adj[c].begin(),adj[c].end(),d);
    if(it1 != adj[c].end()){
        adj[c].erase(it1);
    }
    vector<int>::iterator it2 = find(adj[d].begin(),adj[d].end(),c);
    if(it2 != adj[d].end()){
        adj[d].erase(it2);
    }
    
    //dfs
    vector<int> vis(V+1,0);
    dfs(c,-1,vis,adj);
    return (vis[d]==0);
}

int main()
{
    int V, E;
    cin>>V>>E;
    vector<int> adj[V];
    int i = 0;
    while(i++<E)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int c, d;
    cin>>c>>d;
    cout<<isBridge(V,adj,c,d);
}