#include <bits/stdc++.h>
using namespace std;

string solve(string s)
{
    int a[26] = {0};
    queue<int> q;
    for(int i=0; i<s.length(); i++)
    {
        a[s[i]-'a']++;
        if(a[s[i]-'a']==1) q.push(s[i]);
        while (!q.empty() && a[q.front()-'a']!=1)q.pop();
        if(q.empty())s[i]='#';
        else s[i]=q.front();
    }
    return s;
}

int main()
{
    string s;
    cin>>s;
    cout<<solve(s);
    return 0;
}