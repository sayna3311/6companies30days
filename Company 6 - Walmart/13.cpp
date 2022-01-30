#include<bits/stdc++.h>
using namespace std;

string kthLargestNumber(vector<string>& nums, int k) {
    sort(nums.begin(), nums.end(), [](string &a, string &b) {
        if (a.size() < b.size()) {
            return true;
        }
        else if (a.size() == b.size()) {
            for (int i = 0; i < a.size(); i++) {
                if (a[i] < b[i]) {
                    return true;
                }
                else if (a[i] > b[i]) {
                    return false;
                }
            }
        }
        return false;
    });
    
    return nums[nums.size() - k];
}