# 第五十八题-最后一个单词的长度

### 题目

> 给定一个仅包含大小写字母和空格 `' '` 的字符串，返回其最后一个单词的长度。
>
> 如果不存在最后一个单词，请返回 0 。
>
> **说明：**一个单词是指由字母组成，但不包含任何空格的字符串。

### 举例

> ```
> 输入: "Hello World"
> 输出: 5
> ```

### 思路

* 基础思路：用string.find查找最后一个空格，然后s的长度减去空格的位置就是结果。要考虑的是，如果最后一个是空格， 那么最后一个单词应该是空格之前的单词，如果最后几个都是空格，那最后一个单词应该是几个空格之前的单词。于是用while循环检查s的最后一位是不是空格，如果是就把s的最后一位删掉并更新长度和最后一个空格的位置。但这种办法可能带来空字符串的无限循环，所以while循环之前和里面里还要加上判断s是否为空。
* 进一步思路：用string.find查找最后一个不是空格的字符的位置。然后把s截取到最后一个不是空格的地方。然后再找最后一个空格。把两个位置相减就是最后一个单词的长度。
* solution：不用find，用一个循环。遇到空格就continue并将长度置位0，否则就长度++。这种方法的关键在于，如果最后是空格，不能让0覆盖掉最后一个长度。因此加一个flag来标记上一个是否为空格：遇到空格时将flag置为true，不是空格时检查flag如果为true则将长度置位0并将flag置位false。并在循环最后对长度++。

### 源码

* 基础思路：

  ```c++
  class Solution {
  public:
  	int lengthOfLastWord(string s) {
  		int last = s.find_last_of(" ");
  		int len = s.length();
  		int res = 0;
  		if (s == "")
  			return 0;
  		while (last == (len-1)) {
  			//cout << s.length() << " " << last << " " << res << endl;
  			s = s.substr(0, len - 1);
  			if (s == "")
  				return 0;
  			len = s.length();
  			last = s.find_last_of(" ");
  		}
  		res = s.length() - last - 1;
  
  		//cout << s.length()<<" "<<last << " " << res;
  		return res;
  	}
  };
  ```

* 进一步思路：

  ```c++
  class Solution {
  public:
      int lengthOfLastWord(string s) {
          int last = s.find_last_not_of(" ");
  		int len = s.length();
  		int res = 0;
  		s = s.substr(0, last+1);
  		last = s.find_last_of(" ");
  		res = s.length() - last - 1;
  		//cout << s.length() << " " << last << " " << res;
          return res;
      }
  };
  ```

* solution：

  ```c++
  class Solution {
  public:
      int lengthOfLastWord(string s) {
  		int res = 0;
  		bool flag = false;
  		for (int i = 0; i < s.size(); i++) {
  			if (s[i] == ' ') {
  				flag = true;
  				continue;
  			}
  			if (flag==true) {
  				res = 0;
  				flag = false;
  			}
  			res++;
  		}
          return res;
      }
  };
  ```


### 语法

if (s[i] == ' ')//ok

if (s[i] == " ")//不可以