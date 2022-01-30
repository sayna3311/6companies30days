#include<bits/stdc++.h>
using namespace std;
    
vector<int> find3Numbers(vector<int> arr, int n) {
    int max = n - 1;
    int min = 0;
    int i;

    int *smaller = new int[n];
    smaller[0] = -1; // first entry will always be -1
    for (i = 1; i < n; i++) {
        if (arr[i] <= arr[min]) {
            min = i;
            smaller[i] = -1;
        } else
            smaller[i] = min;
    }

    int *greater = new int[n];
    greater[n - 1] = -1; // last entry will always be -1
    for (i = n - 2; i >= 0; i--) {
        if (arr[i] >= arr[max]) {
            max = i;
            greater[i] = -1;
        } else
            greater[i] = max;
    }
    vector<int> r;

    for (i = 0; i < n; i++) {
        if (smaller[i] != -1 && greater[i] != -1) {

            r.push_back(arr[smaller[i]]);
            r.push_back(arr[i]);
            r.push_back(arr[greater[i]]);
            return r;
        }
    }

    delete[] smaller;
    delete[] greater;
    return r;
}