#include <bits/stdc++.h>
using namespace std;

vector<string> solve(string arr[], int n)
{
    map<string,int> m;
    int mx = 0; string s;
    vector<string> v;

    for(int i=0; i<n; i++)
    {
        m[arr[i]]++;
    }

    for(auto it: m)
    {
        if(it.second > mx)
        {
            mx = it.second;
            s = it.first;
        }
    }

    v.push_back(s);
    v.push_back(to_string(mx));
    return v;
}

int main()
{
    int n;
    cin>>n;
    string arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    vector<string> result = solve(arr,n);
    cout<<result[0]<<" "<<result[1];
    return 0;
}