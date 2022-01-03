#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> v, long long n)
{
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<n; i++)
    {
        pq.push(v[i]);
        if(pq.size()>10) pq.pop();
    }
    while (!pq.empty())
    {
        int x = pq.top();
        pq.pop();
        ans.push_back(x);
    }
    return ans;
}

int main()
{
    long long int n;
    vector<int> res;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    res = solve(v,n);
    for(auto x: res)
        cout<<x<<" ";
    return 0;
}


