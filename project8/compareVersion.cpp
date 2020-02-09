//
// Created by LWZ on 2020/2/5.
//

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1=version1.size();
        int len2=version2.size();
        int i=0;
        int j=0;
        int res=0;
        int n1=0;
        int n2=0;
        while (i<len1||j<len2){
            //cout<<i<<" "<<j<<endl;
            if((i>=len1&&version2[j]=='.')||(j>=len2&&version1[i]=='.')||(i<len1&&j<len2&&version1[i]=='.'&&version2[j]=='.')){
                //cout<<"in.."<<n1<<" "<<n2<<endl;
                if(n1<n2){
                    res=-1;
                    return res;
                }
                else if(n2<n1){
                    res=1;
                    return res;
                }
                else{
                    i++;
                    j++;
                }
                n1=0;
                n2=0;
            }
            else{
                if(i<len1&&version1[i]!='.'){
                    int t=version1[i]-'0';
                    n1*=10;
                    n1+=t;
                    i++;
                }
                if(j<len2&&version2[j]!='.'){
                    int t=version2[j]-'0';
                    n2*=10;
                    n2+=t;
                    j++;
                }
            }
        }
        cout<<res<<" "<<n1<<" "<<n2<<endl;
        if(n1==0&&n2==0){
            res=0;
        }
        else if((i==len1&&j==len2)||(n1!=0||n2!=0)){
            if(n1<n2) res=-1;
            else if(n1>n2) res=1;
            else res=0;
        }
        cout<<res;
        return res;
    }
};

int main(){
    Solution s;
    s.compareVersion("1","0");

    system("pause");
    return 0;
}



