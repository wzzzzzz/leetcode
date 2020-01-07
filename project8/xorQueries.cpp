//
// Created by LWZ on 2020/1/6.
//
#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=queries.size();
        int len=arr.size();
        vector<vector<int>> q(len,vector<int>(len,0));
        vector<int> res={};
        for(int i=0;i<n;i++){
            int s=queries[i][0];
            int e=queries[i][1];
            if(q[s][e]==0){
                int r=arr[s];
                q[s][s]=r;
                //从上下左右计算
                for(int i=s+1;i<=e;i++){
                    r=r^arr[i];
                    q[s][i]=r;
                }
                cout<<r<<endl;
                res.push_back(r);
            }
            else {
                cout << q[queries[i][0]][queries[i][1]] << endl;
                res.push_back(q[queries[i][0]][queries[i][1]]);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> a={15,8,8,8,15};
    vector<vector<int>> q={{2,2},{3,3}};
    s.xorQueries(a,q);

    system("pause");
    return 0;
}

