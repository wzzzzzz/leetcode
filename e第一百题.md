# 第一百题-二叉树是否相同

### 题目

> 给定两个二叉树，编写一个函数来检验它们是否相同。
>
> 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

### 举例

> ```
> 输入:       1         1
>           / \       / \
>          2   3     2   3
>         [1,2,3],   [1,2,3]
> 输出: true
> 
> 示例 2:
> 输入:      1          1
>           /           \
>          2             2
>         [1,2],     [1,null,2]
> 输出: false
> 
> 示例 3:
> 输入:       1         1
>           / \       / \
>          2   1     1   2
>         [1,2,1],   [1,1,2]
> 输出: false
> ```

### 思路

* 思路：先检查是否存在空树。检查父节点的值是否相同，然后分别检查左子和右子节点值是否相同。

### 源码

* 思路：

  ```c++
  /**
   * Definition for a binary tree node.
   * struct TreeNode {
   *     int val;
   *     TreeNode *left;
   *     TreeNode *right;
   *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   * };
   */
  class Solution {
  public:
      bool isSameTree(TreeNode* p, TreeNode* q) {
          if (p == NULL && q == NULL)
  			return true;
  		else if (p == NULL || q == NULL)
  			return false;
          if (p->val != q->val)
  			return false;
  		if (!isSameTree(p->left, q->left))
  			return false;
  		if (!isSameTree(p->right, q->right))
  			return false;
  
  		return true;
      }
  };
  ```



### 语法

vector初始化，可以初始化为几个X，可以用数组初始化，也可以用vector初始化。

vector有插入函数，也有删除函数