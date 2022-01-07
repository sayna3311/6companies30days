#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> a, int n,int k)
{
    vector<int> ans;
    priority_queue<pair<int,int>> pq;
    int i=0, j=0;
    while (j<n)
    {
        if(j-i+1 < k)
        {
            pq.push({a[j],j});
            j++;
        }
        else{
            pq.push({a[j],j});
            int t = pq.top().first;
            ans.push_back(t);
            while (!pq.empty())
            {
                if(pq.top().second <= i)
                    pq.pop();
                else    
                    break;
            }
            i++; j++;
        }
    }
    return ans;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    vector<int> res = solve(a,n,k);
    for(auto i: res)
    {
        cout<<i<<" ";
    }
    return 0;
}