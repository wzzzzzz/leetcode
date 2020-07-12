//
// Created by LWZ on 2019/11/11.
//
#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n=colsum.size();
        vector<vector<int>> res(2,vector<int> (n,0));
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=colsum[i];
        }
        if(sum!=(upper+lower)){
            return vector<vector<int>> ();
        }
        int i=0;
        while(upper>0){
            if(colsum[i]<=upper){
                upper-=colsum[i];
                res[0][i]=colsum[i];
            }
            else{
                lower-=(colsum[i]-upper);
                res[0][i]=upper;
                res[1][i]=colsum[i]-upper;
                upper=0;
            }
            i++;
        }
        while (lower>0){
            lower-=colsum[i];
            res[1][i]=colsum[i];
            i++;
        }
        for(int i=0;i<n;i++){
            cout<<res[0][i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<res[1][i]<<" ";
        }

        return res;
    }
};

int main(){
    Solution s;
    vector<int> col={2,1,2,0,1,0,1,2,0,1};
    s.reconstructMatrix(5,5,col);
    system("pause");
    return 0;
}

