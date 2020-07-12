//
// Created by LWZ on 2020/1/7.
//
#include "iostream"
#include "vector"
#include "queue"
#include "map"
#include "string"
using namespace std;

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n=watchedVideos.size();
        map<int,int> idlevel;
        int l=1;
        queue<int> nextlevel;
        for(int i=0;i<friends[id].size();i++){
            idlevel[friends[id][i]]=1;
            nextlevel.push(friends[id][i]);
        }
        while (l<level){
            l++;
            int len=nextlevel.size();
            for(int i=0;i<len;i++){
                int f=nextlevel.front();
                for(int j=0;j<friends[f].size();j++){
                    if(idlevel[friends[f][j]]==0){
                        idlevel[friends[f][j]]=l;
                        nextlevel.push(friends[f][j]);
                    }
                }
                nextlevel.pop();
            }
        }
        map<string,int> count;
        if (l==level){
            int len=nextlevel.size();
            //cout<<len;
            while (!nextlevel.empty()){
                int f=nextlevel.front();
                if(f!=id){
                    for(int j=0;j<watchedVideos[f].size();j++){
                        count[watchedVideos[f][j]]++;
                        //cout<<watchedVideos[f][j]<<" "<<count[watchedVideos[f][j]]<<endl;
                    }
                }
                nextlevel.pop();
            }
        }
        vector<string> res;
        vector<pair<int,string>> c;
        map<string,int>::iterator ite;
        for(ite=count.begin();ite!=count.end();ite++){
            pair<int,string> t={ite->second,ite->first};
            c.push_back(t);
        }
        sort(c.begin(),c.end());
        for(int i=0;i<c.size();i++){
            //cout<<c[i].first<<" "<<c[i].second<<endl;
            res.push_back(c[i].second);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<string>> w={{"A","B"},{"C"},{"B","C"},{"D"}};
    vector<vector<int>> f={{1,2},{0,3},{0,3},{1,2}};
    s.watchedVideosByFriends(w,f,0,1);

    system("pause");
    return 0;
}

