#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> a, int n)
{
    int i, ans = 0, c = 0;
    for (int i = 1; i < n; i++)
    {
        /* code */
        if(a[i]==a[i-1]) c = 0;
        else if(a[i]>a[i-1]) c++;
        else if(c>0)
        {
            while (i<n && a[i]<a[i-1])
            {
                /* code */
                c++; i++;
            }
            ans = max(ans, c+1);
            c = 0; i--;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int res = solve(a,n);
    cout<<res;
    return 0;
}