#include <iostream>;
using namespace std;


/****************************************第一百题*********************************************/
////Definition for a binary tree node.
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//	
//};
//
//class Solution {
//public:
//	bool isSameTree(TreeNode* p, TreeNode* q) {
//		if (p == NULL && q == NULL)
//			return true;
//		else if (p == NULL || q == NULL)
//			return false;
//		
//		if (p->val != q->val)
//			return false;
//		if (!isSameTree(p->left, q->left))
//			return false;
//		if (!isSameTree(p->right, q->right))
//			return false;
//
//		return true;
//	}
//};
//
//int main() {
//
//}



/****************************************第八十八题*********************************************/
//#include <vector>
//class Solution {
//public:
//	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//		//进一步思路
//		vector<int> nums(nums1);
//		int i, j, k;
//		for (i = 0, j = 0, k = 0; i < m&&j < n;k++) {
//			if (nums1[i] > nums2[j]) {
//				nums[k] = nums2[j];
//				j++;
//			}
//			else {
//				nums[k] = nums1[i];
//				i++;
//			}
//		}
//		while (i < m) {
//			nums[k] = nums1[i];
//			k++;
//			i++;
//		}
//		while (j < m) {
//			nums[k] = nums2[j];
//			k++;
//			j++;
//		}
//		nums1 = nums;
//
//		//基本思路
//		//int t = m + n;
//		//int i,j;
//		//for (i = 0, j = 0; i < m && j < n; i++) {
//		//	if (nums1[i] > nums2[j]) {
//		//		//插入
//		//		nums1.insert(nums1.begin() + i, nums2[j]);
//		//		j++;
//		//		m++;
//		//	}
//		//}
//		//if (i == m && j < n) {
//		//	for (j; j < n; i++,j++) {
//		//		nums1[i] = nums2[j];
//		//	}
//		//}
//		//while (t < nums1.size())
//		//{
//		//	nums1.pop_back();
//		//}
//	}
//};
//
//int main() {
//	int d[] = { 1,2,3,0,0,0 };
//	vector<int> nums1(d, d + 6);
//	int t[] = { 2,5,6,0,0 };
//	vector<int> nums2(t, t + 3);
//	Solution s;
//	s.merge(nums1, 3, nums2, 3);
//	system("pause");
//	return 0;
//}



/****************************************第八十三题*********************************************/
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//	ListNode * deleteDuplicates(ListNode* head) {
//		//solution
//		if (!head || !head->next) {
//			return head;
//		}
//		ListNode *t = head;
//		while (head && head->next) {
//			if (head->val == head->next->val) {
//				head->next = head->next->next;
//			}
//			else head = head->next;
//		}
//		
//		//基本思路
//		//if (!head || !head->next) {
//		//	return head;
//		//}
//		//ListNode *tmp = head;
//		//ListNode *t = head;
//		//while (tmp->next) {
//		//	tmp = tmp->next;
//		//	if (tmp->val == head->val) {
//		//		head->next = tmp;
//		//		head = head->next;
//		//	}
//		//}
//		//if (tmp->val == head->val) {
//		//	head->next = tmp->next;
//		//}
//		while (t) {
//			cout << t->val << endl;
//			t = t->next;
//		}
//		return t;
//	}
//};
//
//int main() {
//	ListNode t1(1);
//	ListNode t2(1);
//	ListNode t3(1);
//	//ListNode t4(3);
//	//ListNode t5(3);
//	//t4.next = &t5;
//	//t3.next = &t4;
//	t2.next = &t3;
//	t1.next = &t2;
//	
//	Solution s;
//	s.deleteDuplicates(&t1);
//	system("pause");
//	return 0;
//}



