//
// Created by LWZ on 2019/12/16.
//
#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        unsigned int lowlen=10;
        unsigned int highlen=10;
        unsigned int l=0;
        unsigned int h=0;
        while(low>=lowlen){
            lowlen*=10;
        }
        lowlen/=10;
        l=low/lowlen;
        while(high>=highlen){
            highlen*=10;
        }
        highlen/=10;

        vector<int> res;
        for(unsigned int highl=lowlen;highl<=highlen;highl*=10){
            //cout<<highl<<"?";
            for(int i=1;i<10;i++){
                unsigned int t=i*highl;
                int k=i;
                for(int j=highl/10;j>0;j/=10){
                    k++;
                    if(k>9){
                        break;
                    }
                    t+=k*j;
                }
                if(k==10){
                    continue;
                }
                if(t>=low&&t<=high){
                    res.push_back(t);
                    cout<<t<<endl;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    s.sequentialDigits(1000,130000);

    system("pause");
    return 0;
}
