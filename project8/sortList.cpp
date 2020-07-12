//
// Created by LWZ on 2020/1/30.
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
    ListNode* sortList(ListNode* head) {
        if(head== nullptr){
            return head;
        }
        ListNode* h=head;
        ListNode* e=head->next;
        if(e== nullptr){
            return head;
        }
        int count=1;
        //两两
        int tmp=0;
        while (h!= nullptr&&e!= nullptr){
            count++;
            if(h->val>e->val){
                tmp=e->val;
                e->val=h->val;
                h->val=tmp;
            }
            h=e->next;
            if(h!= nullptr){
                count++;
                e=h->next;
            }
        }
        //ListNode* end = h==nullptr?e:h;
        //cout<<count<<endl;

        tmp=4;
        while (tmp<count){
            //cout<<"a"<<tmp<<endl;
            head=merge(head,tmp,count);
            tmp*=2;
        }
        //cout<<"a"<<tmp<<endl;
        head=merge(head,tmp,count);
        //cout<<"b"<<tmp<<endl;
        while(head!= nullptr){
            cout<<head->val<<endl;
            head=head->next;
        }
        return head;
    }
    ListNode* merge(ListNode* head,int len,int count){
        ListNode* b=head;
        ListNode* p;
        ListNode* n = new ListNode(-1);
        head=n;
        int tmp=count/len;
        while (tmp>=0&&b!= nullptr){
            //cout<<"c"<<tmp<<endl;
            int t=1;
            p=b->next;
            int flag=0;
            while(t<len/2){
                if(p == nullptr) {
                    n->next=b;
                    n=n->next;
                    flag=1;
                    break;
                }
                p=p->next;
                t++;
            }
            if(flag==1) {
                while(n->next!= nullptr){
                    n=n->next;
                }
                break;
            }
            t=0;
            int t1=0;
            int t2=0;
            while(t<len&&t1<len/2&&t2<len/2&&p!=nullptr){
                //cout<<"d"<<b->val<<p->val<<endl;
                if(b->val<p->val){
                    //cout<<"hhh111"<<b->val<<endl;
                    n->next=b;
                    b=b->next;
                    t1++;
                }
                else{
                    //cout<<"hhh222"<<p->val<<endl;
                    n->next=p;
                    p=p->next;
                    t2++;
                }
                n=n->next;
                t++;
            }
            if(t1<len/2&&b!=nullptr){
                //cout<<"eee"<<n->val<<b->val<<endl;
                n->next=b;
                while(t1<len/2&&b!=nullptr){
                    //cout<<"hhhhh"<<endl;
                    b=b->next;
                    n=n->next;
                    t1++;
                }
            }
            if(t2<len/2&&p!=nullptr){
                //cout<<"eee222"<<p->val<<endl;
                n->next=p;
                while(t2<len/2&&p!=nullptr){
                    p=p->next;
                    n=n->next;
                    t2++;
                }
            }
            b=p;
            tmp--;
        }
        n->next= nullptr;
        return head->next;
    }
};

int main(){
    Solution s;
    ListNode l0(5);
    ListNode l1(2);
    ListNode l2(1);
    ListNode l3(3);
    ListNode l4(6);
    ListNode l5(4);
    l0.next=&l1;
    l1.next=&l2;
    l2.next=&l3;
    l3.next=&l4;
    l4.next=&l5;
    s.sortList(&l0);

    system("pause");
    return 0;
}

