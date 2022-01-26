#include<bits/stdc++.h>
using namespace std;


int maxDistance(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>> dis(m,vector<int>(n,-1));
    queue<pair<int,int>> q;
    
    int count0=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                q.push({i,j});
                dis[i][j]=0;
                count0++;
            } 
        }
    }
    
    if(count0==m*n || count0==0) return -1;
    
    int x[4]={-1,0,1,0};
    int y[4]={0,-1,0,1};
    int max_=INT_MIN;
    while(!q.empty()){
        pair<int,int> p=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int xd=p.first+x[i];
            int yd=p.second+y[i];
            if(xd>=0 && yd>=0 && xd<m && yd<n && dis[xd][yd]==-1 && grid[xd][yd]==0){
                dis[xd][yd]=dis[p.first][p.second]+1;
                q.push({xd,yd});
                max_=max(max_,dis[xd][yd]);
            }
        }
    }
    return max_;
}