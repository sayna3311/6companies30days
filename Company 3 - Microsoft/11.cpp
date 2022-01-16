#include <bits/stdc++.h>
using namespace std;

vector<string> solve(int N)
{
	queue<string> res;
	res.push("1");
	
	vector<string> ans;
	for(int i = 0; i < N; ++i) {
	    
	    string str= res.front();
        res.pop();
	    res.push(str + "0");
	    res.push(str + "1");
	    ans.push_back(str);
	}
	return ans;
}


int main()
{
    int n;
    cin>>n;
    vector<string> res = solve(n);
    for(auto x: res)
        cout<<x<<" ";
    return 0;
}