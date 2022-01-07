#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> a, int n, int k)
{
    vector<int> res;
    multiset<int,greater<int>> s;
    for(int i=0; i<n; i++)
    {
        s.insert(a[i]);
        if(s.size()>k)
        {
            s.erase(s.find(a[i-k]));
        }
        if(s.size()==k)
            res.push_back(*s.begin());
    }
    return res;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    vector<int> res = solve(a,n,k);
    for(auto x: res)
    {
        cout<<x<<" ";
    }
    return 0;
}