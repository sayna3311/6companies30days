#include <bits/stdc++.h>
using namespace std;

string gcdOfStrings(string str1, string str2) {

    if(str1+str2 != str2+str1)
        return "";

    if(str1 == str2){
        return str1;
    }
    
    if(str1.length() > str2.length()){
        return gcdOfStrings(str1.substr(str2.length()), str2);
        
    }
    
    if(str2.length() > str1.length()){
        return gcdOfStrings(str2.substr(str1.length()), str1);
        
    }
    
    
    return 0; 
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    cout<<gcdOfStrings(s1,s2)<<"\n";
}