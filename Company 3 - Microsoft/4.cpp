#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<vector<int>> matrix, int r, int c) 
{
    vector<int> res;
    
    int left = 0, right = c - 1, top = 0, bottom = r - 1;

    while(top <= bottom && left <= right)
    {
        for(int i = left; i <= right; i++)
        {
            res.push_back(matrix[top][i]);
        }
        
        top++;
        
        for(int i = top; i <= bottom; i++)
        {
            res.push_back(matrix[i][right]);
        }
        
        right--;
        
        if(top <= bottom)
        {
            for(int i = right; i >= left; i--)
            {
                res.push_back(matrix[bottom][i]);
            }
            
            bottom--;
        }
        
        if(left <= right)
        {
            for(int i = bottom; i >= top; i--)
            {
                res.push_back(matrix[i][left]);
            }
            
            left++;
        }
    }
    
    return res;
}


int main()
{
    int r, c;
    cin>>r>>c;
    vector<vector<int>> matrix(r, vector<int> (c));

    for (int i = 0; i < r; i++)
    {
        for (int j=0; j<c; j++)
        {
            cin>> matrix[i][j];
        }
    }

    vector<int> res = solve(matrix, r, c);
    for(auto x: res)
    {
        cout<< x<<" ";
    }
    return 0;
    
}