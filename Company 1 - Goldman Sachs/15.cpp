#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> v, int n, int k)
{
    map<int,int> m;
    for(int i=0; i<n; i++)
    {
        m[v[i]%k]++;
    }
    for(int i=0; i<n; i++)
    {
        int r = v[i]%k;
        if(r==0)
        {
            if(m[0]%2) return 0;
        }
        else if(m[r]!=m[k-r]) return 0;
    }
    return 1;
}

int main()
{
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    cout<<solve(v,n,k);
    return 0;
}


