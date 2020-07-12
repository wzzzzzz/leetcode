//
// Created by LWZ on 2019/12/12.
//
#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int tmp=0;
        int plus=0;
        int multiple=1;
        while(n>0){
            tmp=n%10;
            n=n/10;
            plus+=tmp;
            multiple*=tmp;
        }
        cout<<plus<<" "<<multiple;
        return multiple-plus;
    }
};

int main(){
    Solution s;
    s.subtractProductAndSum(4421 );
    system("pause");
    return 0;
}


