#include<bits/stdc++.h>
using namespace std;

string find(string s, int k)
{
    int n = s.length();
    int maxi = INT_MIN;
    for(int i=0; i<k; i++)
    {
        int ind = -1;
        for(int j=n-1; j>=i; j--)
        {
            if(maxi < s[j]-'0')
            {
                ind = i;
                maxi = s[j]-'0';
            }
        }
        swap(s[i],s[ind]);
    }
    return s;
}