/****************************************第七十题？？？？？？？？？？？？？？？？？？？？？？？？？****/
//class Solution {
//public:
//	int climbStairs(int n) {
//		//迭代方法
//		if (n == 1 || n == 0)
//			return n;
//		int last1 = 1;
//		int last2 = 2;
//		for (int i = 2; i < n; i++) {
//			int tmp = last2;
//			last2 = last1 + last2;
//			last1 = tmp;
//		}
//		cout << last2;
//		return last2;
//
//		//不好！阶乘数字太大了！而且估计也不快！
//		//if (n == 0)
//		//	return 0;
//		//int res = 1;
//		//int i = 1;
//		//int j = 0;
//		////i是2的个数
//		//for (i = 1; n >= (i * 2); i++) {
//		//	j = n - (i * 2);
//		//	int tmp = 1;
//		//	//计算i和j的排列组合
//		//	if (j != 0) {
//		//		tmp = qiujiecheng(i + j);
//		//		cout <<i+j<<" "<< tmp << "   ";
//		//		tmp /= qiujiecheng(i);
//		//		cout << i<<" "<<tmp << "   ";
//		//		tmp /= qiujiecheng(j);
//		//		cout <<j<<" "<< tmp << "   ";
//		//	}
//		//	res += tmp;
//		//	//cout << res;
//		//}
//		//cout << res;
//
//
//		//太慢！不好！
//		//if (n == 0)
//		//	return 0;
//		//if (n == 1)
//		//	return 1;
//		//if (n == 2)
//		//	return 2;
//		//int n1 = climbStairs(n - 1);
//		//int n2 = climbStairs(n - 2);
//		////cout << n1 << " " << n2;
//		//return (n1 + n2);
//	}
//
//
//	//int qiujiecheng(int x) {
//	//	int res = 1;
//	//	for (int i = 0; i < x; i++) {
//	//		res *= x;
//	//	}
//	//	return res;
//	//}
//};
//
//int main() {
//	int n = 4;
//	Solution s;
//	s.climbStairs(n);
//	system("pause");
//	return 0;
//}



/****************************************第六十九题*********************************************/
//#include<algorithm>;
//class Solution {
//public:
//	int mySqrt(int x) {
//		////二分法进一步		
//		if (x > 100) {
//			int high = min(x/2, 65536);
//			int low = 1;
//			int mid = 1;
//			unsigned int midmid = 1;
//			//这里要有等于，为了最后多检查一遍
//			while (high >= low) {
//				mid = (high + low) / 2;
//				midmid = mid * mid;
//				cout << mid << " " << midmid << "  ";
//				if (midmid < x) {
//					low = mid + 1;
//				}
//				else if (midmid > x) {
//					high = mid - 1;
//				}
//				else return mid;
//			}
//			//cout << low<<" "<<mid<<" "<<high;
//			return high;
//		}
//		else {
//			int res = 0;
//			unsigned int resres = 0;
//			while (resres <= x) {
//				res++;
//				resres = res * res;
//			}
//			//cout << res << " " << res * res;
//			return (res - 1);
//		}
//		
//		//二分法
//		//if (x == 0 || x == 1)
//		//	return x;
//		//int high = min(x, 65536);
//		//int low = 1;
//		//int mid = 1;
//		//unsigned int midmid = 1;
//		////这里要有等于，为了最后多检查一遍
//		//while (high >= low) {
//		//	mid = (high + low) / 2;
//		//	midmid = mid * mid;
//		//	cout << mid << " " << midmid << "  ";
//		//	if (midmid < x) {
//		//		low = mid+1;
//		//	}
//		//	else if (midmid > x) {
//		//		high = mid-1;
//		//	}
//		//	else return mid;
//		//}
//		////cout << low<<" "<<mid<<" "<<high;
//		//return high;
//
//		//进一步
//		//if (x == 0 || x == 1)
//		//	return x;
//		//int res = 1;
//		//unsigned int resres = 1;
//		//while (resres <= x && resres >0) {
//		//	res*=2;
//		//	resres = res * res;
//		//	//cout << res << " " << res * res<<"   ";
//		//}
//		//res /= 2;
//		//resres = res * res;
//		//while (resres <= x) {
//		//	res++;
//		//	resres = res * res;
//		//	//cout << res << " " << res * res;
//		//}
//		////cout << res << " " << res * res;
//		//return (res-1);
//		
//		//基础思路
//		//int res = 0;
//		//unsigned int resres = 0;
//		//while (resres <= x) {
//		//	res++;
//		//	resres = res * res;
//		//}
//		////cout << res << " " << res * res;
//		//return (res - 1);
//	}
//};
//
//int main() {
//	int x = 5;
//	Solution s;
//	s.mySqrt(x);
//	system("pause");
//	return 0;
//}



