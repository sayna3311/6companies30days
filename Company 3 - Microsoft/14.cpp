#include <bits/stdc++.h>
using namespace std;

int solve(int D){
        int steps = 0;
        int sum = 0;
        while(sum<D) {
            sum+=steps;
            steps++;
        }
        while((sum-D)%2) {
            sum+=steps;
            steps++;
        }
        return steps-1;
    }

int main()
{
    int d;
    cin>>d;
    cout<<solve(d);
    return 0;
}