#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> v, int n)
{
    vector<int> ans(2);
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[v[i]]++;
    }
    for(int i=1;i<n+1;i++){
        if(mp[v[i]]>1){
            ans[0]=v[i];
        }
    }
    for(int i=1;i<=n;i++){
        if(mp[i]==0){
            ans[1]=i;
            break;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    vector<int> res = solve(v,n);
    cout<<res[0]<<" "<<res[1];
    return 0;
}


