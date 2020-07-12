//
// Created by LWZ on 2020/2/10.
//
#include <string>
#include <algorithm>
#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int len=nums.size();
        vector<string>num(len,"");
        for(int i=0;i<len;i++){
            num[i]=to_string(nums[i]);
        }

        vector<vector<string>> order(10,vector<string>());
        for(int i=0;i<len;i++){
            order[num[i][0]-'0'].push_back(num[i]);
        }
        string res="";
        for(int i=9;i>=0;i--){
            res+=number(order[i]);
        }
        if(res[0]=='0') res="0";
        cout<<res;
        return res;
    }
    static bool sortstrnum(string a,string b){
        int la=a.size();
        int lb=b.size();
        int i=0,j=0;
        //false是a比较小，true是a比较大
        bool res=false;
        while (i<la&&j<lb){
            if(a[i]<b[j]){
                return false;
            }
            else if(a[i]>b[j]) return true;
            else{
                i++;
                j++;
            }
        }
        while(i<la) {
            j=0;
            while(j<lb){
                if(a[i]<b[j]) return false;//选的短的
                else if(a[i]>b[j]) return true;
                else j++;
            }
            i++;
        }
        while(j<lb) {
            i=0;
            while(i<la){
                if(a[i]>b[j]) return true;//选的短的
                else if(a[i]<b[j]) return false;
                else i++;
            }
            j++;
        }
        return res;
    }
    string number(vector<string>& nums){
        int len=nums.size();
        string res;
        sort(nums.begin(),nums.end(),sortstrnum);
        for(int i=0;i<len;i++){
            //cout<<nums[i]<<" ";
            res+=nums[i];
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> n={2281,2};
    s.largestNumber(n);

    system("pause");
    return 0;
}
