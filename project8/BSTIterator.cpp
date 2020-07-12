//
// Created by LWZ on 2020/2/8.
//
#include "iostream"
#include "vector"
#include "stack"
#include "queue"
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
    queue<int> bst;
public:
    BSTIterator(TreeNode* root) {
        if(root== nullptr) return;
        stack<TreeNode> b;
        TreeNode* r=root;
        while (r||!b.empty()){
            if(r) {
                b.push(*r);
                r=r->left;
            }
            else {
                r = &b.top();
                b.pop();
                bst.push(r->val);
                r=r->right;
            }
        }
    }
    void res(){
        while (!bst.empty()){
            cout<<bst.front();
            bst.pop();
        }
    }
    /** @return the next smallest number */
    int next() {
        int r=bst.front();
        bst.pop();
        cout<<r<<endl;
        return r;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        cout<<!bst.empty()<<endl;
        return !bst.empty();
    }
};

int main(){
    TreeNode n1(7);
    TreeNode n2(3);
    TreeNode n3(15);
    TreeNode n4(9);
    TreeNode n5(20);
    n1.left=&n2;
    n1.right=&n3;
    n3.left=&n4;
    n3.right=&n5;
    BSTIterator *b=new BSTIterator(&n1);
    //b->res();
    b->next();
    b->hasNext();
    b->next();

    system("pause");
    return 0;
}