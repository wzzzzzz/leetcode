//
// Created by LWZ on 2020/2/9.
//
#include "iostream"
#include "vector"
#include "queue"
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root== nullptr) return 0;
        if((!root->left)&&(!root->right)) return root->val;
        queue<TreeNode*> q;
        q.push(root);
        int res=0;
        while (!q.empty()){
            TreeNode* r=q.front();
            q.pop();
            if((!r->left)&&(!r->right)) res+=r->val;
            if(r->left){
                r->left->val+=r->val*10;
                q.push(r->left);
            }
            if(r->right){
                r->right->val+=r->val*10;
                q.push(r->right);
            }
        }

        return res;
    }
};


int main(){
    TreeNode n1(4);
    TreeNode n2(9);
    TreeNode n3(0);
    TreeNode n4(5);
    TreeNode n5(1);
    n1.left=&n2;
    n1.right=&n3;
    n2.left=&n4;
    n2.right=&n5;
    Solution s;
    cout<<s.sumNumbers(&n1);

    system("pause");
    return 0;
}