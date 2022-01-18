#include<bits/stdc++.h>
using namespace std;

vector<int> solve(int a[], int n, int s)
{
    vector<int> ans(2,-1);
    long long sum=0;
    int i=0;
    int j=0;
    while(j<n){
        if((sum+a[j])==s){
            ans[0]=i+1;
            ans[1]=j+1;
            break;
        }
        else if((sum+a[j])<s){
            sum+=a[j];
            j++;
        }
        else{
            sum=sum-a[i];
            i++;
        }
    }
    if(ans[0]==-1 && ans[1]==-1){
        ans.pop_back();
    }
    return ans;
}

int main()
{
    int n,s;
    cin>>n>>s;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    vector<int> res = solve(a,n,s);
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}