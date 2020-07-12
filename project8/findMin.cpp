//
// Created by LWZ on 2020/2/1.
//

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int len=nums.size();
        int l=0;
        int r=len-1;
        int m=0;
        int res=0;
        if(nums[l]<nums[r]){
            res=nums[l];
            return res;
        }
        while (l<r){
            m=(l+r)/2;
            if(nums[l]<=nums[m]&&nums[l]>nums[r]){
                l=m+1;
            }
            else if(nums[m]<=nums[r]&&nums[r]<nums[l]){
                if(m>0&&nums[m-1]>nums[m]){
                    res=nums[m];
                    return res;
                }
                r=m-1;
            }
            else if(nums[l]<=nums[m]&&nums[m]<=nums[r]){
                res=nums[l];
                return res;
            }
            cout<<l<<" "<<m<<" "<<r<<endl;
        }
        cout<<nums[l]<<" "<<nums[r];
        return nums[l];
    }
};

int main(){
    Solution s;
    vector<int> n={3,4,5,1,2};
    s.findMin(n);

    system("pause");
    return 0;
}

