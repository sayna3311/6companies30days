#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m, int k)
{
    if (n-k+1>=m) return m+k-1;
    m = m - (n-k+1);
    return (m%n)?(m%n):n;
}

int main()
{
    int n, m, k;
    cin>>n>>m>>k;
    cout<<solve(n,m,k);
    return 0;
}


