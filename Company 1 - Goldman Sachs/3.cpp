#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int>& a, int n, long long k)
{
    int i=0, j=0, ans=0;
    long long prod = 1;
    while(j<n)
    {
        prod *= a[j];
        if(prod >= k)
        {
            while(i<=j && prod >= k)
            {
                prod /= a[i];
                i++;
            }
        }
        ans += j-i+1;
        j++;
    }
    return ans;
    cout<<ans;
}

int main()
{
    int n;
    long long int k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int ans = solve(a,n,k);
    cout<<ans<<"\n";
    return 0;
}