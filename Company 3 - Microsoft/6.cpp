#include<bits/stdc++.h>
using namespace std;

void helper(vector<int> a, int idx, int &n, string &curr, vector<string> &res, string map[])
{
    if(idx==n)
    {
        res.push_back(curr);
        return;
    }
    for (char ch: map[a[idx]])
    {
        curr.push_back(ch);
        helper(a,idx+1,n,curr,res,map);
        curr.pop_back();
    }
    
}

vector<string> solve(vector<int> a, int n)
{
    string curr = "";
    vector<string> res;
    string map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    helper(a,0,n,curr,res,map);
    return res;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i<n; i++)
    {
        cin>>a[i];
    }
    vector<string> res = solve(a,n);
    for(auto x: res)
        cout<<x<<" ";
    return 0;
}