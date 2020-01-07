//
// Created by LWZ on 2019/12/19.
//
#include "iostream"
#include "vector"
using namespace std;

//待解决！！！
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int res=0;
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> plus=mat;
        vector<vector<int>> p(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            p[0][j]=mat[0][j]<threshold?1:0;
        }
        for(int i=1;i<m;i++){
            p[i][0]=mat[i][0]<threshold?1:0;
            for(int j=0;j<n;j++){
                if(mat[i][j]<threshold){
                    if(p[i][j]+)
                }
                else p[i][j]=0;
            }
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> mat={
        {1,1,3,2,4,3,2},{1,1,3,2,4,3,2},{1,1,3,2,4,3,2}
    };
    s.maxSideLength(mat,4);

    system("pause");
    return 0;
}
