#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> v, int n, int t)
{
    int mini = INT_MAX;
    int s = 0, c=0, l=0, r = 0;
    while(l<n)
    {
        if(s >= t)
        {
            mini = min(mini,c);
            s -= v[l++];
            c--;
        }
        else{
            if(r<n)
            {
                s += v[r++];
                c++;
            }
            else break;
        }
    }
    return mini==INT_MAX? 0: mini;
}

int main()
{
    int target;
    cin>>target;
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    cout<<solve(v,n,target);
    return 0;
}


