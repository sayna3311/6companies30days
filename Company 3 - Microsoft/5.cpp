#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, vector<int> p)
{
    vector<int> ans(n,-1);
    stack<pair<int,int>> st;
    for(int i=0; i<n; i++)
    {
        if(!st.empty() and st.top().first <= p[i])
        {
            while (!st.empty() and st.top().first <= p[i])
            {
                st.pop();
            }
            if(!st.empty())
                ans[i] = st.top().second;
        }
        else if(!st.empty() and st.top().first > p[i])   
        {
            ans[i] = st.top().second;
        }
        st.push({p[i],i});
        ans[i] = i - ans[i];   
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i=0; i<n; i++)
    {
        cin>>p[i];
    }
    vector<int> res = solve(n,p);
    for(auto x: res)
        cout<<x<<" ";
    return 0;
}