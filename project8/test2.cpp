//
// Created by LWZ on 2019/9/21.
//
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int len=indices.size();
        vector<int> rows(n,0);
        vector<int> cols(m,0);
        int row=0;
        int col=0;
        for(int i=0;i<len;i++){
            rows[indices[i][0]]++;
            cols[indices[i][1]]++;
        }
        for(int i=0;i<n;i++){
            if(rows[i]%2==1){
                row++;
            }
        }
        for(int i=0;i<m;i++){
            if(cols[i]%2==0){
                col++;
            }
        }
        int res=row*col+(n-row)*(m-col);
        cout<<res<<endl;
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> indices = {{40,5}};
    s.oddCells(48,37,indices);

    system("pause");
    return 0;
}

