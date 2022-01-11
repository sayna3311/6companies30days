#include<bits/stdc++.h>
using namespace std;

void solve(int n, vector<vector<int> >& matrix)
{
    for(int i=0; i<n; i++)
    reverse(matrix[i].begin(), matrix[i].end());
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        swap(matrix[i][j], matrix[j][i]);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int> (n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n;j++)
            cin>>v[i][j];
    }

    solve(n,v);
    for(auto x: v)
    {
        for(auto y: x)
        {
            cout<<y<<" ";
        }
        cout<<"\n";
    }
    return 0;
}