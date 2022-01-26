#include<bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<int> rec;
vector<int> ans;
bool isCycle;

void dfs(int curr, vector<vector<int>>& gr)
{
    if(!visited[curr])
    {
        rec[curr] = 1;
        for (int i = 0; i<gr[curr].size(); i++)
        {
            if(!rec[gr[curr][i]])
                dfs(gr[curr][i], gr);
            else
            {
                isCycle = true;
                return;
            }
        }
        ans.push_back(curr);
        visited[curr] = true;
        rec[curr] = 0; 
    }
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<vector<int>> gr(numCourses);
    for(int i=0; i<prerequisites.size(); i++)
    {
        gr[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }

    visited.resize(numCourses,false);
    rec.resize(numCourses,0);

    for(int i=0; i<numCourses; i++)
    {
        dfs(i,gr);
        if(isCycle)
        {
            ans.clear();
            return ans;
        }
    }
    return ans;
}