/****************************************第六十八题*********************************************/
//#include<algorithm>;
//class Solution {
//public:
//	string addBinary(string a, string b) {
//		string res = "";
//		int la = a.length();
//		int lb = b.length();
//		int l;
//		//初始化l和res
//		if (la < lb) {
//			res = b;
//			l = la;
//		}
//		else {
//			res = a;
//			l = lb;
//		}
//		int lr = res.length();
//		//计算res，每一位是a和b的直接相加
//		for (int i = 1; i < l+1; i++) {
//			res[lr - i] = a[la - i] - '0' + b[lb - i];
//			//cout << " " << res.c_str();
//		}
//		//对res从右往左依次进位，flag来标记本次是否进位，也就是下一次是否加一
//		bool flag = false;
//		for (int i = lr - 1; i >= 0; i--) {
//			if (flag) {
//				res[i] = res[i] + '1' - '0';
//				//cout << " " << res[i];
//			}
//			if (res[i] >='2') {
//				flag = true;
//				res[i] = res[i] - '2' + '0';
//				cout << " " << res[i];
//			}
//			else flag = false;
//			//cout << " " << res.c_str();
//		}
//		//结束后检查首位是否需要加一位
//		if (flag)
//			res = "1" + res;
//		//cout << " " << res.c_str();
//		return res;
//	}
//};
//
//int main() {
//	string a = "1";
//	string b = "0";
//	Solution s;
//	s.addBinary(a, b);
//	system("pause");
//	return 0;
//}



/****************************************第六十六题*********************************************/
//#include <vector>;
//class Solution {
//public:
//	vector<int> plusOne(vector<int>& digits) {
//		//进一步
//		int size = digits.size();
//		for (int i = size - 1; i >= 0; i--) {
//			if (digits[i] == 9) {
//				digits[i] = 0;
//			}
//			else {
//				digits[i] += 1;
//				break;
//			}
//		}
//		if (digits[0] == 0) {
//			digits.insert(digits.begin(), 1);
//		}
//
//      //基础思路
//		//int size = digits.size();
//		////用来标记是否下一次需要进位
//		//bool flag = false;
//		//for (int i = size-1; i >= 0; i--) {
//		//	if (digits[i] == 9) {
//		//		digits[i] = 0;
//		//		flag = true;
//		//	}
//		//	else {
//		//		digits[i] += 1;
//		//		flag = false;
//		//		break;
//		//	}
//		//}
//		//if (flag) {
//		//	digits.insert(digits.begin(), 1);
//		//}
//		//for (int i = 0; i < digits.size(); i++) {
//		//	cout << digits[i] << endl;
//		//}
//		return digits;
//	}
//};
//
//int main() {
//	int d[] = { 9,9,9,9 };
//	vector<int> digit(d, d + 4);
//	Solution s;
//	s.plusOne(digit);
//	system("pause");
//	return 0;
//}



/****************************************第五十八题*********************************************/
//class Solution {
//public:
//	int lengthOfLastWord(string s) {
		//solution
		//int res = 0;
		//bool flag = false;
		//for (int i = 0; i < s.size(); i++) {
		//	if (s[i] == ' ') {
		//		flag = true;
		//		continue;
		//	}
		//	if (flag==true) {
		//		res = 0;
		//		flag = false;
		//	}
		//	res++;
		//}
		//cout << res;
		
		////思路2
		////int last = s.find_last_not_of(" ");
		////int len = s.length();
		////int res = 0;
		////if (last == -1) {
		////	return 0;
		////}
		////else s = s.substr(0, last+1);
		////last = s.find_last_of(" ");
		////res = s.length() - last - 1;
		////cout << s.length() << " " << last << " " << res;

		////思路1
		////int last = s.find_last_of(" ");
		////int len = s.length();
		////int res = 0;
		////if (s == "")
		////	return 0;
		////while (last == (len-1)) {
		////	//cout << s.length() << " " << last << " " << res << endl;
		////	s = s.substr(0, len - 1);
		////	if (s == "")
		////		return 0;
		////	len = s.length();
		////	last = s.find_last_of(" ");
		////}
		////res = s.length() - last - 1;

		//cout << s.length()<<" "<<last << " " << res;
