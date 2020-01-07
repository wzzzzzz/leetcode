//
// Created by LWZ on 2019/12/27.
//
#include "iostream"
#include "vector"
#include "algorithm"
#include "map"
using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0) return false;
        if(k==1) return true;
        map<int,int> count;
        for(int i=0;i<n;i++){
            count[nums[i]]++;
        }
        map<int,int>::iterator ite;
        for(ite=count.begin();ite!=count.end();ite++){
            //cout<<ite->first<<" "<<ite->second<<endl;
            if(ite->second<0) return false;
            if(ite->second==0) continue;
            for(int i=1;i<k;i++){
                count[ite->first+i]-=ite->second;
            }
            ite->second=0;
        }
        cout<<"true";
        return true;

//        sort(nums.begin(),nums.end());
//        int t=0;
//        while(t<n){
//            int s=t;
//            int i=s+1;
//            int count=1;
//            cout<<s<<" "<<nums[s]<<endl;
//            while(count<k){
//                if(i>=n) {
//                    return false;
//                }
//                cout<<count<<" "<<i<<" "<<nums[i]<<endl;
//                if(nums[s]+count==nums[i]){
//                    nums[i]=-1;
//                    count++;
//                }
//                i++;
//            }
//            nums[s]=-1;
//            //if(i==n) t=n;
//            while(t<i){
//                if(nums[t]!=-1){
//                    break;
//                }
//                t++;
//            }
//        }
//        cout<<"true";
//        return true;
    }
};

int main(){
    Solution s;
    vector<int> n={1,2,3,4,6,7};
    s.isPossibleDivide(n,3);

    system("pause");
    return 0;
}