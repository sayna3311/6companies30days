#include <bits/stdc++.h>
using namespace std;

string solve(string str)
{
    stack<int> st;
    string res = "";
    int c = 1;
    for(int i=0; i<str.size(); i++)
    {
        char x = str[i];
        if(x=='D') st.push(c++);
        else{
            st.push(c++);
            while (!st.empty())
            {
                char y = '0' + st.top();
                res.push_back(y);
                st.pop();
            }
        }
    }
    st.push(c++);
    while(!st.empty())
    {
        char z = '0' + st.top();
        res.push_back(z);
        st.pop();
    }
    return res;
}

int main()
{
    string str;
    cin>>str;
    cout<<solve(str);
    return 0;
}


