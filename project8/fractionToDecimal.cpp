//
// Created by LWZ on 2020/2/6.
//
#include "iostream"
#include "stdio.h"
#include "stdlib.h"
#include "vector"
#include "string"
#include "map"
#include "cstdlib"
#include "sstream"
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        bool zhengfu=true;//true表示是正的
        long long int n=numerator;
        long long int de=denominator;
        if(numerator==-2147483648&&denominator==-2147483648) return"1";
        if((de<0&&n>0)||(de>0&&n<0)){
            de=-1*de;
            zhengfu=false;
        }

        string res="";
        map<pair<long long int,int>,int> d;
        vector<int> resnum;
        stringstream ss;
        string t;
        int r=n/de;
        long long int l=n%de;
        d[{l,r}]=0;
        ss<<r;
        ss>>t;
        ss.clear();
        res+=t;
        if(l!=0) res+='.';
        int i=res.size();
        int ind=0;
        while (l!=0){
            l*=10;
            n=l;
            r=n/de;
            l=n%de;
            //cout<<l<<" "<<r<<endl;
            if(d.find({l,r})!=d.end()){
                cout<<"!!"<<endl;
                ind=d[{l,r}];
                break;
            }
            d[{l,r}]=i;
            i++;

            ss<<r;
            ss>>t;
            ss.clear();
            res+=t;
        }

        cout<<ind<<endl;
        if(l!=0){
            string a=res;
            string b=res.substr(0,ind);
            res=b+'('+a.substr(ind)+')';
        }
        if (!zhengfu&&res[0]!='-') res='-'+res;
        if(zhengfu&&res[0]=='-') res=res.substr(1,res.size()-1);
        cout<<res;
        return res;
    }
};

int main(){
    Solution s;
    s.fractionToDecimal(1,333);

    system("pause");
    return 0;
}

