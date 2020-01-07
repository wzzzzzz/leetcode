//
// Created by LWZ on 2020/1/6.
//
#include "iostream"
#include "vector"
#include "string"
using namespace std;

class Solution {
public:
    string freqAlphabets(string s) {
        int len=s.length();
        string res="";
        for(int i=0;i<len;){
            if(i+2<len&&s[i+2]=='#'){
                int t=(s[i]-'0')*10+s[i+1]-'0'-1;
                char tmp=t+'a';
                //cout<<t<<" "<<tmp<<endl;
                res+=tmp;
                i+=3;
            }
            else {
                char tmp=s[i]-'0'-1+'a';
                //cout<<tmp<<endl;
                res+=tmp;
                i++;
            }
        }
        //cout<<res;
        return res;
    }
};

int main(){
    Solution s;
    string ss="12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#";
    s.freqAlphabets(ss);

    system("pause");
    return 0;
}
