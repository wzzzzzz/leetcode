//
// Created by LWZ on 2019/12/12.
//
#include "iostream"
#include "vector"
#include "map"
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int len=groupSizes.size();
        vector<vector<int>> res;
        map<int,vector<int>> m;
        map<int,vector<int>>::iterator ite;
        for(int i=0;i<len;i++){
            ite=m.find(groupSizes[i]);
            if(ite==m.end()){
                vector<int> *tmp=new vector<int>();
                tmp->push_back(i);
                m[groupSizes[i]]=*tmp;
            }
            else ite->second.push_back(i);
        }
        //cout<<m.size()<<endl;
        ite=m.begin();
        while(ite!=m.end()){
            int s=ite->second.size();
            if(ite->first==s){
                res.push_back(ite->second);
            }
            else{
                for(int i=0;i<s;i++){
                    if(i%(ite->first)==0) {
                        vector<int> *tmp = new vector<int>();
                        res.push_back(*tmp);
                    }
                    res[res.size()-1].push_back(ite->second[i]);
                }
            }
            ite++;
        }
//        for(int i=0;i<res.size();i++){
//            for(int j=0;j<res[i].size();j++){
//                cout<<res[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> t={2,1,3,3,3,2};
    s.groupThePeople(t);

    system("pause");
    return 0;
}