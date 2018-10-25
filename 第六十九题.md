# 第六十九题-求平方根

### 题目

> 实现 `int sqrt(int x)` 函数。
>
> 计算并返回 *x* 的平方根，其中 *x* 是非负整数。
>
> 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

### 举例

> ```
> 输入: 4
> 输出: 2
> 
> 输入: 8
> 输出: 2
> 说明: 8 的平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
> ```

### 思路

* 基本思路：res从0开始，一个while循环，条件是res平方小于等于x，循环内加加，结束后对res减一并返回。此方法很慢。
* 基本思路进一步：先检查0和1。res从1开始（因为是乘不是加），第一个while循环，条件是平方小于等于x并大于0，循环内对res乘2，结束后对res除2。这一步将res的范围缩小。第二个while循环，类似上面基本思路。此方法比上面快一些。
* solution二分法：二分法的思想。一个high一个low一个mid。一个while循环，条件是high大于等于low（注意这里的等于），循环内先计算mid，然后根据mid平方和x的比较来更新high或者low。更新high或者low时，如果更新是low=mid+1，前面循环条件就要有等于号，最后的结果取high，相对快一点；如果更新是low=mid，前面循环条件就不用等于号，最后的结果取low，但是比较慢。原因是如果+1就可能改变两端过于快，而题目要舍去小数，因此可能导致两个边界都大于理论结果，所以循环条件要有等于，使得最终再进行一次比较来解决这种错误，此时必然更新high，所以结果是high。如果不+1就不会出现上面的情况，因此正常做就行，但是更新没有上面的快。

### 源码

* 基本思路：略

* 基本思路进一步：

  ```c++
  class Solution {
  public:
      int mySqrt(int x) {
  		if (x == 0 || x == 1)
  			return x;
  		int res = 1;
  		unsigned int resres = 1;
  		while (resres <= x && resres >0) {
  			res*=2;
  			resres = res * res;
  			//cout << res << " " << res * res<<"   ";
  		}
  		res /= 2;
          resres = res * res;
  		while (resres <= x) {
  			res++;
  			resres = res * res;
  		}
  		//cout << res << " " << res * res;
  		return (res - 1);
      }
  };
  ```

* solution二分法：

  ```c++
  class Solution {
  public:
      int mySqrt(int x) {
  		if (x == 0 || x == 1)
  			return x;
  		int high = min(x, 65536);
  		int low = 1;
  		int mid = 1;
  		unsigned int midmid = 1;
  		while (high >= low) {
  			mid = (high + low) / 2;
  			midmid = mid * mid;
  			//cout << mid << " " << midmid << "  ";
  			if (midmid < x) {
  				low = mid+1;
  			}
  			else if (midmid > x) {
  				high = mid-1;
  			}
  			else return mid;
  		}
  		//cout << low<<" "<<mid<<" "<<high;
  		return high;
      }
  };
  ```


### 语法

注意int的范围和unsigned int范围不同。