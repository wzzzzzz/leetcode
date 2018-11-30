# 第七十题——爬楼梯

### 题目

> 假设你正在爬楼梯。需要 *n* 阶你才能到达楼顶。
>
> 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
>
> **注意：**给定 *n* 是一个正整数。

### 举例

> ```
> 输入： 2
> 输出： 2
> 解释： 有两种方法可以爬到楼顶。
> 1.  1 阶 + 1 阶
> 2.  2 阶
> 
> 输入： 3
> 输出： 3
> 解释： 有三种方法可以爬到楼顶。
> 1.  1 阶 + 1 阶 + 1 阶
> 2.  1 阶 + 2 阶
> 3.  2 阶 + 1 阶
> ```

### 思路

* 思路1：递归的思路。减一调用自己和减二调用自己。太慢了！慢是因为有大量重复的计算。
* 思路2：排列组合的算法。阶乘数字太大了！而且估计也不快
* 迭代：从递归看出来是斐波那契数列。用循环来做，去掉了大量重复计算所以快了。
* 公式：略。

### 源码

* 递归：

  ```c++
  class Solution {
  public:
  	int climbStairs(int n) {
  		//太慢！不好！
  		if (n == 0)
  			return 0;
  		if (n == 1)
  			return 1;
  		if (n == 2)
  			return 2;
  		int n1 = climbStairs(n - 1);
  		int n2 = climbStairs(n - 2);
  		//cout << n1 << " " << n2;
  		return (n1 + n2);
  	}
  };
  ```

* 迭代：

  ```c++
  class Solution {
  public:
      int climbStairs(int n) {
          if (n == 1 || n == 0)
  			return n;
  		int last1 = 1;
  		int last2 = 2;
  		for (int i = 2; i < n; i++) {
  			int tmp = last2;
  			last2 = last1 + last2;
  			last1 = tmp;
  		}
  
  		return last2;
  	}
  };
  ```

### 体会

递归的缺点是，做了大量重复性的计算，因此改进的时候应当考虑如何把重复性的工作节约下来。