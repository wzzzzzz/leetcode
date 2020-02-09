//
// Created by LWZ on 2020/2/1.
//

#include "iostream"
#include "vector"
#include "string"
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int len=s.size();
        int i=0;
        int j=0;
        string res="";
        while(i<len&&j<len){
            //cout<<i<<" "<<j<<endl;
            while(i<len&&s[i]==' ') i++;
            j=i+1;
            while(j<len&&s[j]!=' ') j++;
            if(i>=len&&j>=len) break;
            string tmp=s.substr(i,j-i);
            i=j;
            res=tmp+" "+res;
        }
        res=res.substr(0,res.size()-1);
        //cout<<res;
        return res;
    }
};

int main(){
    Solution s;
    string ss="a good   example  ";
    s.reverseWords(ss);

    system("pause");
    return 0;
}

