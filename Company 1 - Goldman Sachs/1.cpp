#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> solve(int n, vector<string>& v)
{
    vector<vector<string> > ans;
    unordered_map<string,vector<string> > mp;
    for(int i=0; i<n; i++)
    {
        string word = v[i];
        sort(word.begin(),word.end());
        mp[word].push_back(v[i]);
    }

    for(auto x: mp)
    {
        ans.push_back(x.second);
    }
    
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }

    vector<vector<string>> res = solve(n,v);
    for(int i=0; i<res.size(); i++)
    {
        for(int j=0; j<res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}


