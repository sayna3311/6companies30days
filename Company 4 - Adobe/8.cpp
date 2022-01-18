#include <bits/stdc++.h>
using namespace std;

int atoi(string str) {
    int ans=0;
    int flag=0;
    int n=str.length();
    int i=0;
    if(str[i]=='-'){
        i++,flag=1;
    }
    for(i;i<n;i++){
    if(str[i]<48 || str[i]>57)
    return -1;
    else{
        ans=ans*10+((int)str[i]-'0');
    }
    }
    if(flag==1)
    ans*=-1;
    return ans;
}

int main()
{
    string s;
    cin>>s;
    cout<<atoi(s);
    return 0;
}