#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
long long power(long long x,long long y){
	long long result = 1;
    while (y > 0) {
    	if (y % 2 == 0){
        	x = (x%mod * x%mod)%mod;
           	y = y / 2;
        }
       	else{
   			result = (result%mod * x%mod)%mod;
       		y = y - 1;
       	}
 	}
 	return result%mod;
}