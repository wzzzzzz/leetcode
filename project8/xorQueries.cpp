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
        vector<int> q(len,0);
        q[0]=arr[0];
        for(int i=1;i<len;i++){
            q[i]=q[i-1]^arr[i];
        }
        vector<int> res={};
        for(int i=0;i<n;i++){
            int s=queries[i][0];
            int e=queries[i][1];
            int t=s>0?q[e]^q[s-1]:q[e];
            cout<<t<<endl;
            res.push_back(t);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> a={1,3,4,8};
    vector<vector<int>> q={{0,1},{1,2},{0,3},{3,3}};
    s.xorQueries(a,q);

    system("pause");
    return 0;
}

