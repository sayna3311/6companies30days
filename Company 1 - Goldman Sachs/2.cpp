#include <bits/stdc++.h>
using namespace std;

int overlap(int l1[], int l2[], int r1[], int r2[])
{
    if(l1[0]>r2[0] || l2[0]>r1[0])
        return false;
    if(l1[1]<r2[1] || l2[1]<r1[1])
        return false;
    return true;
}

int main()
{
    int l1[2], l2[2], r1[2], r2[2];
    cin>>l1[0]>>l1[1]>>r1[0]>>r1[1]>>l2[0]>>l2[1]>>r2[0]>>r2[1];
    int ans = overlap(l1,l2,r1, r2);
    cout<<ans<<"\n";
    return 0;
}