//		return res;
//	}
//};
//
//int main() {
//	string ss = "a  bbb";
//	Solution s;
//	s.lengthOfLastWord(ss);
//	system("pause");
//	return 0;
//}



/****************************************第五十三题*********************************************/
//#include <algorithm>;
//#include <vector>;
//class Solution {
//public:
//	int maxSubArray(vector<int>& nums) {
//		//divide and conquer 
//		int res = 0;
//
//		//看了答案的2
//		//int res = nums[0];
//		//int tmp = nums[0];
//		//int len = nums.size();
//		//for (int i = 1; i < len; i++) {
//		//	tmp = max(nums[i], nums[i] + tmp);
//		//	res = max(tmp, res);
//		//}
//		
//		//看了答案的1
//		//int res = nums[0];
//		//int len = nums.size();
//		//int tmp = 0;
//		//for (int i = 0; i < len; i++) {
//		//	tmp += nums[i];
//		//	res = max(res, tmp);
//		//	tmp = max(0, tmp);			
//		//	//cout << res << tmp << endl;
//		//}
//
//		//基础思路
//		//int res = nums[0];
//		//int len = nums.size();
//		//int tmp = 0;
//		//for (int i = 0; i < len; i++) {
//		//	tmp = nums[i];
//		//	res = max(res, tmp);
//		//	if (tmp < 0) {
//		//		continue;
//		//	}
//		//	for (int j = i + 1; j < len; j++) {
//		//		tmp += nums[j];
//		//		res = max(res, tmp);
//		//	}
//		//	//cout << res << tmp << endl;
//		//}
//		cout << res;
//		return res;
//	}
//};
//
//int main() {
//	int n[] = { -1, -2, -1, -1, 5, 2, 1, -5, 4 };
//	vector<int> nums(n, n + 2);
//	Solution s;
//	s.maxSubArray(nums);
//	system("pause");
//	return 0;
//}



/****************************************第三十八题*********************************************/
//#include <sstream> ;
//#include <string.h>;
//class Solution {
//public:
//	string countAndSay(int n) {
//		string res;
//		if (n == 1)
//			res = "1";
//		else {
//			int l = n - 1;
//			string last = countAndSay(l);
//			int length = 1;
//			for (int i = 0; i < last.length(); i++) {
//				////int length = 1;
//				////for (int j = i + 1; j < last.length(); j++) {
//				////	if (last[i] == last[j]) {
//				////		length++;
//				////	}
//				////	else {
//				////		break;
//				////	}
//				////}
//				////ostringstream os;
//				////os << length;
//				////res += os.str();
//				////res += last[i];
//				////i = i + length - 1;
//				////cout << length << "   " << last[i] << "   " << res.c_str() << endl;
//
//				if (last[i] == last[i + 1]) {
//					length++;
//				}
//				else {
//					//ostringstream os;
//					//os << length;
//					res += std::to_string(length);
//					//res += os.str();
//					res += last[i];
//					length = 1;
//				}
//			}
//		}
//		cout << res.c_str() << endl;
//		return res;
//	}
//};
//
//int main() {
//	int n = 5;
//	Solution s;
//	s.countAndSay(n);
//	system("pause");
//	return 0;
//}



/****************************************第三十五题*********************************************/
//class Solution {
//public:
//	int searchInsert(vector<int>& nums, int target) {
//		int res = 0;
//		for (int i = 0; i < nums.size(); i++) {
//			if (nums[i] < target) {
//				res++;
//			}
//			else break;
//		}
//		//cout << res << endl;
//		return res;
//	}
//};
//
//int main() {
//	Solution s;
//	int tmp[] = {1,3,5,6,7};
//	vector<int> nums(tmp, tmp + 5);
//	int target = 0;
//	s.searchInsert(nums, target);
//
//	system("pause");
//	return 0;
//}



