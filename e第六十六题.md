# 第六十六题-vector代表的数字加一

### 题目

> 给定一个由**整数**组成的**非空**数组所表示的非负整数，在该数的基础上加一。
>
> 最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
>
> 你可以假设除了整数 0 之外，这个整数不会以零开头。

### 举例

> ```
> 输入: [1,2,3]
> 输出: [1,2,4]
> 解释: 输入数组表示数字 123。
> 
> 输入: [4,3,2,1]
> 输出: [4,3,2,2]
> 解释: 输入数组表示数字 4321。
> ```

### 思路

* 基础思路：从最后一个往前循环，先检查是否=9，是的话就更新为0并继续循环，否则就结束循环。然后考虑加完后第一位是0的情况，因此引入一个flag来标记下一次是否组需要进位，如果检查=9就令flag为true，否则令flag为false。循环结束后检查flag若为true就给vector最前面加一位1。
* 进一步思路：看了一下solution更快的方法，好像是不需要考虑为负的情况（其实也有道理毕竟每一位只能存一个数字），因此改进前面的方法，不用flag，循环结束后直接检查第一位是不是0，如果是0就给前面加一位1（digits一开始为0的情况在循环里处理掉了）。

### 源码

* 基础思路：

  ```c++
  class Solution {
  public:
      vector<int> plusOne(vector<int>& digits) {
          int size = digits.size();
  		//用来标记是否下一次需要进位
  		bool flag = false;
  		for (int i = size-1; i >= 0; i--) {
  			if (digits[i] == 9) {
  				digits[i] = 0;
  				flag = true;
  			}
  			else {
  				digits[i] += 1;
  				flag = false;
  				break;
  			}
  		}
  		if (flag) {
  			digits.insert(digits.begin(), 1);
  		}
  		//for (int i = 0; i < digits.size(); i++) {
  		//	cout << digits[i] << endl;
  		//}
  		return digits;
      }
  };
  ```

* 进一步思路：

  ```c++
  class Solution {
  public:
      vector<int> plusOne(vector<int>& digits) {
          int size = digits.size();
  		for (int i = size-1; i >= 0; i--) {
  			if (digits[i] == 9) {
  				digits[i] = 0;
  			}
  			else {
  				digits[i] += 1;
  				break;
  			}
  		}
  		if (digits[0]==0) {
  			digits.insert(digits.begin(), 1);
  		}
  		return digits;
      }
  };
  ```



### 语法

iterator迭代器

本题用到vector的迭代器例如：

```
vector<int>& digits；

digits.begin()；
```

可以用digits.begin()+1的方式来使迭代器移位

迭代器的分类：输入迭代器，输出~，前向~，双向~，随机~。