#include<bits/stdc++.h>
using namespace std;

class MountainArray{
    public:
    int get(int index);
    int length();
};

int search(int target, MountainArray &mount)
{
    int peak = 0;
    int end = (mount.length()) - 1;

    while(peak!=end)
    {
        int mid = (peak + end)/2;
        int x = mount.get(mid);
        if(x<mount.get(mid+1))
            peak = mid + 1;
        else
            end = mid;
    }

    int index = -1;
    int start = 0;
    end = peak;

     while(start <= end)
    {
        int mid = start + (end-start)/2;
        int x = mount.get(mid);
        if(x ==target)
        {
            index = mid;
            break;
        }
        else if(x <target)
            start = mid+1;
        else
            end = mid-1;
    }

    if(index!=-1)
        return index;
    
    start = peak+1;
    end = mount.length()-1;
    
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        int x = mount.get(mid);
        if(x ==target)
    {
        index = mid;
        break;
    }
    else if(x <target)
        end = mid-1;
    else
        start = mid+1;
    }
    
    
    return index;
    
}