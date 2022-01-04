#include <bits/stdc++.h>
using namespace std;

string solve(string s)
{
    stack<int> c;
    stack<string> res;
    int i = 0;
    string curr = "";
    while(i<s.length())
    {
        if(isdigit(s[i]))
        {
            int n = 0;
            while (isdigit(s[i]))
            {
                n = 10*n + (s[i]-'0');
                i++;
            }
            c.push(n);
        }
        else if(s[i]=='[')
        {
            res.push(curr);
            curr = "";
            i++;
        }
        else if(s[i]==']')
        {
            int n = c.top();
            c.pop();
            string r = res.top();
            res.pop();
            for(int i=0; i<n; i++)
                r += curr;
            curr = r;
            i++;
        }
        else
        {
            curr += s[i];
            i++;
        }
    }
    return curr;
}

int main()
{
    string s;
    cin>>s;
    cout<<solve(s);
    return 0;
}


