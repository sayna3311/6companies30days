#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 1e9 + 7;

void func(int o,int c,string op,vector<string>&ans){
    if(c<o||c<0||o<0)return;
    if(c==0&&o==0){
        ans.push_back(op);
        return;
    }
    func(o-1,c,op+"(",ans);
    func(o,c-1,op+")",ans);
}

vector<string> solve(int n)
{
    vector<string>ans;
    func(n,n,"",ans);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<string> res = solve(n);
    for(auto x: res)
        cout<<x<<endl;
    return 0;
}