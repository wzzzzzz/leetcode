# 第八十三题-链表去掉重复项

### 题目

> 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

### 举例

> ```
> 输入: 1->1->2
> 输出: 1->2
> 
> 输入: 1->1->2->3->3
> 输出: 1->2->3
> ```

### 思路

* 基本思路：while循环。用两个指针，一个指向重复的头，一个指向重复的尾，每次循环检查两个指针的值是否相等，不等就把头指针的next指向尾指针，每次循环把尾指针后移。循环结束后检查最后一个尾指针是否与头指针值相等，相等就把当前的next指向下一个的next。
* solution：while循环。一个指针，每次检查指针值和指针下一个的值是否相等，相等就把当前的next指向下一个的next，否则就把指针后移。

### 源码

* 基本思路：

  ```c++
  class Solution {
  public:
      ListNode* deleteDuplicates(ListNode* head) {
  		if (!head || !head->next) {
  			return head;
  		}
          ListNode *tmp = head;
  		ListNode *t = head;
  		while (tmp->next) {
  			tmp = tmp->next;
  			if (tmp->val != head->val) {
  				head->next = tmp;
  				head = head->next;
  			}
  		}
  		if (tmp->val == head->val) {
  			head->next = tmp->next;
  		}
  		return t;
      }
  };
  ```

* solution：

  ```c++
  class Solution {
  public:
      ListNode* deleteDuplicates(ListNode* head) {
  		if (!head || !head->next) {
  			return head;
  		}
  		ListNode *t = head;
  		while (head && head->next) {
  			if (head->val == head->next->val) {
  				head->next = head->next->next;
  			}
  			else head = head->next;
  		}
  		return t;
      }
  };
  ```


### 语法

用while循环时，注意条件与的运行方式是从第一项条件开始的。因此不能这样写while (head->next && head)