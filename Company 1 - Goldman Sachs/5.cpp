#include <bits/stdc++.h>
using namespace std;

unsigned long long solve(int n) {
	   set <long long int> s;
	   s.insert(1);
	   n--;
	   while(n--){
	        auto it = s.begin();
	        long long int x = *it;
	        s.erase(it);
	        s.insert(x*2);
	        s.insert(x*3);
	        s.insert(x*5);
	    } 
        return *s.begin();
}

int main()
{
    int n;
    cin>>n;
    cout<<solve(n);
}