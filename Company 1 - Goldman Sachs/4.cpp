#include <bits/stdc++.h>
using namespace std;

string encode(string src)
{
    string ans = "";
    int n = src.length();
    char alp = src[0];
    int c = 0;
    for(int i=0; i<n; i++)
    {
        if(src[i]==alp)
        {
            c++;
        }
        else{
            ans += alp + to_string(c);
            alp = src[i];
            c = 1;
        }
    }
    ans += alp + to_string(c);
    return ans;
}

int main()
{
    string str;
    cin>>str;
    cout<<encode(str)<<"\n";
    return 0;
}


