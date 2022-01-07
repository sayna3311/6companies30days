#include <bits/stdc++.h>
using namespace std;

vector<string> helper(string s, vector<string> v, int n)
{
    int l = s.length();
    map<string,int> mp;
    for(int i=0; i<n; i++)
    {
        if(v[i].length() >= l and v[i].substr(0,l)==s)
            mp[v[i]]++;
    }
    vector<string> temp;
    for (auto i: mp)
    {
        temp.push_back(i.first);
    }
    if(temp.size()==0)
        temp.push_back("0");
    return temp;
}

vector<vector<string>> solve(int n, vector<string> v, string s)
{
    vector<vector<string>> res;
    for(int i=1; i<=s.length(); i++)
    {
        vector<string> temp = helper(s.substr(0,i),v,n);
        res.push_back(temp);
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin>>v[i];
    }
    string s;
    cin>>s;
    vector<vector<string>> res = solve(n,v,s);
    for(auto x: res)
    {
        for(auto y: x)
        {
            cout<<y<<" ";
        }
        cout<<"\n";
    }
    return 0;
}








