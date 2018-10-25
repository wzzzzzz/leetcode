# 第八十八题-合并两个排序串

### 题目

> 给定两个有序整数数组 *nums1* 和 *nums2*，将 *nums2* 合并到 *nums1* 中*，*使得 *num1* 成为一个有序数组。
>
> **说明:**
>
> - 初始化 *nums1* 和 *nums2* 的元素数量分别为 *m* 和 *n*。
> - 你可以假设 *nums1* 有足够的空间（空间大小大于或等于 *m + n*）来保存 *nums2* 中的元素。

### 举例

> ```
> 输入:
> nums1 = [1,2,3,0,0,0], m = 3
> nums2 = [2,5,6],       n = 3
> 
> 输出: [1,2,2,3,5,6]
> ```

### 思路

* 基本思路：while循环。用两个指针，一个指向串1，一个指向串2，每次比较当前指针的值得大小，如果串1>串2就把串2的值插入串1当前位置的前面，并对串1的m++，每次循环都对串1的指针++。循环结束后检查串2还有没有剩余，如果有的话就把剩下的都复制到串1。最后把串1多余的0删掉。
* 思路2：先创建一个新串。while循环，两个指针，每次把较小值赋值给新串的当前位置，然后移动较小值的指针。循环结束后分别检查两个串还有没有剩余，有的话就把剩下的复制到新串中。最后把新串赋值给串1。

### 源码

* 基本思路：

  ```c++
  class Solution {
  public:
      void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
          int t = m + n;
  		int i,j;
  		for (i = 0, j = 0; i < m && j < n; i++) {
  			if (nums1[i] > nums2[j]) {
  				//插入
  				nums1.insert(nums1.begin() + i, nums2[j]);
  				j++;
  				m++;
  			}
  		}
  		if (i == m && j < n) {
  			for (j; j < n; i++,j++) {
  				nums1[i] = nums2[j];
  			}
  		}
  		while (t < nums1.size())
  		{
  			nums1.pop_back();
  		}
      }
  };
  ```

* 思路2：

  ```c++
  class Solution {
  public:
      void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  		vector<int> nums(nums1);
  		int i, j, k;
  		for (i = 0, j = 0, k = 0; i < m&&j < n;k++) {
  			if (nums1[i] > nums2[j]) {
  				nums[k] = nums2[j];
  				j++;
  			}
  			else {
  				nums[k] = nums1[i];
  				i++;
  			}
  		}
  		while (i < m) {
  			nums[k] = nums1[i];
  			k++;
  			i++;
  		}
  		while (j < n) {
  			nums[k] = nums2[j];
  			k++;
  			j++;
  		}
          nums1 = nums;
      }
  };
  ```


### 语法

vector初始化，可以初始化为几个X，可以用数组初始化，也可以用vector初始化。

vector有插入函数，也有删除函数