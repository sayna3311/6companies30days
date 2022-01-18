#include <bits/stdc++.h>
using namespace std;

string solve(string str) {
    int n = str.size();
    if(n<=3) return "-1";
    string half = str.substr(0,n/2);
    if( next_permutation( half.begin() , half.end() ) )
    {
        string ans=half;
        if(n&1)
        {
            ans+=str[n/2];
        }
        reverse(half.begin() , half.end());
        ans+=half;
        return ans;
    }
    return "-1";
}

int main()
{
    string s;
    cin>>s;
    cout<<solve(s);
    return 0;
}