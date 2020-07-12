//
// Created by LWZ on 2019/12/27.
//
#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            int t=1;
            nums[i]/=10;
            while(nums[i]>0){
                t++;
                nums[i]/=10;
            }
            if(t%2==0) res++;
        }
        cout<<res;
        return res;
    }
};

int main(){
    Solution s;
    vector<int> n={555,901,482,1771};
    s.findNumbers(n);

    system("pause");
    return 0;
}