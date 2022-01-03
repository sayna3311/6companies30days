#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
    return (n*(n+1)*(2*n + 1))/6;
}

int main()
{
    int n;
    cin>>n;
    cout<<solve(n);
    return 0;
}


