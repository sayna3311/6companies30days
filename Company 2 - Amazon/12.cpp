#include <bits/stdc++.h>
using namespace std;

string solve(int n)
{
    string s="";
    while(n!=0)
    {
        n--;
        int r = n%26;
        s = string(1,r +'A') + s;
        n /= 26;
    }
    return s;
}

int main()
{
    int n;
    cin>>n;
    cout<<solve(n);
    return 0;
}
