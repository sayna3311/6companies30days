#include<bits/stdc++.h>
using namespace std;

vector<int> solve(int a[], int n)
{
    stack<int> s;
    s.push(a[n-1]);
    for(int i=n-2; i>=0; i--)
    {
        if(s.top()<=a[i])
            s.push(a[i]);
    }

    vector<int> ans;
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    vector<int> ans = solve(a,n);
    for(auto x: ans)
    {
        cout<<x<<" ";
    }
    return 0;
}