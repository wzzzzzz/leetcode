//
// Created by LWZ on 2020/2/1.
//
#include "iostream"
#include "vector"
#include "string"
#include "stack"
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int len=tokens.size();
        stack<string> f;
        stack<int> nums;
        for(int i=0;i<len;i++){
            string tmp=tokens[i];
            int flag=0;
            if(tmp.size()>1||(tmp[0]<='9'&&tmp[0]>='0')) flag=1;
            //cout<<i<<" "<<flag<<endl;
            if((!f.empty())&&((f.top()[0]=='*'||f.top()[0]=='/')||(tmp!="*"||tmp!="/"))){
                int b=nums.top();
                nums.pop();
                int a=nums.top();
                nums.pop();
                int r=cal(f.top()[0],a,b);
                nums.push(r);
                i--;
                f.pop();
                //cout<<tmp<<" "<<a<<" "<<b<<" "<<r<<endl;
                continue;
            }
            if(flag==1){
                int num=0;
                int j=0;
                if(tmp[0]=='-') j++;
                for(j;j<tmp.size();j++){
                    num*=10;
                    num+=(tmp[j]-'0');
                }
                if(tmp[0]=='-') num=0-num;
                //cout<<num<<endl;
                nums.push(num);
            }
            else{
                //cout<<tmp<<endl;
                f.push(tmp);
            }
        }
        while(!f.empty()){
            char ftmp=f.top()[0];
            f.pop();
            int b=nums.top();
            nums.pop();
            int a=nums.top();
            nums.pop();
            nums.push(cal(ftmp,a,b));
        }
        int res=nums.top();
        cout<<res;
        return res;
    }
    int cal(char ftmp,int a,int b){
        int r=0;
        switch (ftmp){
            case '*': r=a*b;break;
            case '/': r=a/b;break;
            case '+': r=a+b;break;
            case '-': r=a-b;break;
        }
        return r;
    }
};

int main(){
    Solution s;
    vector<string> t={"3","11","5","+","-"};
    s.evalRPN(t);

    system("pause");
    return 0;
}