/****************************************第二十八题*********************************************/
//class Solution {
//public:
//	int strStr(string haystack, string needle) {
//		int length = haystack.size();
//		int len = needle.size();
//		if (len == 0) {
//			return 0;
//		}
//		if (length < len)
//			return -1;
//		int i;
//		for (i = 0; i < length-len+1; i++) {
//			if (haystack[i] == needle[0]) {
//				int j;
//				for (j = 1; j < len; j++) {
//					if (haystack[i + j] != needle[j])
//						break;
//				}
//				if (j == len){
//					return i;
//				}
//			}
//		}
//		return -1;
//	}
//};
//
//int main() {
//	string haystack = "abb";
//	string needle = "abaaa";
//	Solution s;
//	s.strStr(haystack, needle);
//
//	system("pause");
//	return 0;
//}



/****************************************第二十七题*********************************************/
//class Solution {
//public:
//	int removeElement(vector<int>& nums, int val) {
//		int length = nums.size();
//		for (int i = 0; i < length; i++) {
//			if (nums[i] == val) {
//				if (nums[length - 1] == val) {
//					i--;
//				}
//				else {
//					nums[i] = nums[length - 1];
//				}
//				length--;
//			}
//		}
//		//for (int i = 0; i < nums.size(); i++) {
//		//	cout << nums[i] << endl;
//		//}
//		//cout << length;
//		return length;
//	}
//};
//
//int main() {
//	Solution s;
//	int tmp[] = {2,2,2,1,2,2,2,2};
//	vector<int> n(tmp, tmp + 8);
//	s.removeElement(n, 2);
//
//	system("pause");
//	return 0;
//}



/****************************************第二十六题*********************************************/
//#include<vector>;
//#include<algorithm>;
//class Solution {
//public:
//	int removeDuplicates(vector<int>& nums) {
//		int length = nums.size();
//		if (length == 0 || length == 1)
//			return length;
//		int tmp = nums[length - 1];
//		int same = 0;
//		int last = nums[0];
//		int i;
//		for (i = 1; i < length;) {
//			//for (int j = 0; j < length; j++) {
//			//	cout << nums[j] <<" ";
//			//}
//			//cout << endl;
//			//算出有几个和num[i]相等的
//			if (nums[i] == last) {
//				int j = i;
//				while (j < length && nums[j] == last) {
//					nums[j] = tmp;
//					same++;
//					j++;
//				}
//				i = j;
//			}
//			else {
//				last = nums[i];
//				i++;
//			}
//		}
//
//		sort(nums.begin(), nums.end());
//		for (i = 0; i < length; i++) {
//			cout << nums[i] << endl;
//		}
//		cout << " "<<same<<" "<<length-same;
//		return length - same;
//	}
//};
//
//int main() {
//	Solution s;
//	int tmp[] = {-1,0,0,1,1,2,2,3,3,4};
//	vector<int> n(tmp, tmp + 3);
//	s.removeDuplicates(n);
//
//	system("pause");
//	return 0;
//}



