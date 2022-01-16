#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>ans;
void rec(int ind, int total, vector<int>temp, vector<int>arr, int k)
{
    if(total == k)
    {
        if(temp.size() == 4)
            ans.push_back(temp);
        return;
    }
    
    if(ind >= arr.size() or total > k)
        return;
    
    temp.push_back(arr[ind]);
    rec(ind+1, total + arr[ind], temp, arr, k);
    temp.pop_back();
    
    while( ind < arr.size()-1 and arr[ind] == arr[ind+1])
        ind = ind + 1;
    
    rec(ind+1, total, temp, arr, k);
    
}

vector<vector<int> > fourSum(vector<int> &arr, int k) 
{
    sort(arr.begin(),arr.end());
    rec(0,0,{},arr,k);
    return ans;
}

int main()
{
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin>>v[i];
    }
    vector<vector<int>> res = fourSum(v,k);
    for(auto x: res)
    {
        for(auto y: x)
            cout<<y<<" ";
        cout<<"\n";
    }
}