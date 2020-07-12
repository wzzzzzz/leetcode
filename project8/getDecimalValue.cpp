//
// Created by LWZ on 2019/12/16.
//
#include "iostream"
#include "vector"
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res=0;
        while (head!= nullptr){
            res*=2;
            res+=head->val;
            head=head->next;
        }
        cout<<res<<endl;
        return res;
    }
};

int main(){
    Solution s;
    ListNode h1(0);
    ListNode h2(0);
    ListNode h3(1);
    h1.next=&h2;
    //h2.next=&h3;
    s.getDecimalValue(&h1);

    system("pause");
    return 0;
}