/****************************************第二十一题*********************************************/
////Definition for singly-linked list.
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {
//		ListNode t1 = *l1;
//		ListNode t2 = *l2;
//		ListNode res(-1);
//		ListNode tmp(-1);
//		while (t1.val != NULL && t2.val != NULL) {
//			ListNode t(-1);
//			if (t1.val <= t2.val) {
//				t = t1;
//				if (t1.next != NULL)
//				{
//					//cout << t1.val << endl;
//					t1 = *t1.next;
//				}
//				//else {
//					
//					//break;
//				//}
//			}
//			else{
//				t = t2;
//				if (t2.next != NULL)
//					t2 = *t2.next;
//				else break;
//			}
//			
//			if (res.val != -1) {				
//				tmp.next = &t;
//				tmp = *tmp.next;
//				//cout << tmp.val << endl;
//			}
//			else {
//				res = t;
//				tmp = res;
//			}
//			//if (t1.next == NULL || t2.next == NULL)
//			//	break;
//			//else {
//			//	t1 = *t1.next;
//			//	t2 = *t2.next;
//			//}
//		}
//
//		if (t1.val != NULL) {
//			res.next = &t1;
//			//cout << t1.val << endl;
//		}
//		if (t2.val != NULL) {
//			res.next = &t2;
//			//cout << t2.val << endl;
//		}
//
//		//while (res.next != NULL) {
//			//cout << res.val << endl;
//			//res = *res.next;
//		//}
//		return res.next;
//	}
//};
//int main() {
//	ListNode l1(1);
//	ListNode t1(2);
//	ListNode t2(4);
//	t1.next = &t2;
//	l1.next = &t1;
//	while (l1.next != NULL) {
//		cout << l1.val << endl;
//		l1=*l1.next;
//	}
//
//	ListNode l2(1);
//	ListNode t3(3);
//	ListNode t4(4);
//	t4.next = &t3;
//	l2.next = &t4;
//
//	Solution s;
//	s.mergeTwoLists(&l1, &l2);
//
//	system("pause");
//	return 0;
//}



/****************************************第二十题*********************************************/
//#include <string>;
//#include <string.h>;
//#include <stack>;
//using namespace std;
//
//class Solution {
//public:
//	bool isValid(string s) {
//		stack<char> stk;
//	    for(int i=0;i<s.size();i++) {
//			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
//				stk.push(s[i]);
//				//cout << s[i] << endl;
//			}
//			else {
//				if (stk.empty()) {
//					//cout << "empty" << endl;
//					//cout << "0" << endl;
//					return false;
//				}
//				else {
//					char tmp = stk.top();
//					//cout << tmp << endl;
//					stk.pop();
//					if (s[i]==')'&&tmp!='('|| s[i] == ']'&&tmp != '[' || s[i] == '}'&&tmp != '{') {
//						//cout << "0" << endl;
//						return false;
//					}
//				}
//
//			}
//		}
//		//cout << "1" << endl;
//		if (!stk.empty()) {
//			//cout << "0" << endl;
//			return false;
//		}
//		return true;
//	}
//};
//
//int main() {
//	Solution s;
//	string t = "(";
//	s.isValid(t);
//
//	system("pause");
//	return 0;
//}



/****************************************第十四题*********************************************/
//#include <string>;
//#include <string.h>;
//using namespace std;
//
//class Solution {
//public:
//	string longestCommonPrefix(vector<string>& strs) {
//		if (strs.empty() == true)
//			return "";
//		if (strs.size() == 1)
//			return strs[0];
//
//		string shortest=strs[0];
//		vector<string> comp;
//		string longest = "";
//		//找出最短的字符串
//		for (int i = 0; i < strs.size(); i++) {
//			if (strs[i].length() < shortest.length()) {
//				shortest = strs[i];
//			}
//		}
//		//cout << shortest << endl;
//		//以最短的字符串进行比较
//			for (int j = 1; j < shortest.length() +1; j++) {				
//				int k;
//				for (k = 0; k < strs.size(); k++) {
//					if (strs[k].find(shortest.substr(0, j)) >0) {
//						break;
//					}
//				}
//				if (k == strs.size()) {
//					comp.push_back(shortest.substr(0, j));
//					//cout << shortest.substr(i, j) << endl;
//					if (shortest.substr(0, j).length() > longest.length()) {
//						longest = shortest.substr(0, j);
//					}
//					cout << longest << endl;
//				}
//			}
//		return longest;
//	}
//};
//
//int main() {
//	vector<string> strs(1);
//	strs[0] = "dog";
//
//
//	Solution s;
//	s.longestCommonPrefix(strs);
//
//	system("pause");
//	return 0;
//}



/****************************************第十三题*********************************************/
//class Solution {
//public:
//	int romanToInt(string s) {
//		int res = 0;
//			
//		int now = 0;
//		int last = 0;;
//		for (int i = 0; i < s.length(); i++) {
//			switch (s[i])
//			{
//			case 'I': {res += 1; now = 1; break; }
//			case 'V': {res += 5; now = 5; break; }
//			case 'X': {res += 10; now = 10; break; }
//			case 'L': {res += 50; now = 50; break; }
//			case 'C': {res += 100; now = 100; break; }
//			case 'D': {res += 500; now = 500; break; }
//			case 'M': {res += 1000; now = 1000; break; }
//			};
//			//printf("%d %c\n", res, s[i]);
//
//			if (now>last) {
//				res = res - 2 * last;
//			}
//			//printf("%d\n", res);
//			last = now;
//		}
//		//printf("%d\n", res);
//		return res;
//	}
//};
//
//int main() {
//	Solution s;
//	string str = "LVIII";
//	s.romanToInt(str);
//
//	system("pause");
//	return 0;
//}



/****************************************第九题*********************************************/
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//bool isPalindrome(int x) {
//	if (x < 0) {
//		//printf("0");
//		return false;
//	}
//
//	char a[20] = { 0, };
//	int length = 0;
//	while (x >= 1) {
//		int tmp = x % 10;
//		x /= 10;
//		a[length] = tmp;
//		length++;
//		//printf("%d,%d\n", a[length-1], length);
//	}
//	for (int i = 0; i < length / 2; i++) {
//		//printf("%d,%d\n", a[i], a[length - i - 1]);
//		if (a[i] != a[length - i - 1]) {
//			//printf("0");
//			return false;
//		}
//	}
//
//	//printf("1");
//	return true;
//}
//
//bool isPalindrome(int x) {
//	if (x < 0)
//		return false;
//
//	int length = 0;
//	while (x >= pow(10, length)) {
//		length++;
//	}
//
//	while (x >= 1) {
//		printf("%d\n", length);
//		int left = x / (pow(10, length-1));
//		int right = x % 10;
//		printf("%d.%d\n", left, right);
//
//		if (left != right) {
//			return false;
//		}
//		else {
//			x = x % (int)pow(10, length-1);
//			x = x / 10;
//			length -= 2;
//			printf("%d\n", x);
//		}
//	}
//	printf("1");
//	return true;
//}
//
//bool isPalindrome(int x) {
//		if (x < 0)
//			return false;
//		if (x < 10)
//			return true;
//
//		int tmp = x;
//		int right = x % 10;
//		int reverse = 0;
//		int length = 0;
//
//		while (tmp >= 10) {
//			reverse *= 10;
//			reverse += tmp % 10;//如果tmp % 10==0不影响，因为最后一个和第一个必定不等
//			tmp = tmp / 10;
//			//printf("%d,%d\n", reverse, tmp);
//			length++;
//		}
//		//printf("%d\n", length);
//
//		x = x / 10;
//		x = x % (int)pow(10, length);
//
//		if(tmp !=right){
//			//printf("1");
//			return false;
//		}
//		else if(reverse!=x)
//		{
//			//printf("2");
//			return false;
//		}
//		else {
//			//printf("3");
//			return true;
//		}
//}
//
//int main() {
//	int x = 10200;
//	isPalindrome(x);
//	system("pause");
//	return 0;
//}



/****************************************第七题*********************************************/
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//int reverse(int x) {
//	int res = 0;
//	int flag = 0;
//	if (x < 0) {
//		flag = 1;
//		x = 0 - x;
//	}
//	while (x >= 1) {
//		int tmp = x % 10;
//		x = x/10;
//		if (res > 214748364) {
//			res = 0;
//			return res;
//		}
//		res *= 10;
//		res += tmp;
//	}
//	if (flag == 1)
//		res = 0 - res;
//	return res;
//}
//
//int main() {
//	int x = 1534236469;
//	reverse(x);
//
//	system("pause");
//	return 0;
//}



/*******************************************第一题********************************************/
//#include <stdio.h>
//#include <stdlib.h>
//
//int* twoSum(int* nums, int numsSize, int target) {
//	static int res[2] = { 0,0 };
//	for (int i = 0; i<numsSize; i++) {
//		for (int j = i + 1; j<numsSize; j++) {
//			if ((nums[i] + nums[j]) == target) {
//				res[0] = i;
//				res[1] = j;
//				//printf("%d", i, j);
//				printf("[%d,%d]\n", i, j);
//				return res;
//			}
//		}
//	}
//	return res;
//}
//
//int main() {
//	int nums[7] = { 2,7,11,15,8,2,1 };
//	twoSum(nums, 7, 9);	
//	system("pause");
//	return 0;
//}