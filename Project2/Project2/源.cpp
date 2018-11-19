#include <iostream>;
using namespace std;

#include<vector>;
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<int> tmp = nums;
		vector<vector<int>> res;
		int len = nums.size();
		getpermute( 0, len, tmp, res);

		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++) {
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
		return res;
	}

	void getpermute(int ind, int len, vector<int>& tmp, vector<vector<int>>& res) {
		if (ind == 0) {
			getpermute(ind + 1, len, tmp, res);
		}
		else if (ind < len)
			res.push_back(tmp);
		vector<int> thistmp = tmp;
		for (int i = ind+1; i < len; i++) {
			vector<int> now = thistmp;
			int t = now[ind];
			now[ind] = now[i];
			now[i] = t;
			getpermute(ind + 1, len, now, res);
		}
	}
};

int main() {
	Solution s;
	int n[7] = { 1,2,3,4,2,1,5 };
	vector<int> nums(n, n + 4);
	s.permute(nums);
	system("pause");
	return 0;
}



/****************************************第四十三题*********************************************/
//#include<string>;
//#include<vector>;
//class Solution {
//public:
//	string multiply(string num1, string num2) {
//		if (num1 == "0" || num2 == "0")
//			return "0";
//		int len1 = num1.length();
//		int len2 = num2.length();
//
//		vector<string> tmp;
//		for (int i = len1-1; i >= 0 ; i--) {
//			int ind = len1 - i - 1;
//			tmp.push_back("");
//			int n1 = num1[i] - '0';
//			int t = 0;
//			for (int j = len2 -1; j >= 0 ; j--) {
//				int n2 = num2[j] - '0';
//				int thisn = n1 * n2 + t;
//				t = thisn / 10;
//				thisn %= 10;
//				tmp[ind] = to_string(thisn) + tmp[ind];
//			}
//			if (t > 0) {
//				tmp[ind] = to_string(t) + tmp[ind];
//			}
//			for (int j = 0; j < ind; j++) {
//				tmp[ind] += "0";
//			}
//			//cout << tmp[ind] << endl;
//		}
//
//		int len = tmp.size();
//		vector<int> lens;
//		for (int i = 0; i < len; i++) {
//			lens.push_back(tmp[i].size());
//		}
//		int next = 0;
//		string res;
//		for (int i = lens[len-1] - 1; i >= 0; i--) {
//			int thissum = 0;
//			for (int j = 0; j < len; j++) {
//				int ind = lens[j] - (lens[len - 1] - i - 1)-1;
//				if (ind>=0) {
//					thissum += tmp[j][ind]-'0';
//				}
//			}
//			thissum += next;
//			//cout << thissum<<" "<<next<<"   ";
//			next = thissum / 10;
//			res = to_string(thissum % 10) + res;
//		}
//		if (next != 0) {
//			res = to_string(next) + res;
//		}
//
//		//cout << res;
//		return res;
//	}
//};
//
//int main() {
//	string a = "123456789", b = "987654321";
//	Solution s;
//	s.multiply(a, b);
//	system("pause");
//	return 0;
//}



/****************************************第四十题*********************************************/
//#include<vector>;
//#include<algorithm>;
//class Solution {
//public:
//	vector<vector<int>> res;
//	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//		vector<int> tmp;
//		int len = candidates.size();
//		sort(candidates.begin(), candidates.end());
//		cout << candidates.size()<<" ";
//		getsum(0, tmp, candidates, target);
//		cout << res.size()<<endl;
//		for (int i = 0; i < res.size(); i++) {
//			for (int j = 0; j < res[i].size(); j++) {
//				cout << res[i][j] << " ";
//			}
//			cout << endl;
//		}
//		return res;
//	}
//	void getsum(int index, vector<int> tmp, vector<int>& candidates, int target) {
//		int len = candidates.size();
//		if (target == 0) {
//			res.push_back(tmp);
//			return;
//		}
//		for (int i = index; i < len; i++) {
//			if (candidates[i] > target) {
//				return;
//			}
//			tmp.push_back(candidates[i]);
//			getsum(i + 1, tmp, candidates, target - candidates[i]);
//			tmp.pop_back();
//			while (i < len - 1 && candidates[i] == candidates[i + 1]) {
//				i++;
//			}
//		}
//	}
//};
//
//int main() {
//	Solution s;
//	int n[7] = { 2,5,2,1,2,1,5 };
//	vector<int> nums(n, n + 5);
//	s.combinationSum2(nums, 5);
//	system("pause");
//	return 0;
//}



/****************************************第三十九题*********************************************/
//#include<vector>;
//#include<algorithm>;
//class Solution {
//public:
//	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//		vector<vector<int>> res;
//		int len = candidates.size();
//		sort(candidates.begin(), candidates.end());
//		cout << candidates.size();
//		res = getsum(candidates, target);
//		cout << endl;
//		for (int i = 0; i < res.size(); i++) {
//			for (int j = 0; j < res[i].size(); j++) {
//				cout << res[i][j] << " ";
//			}
//			cout << endl;
//		}
//		return res;
//	}
//	vector<vector<int>> getsum(vector<int>& candidates, int target) {
//		vector<vector<int>> res;
//		int len = candidates.size();
//
//		for (int i = 0; i < len&&candidates[i] <= target; i++) {
//			int count = target / candidates[i];		
//			int thisnum = candidates[i];
//
//			if (target%candidates[i] == 0) {
//				vector<int> tmp( count, candidates[i] );
//				res.push_back(tmp);
//				count--;
//			}
//			vector<int> next(candidates.begin() + i + 1 , candidates.end());
//			cout << next.size();
//			for (count; count > 0; count--) {
//				vector<vector<int>> tmp;
//				int sum = count * thisnum;
//				tmp = getsum(next, target - sum);
//				//给tmp的每个数组前面加上对应的count个thisnum,然后加给res
//				for (int j = 0; j < tmp.size(); j++) {
//					for (int k = 0; k < count; k++) {
//						tmp[j].insert(tmp[j].begin(), thisnum);
//					}
//					res.push_back(tmp[j]);
//				}
//			}
//		}
//
//		return res;
//	}
//};
//
//int main() {
//	Solution s;
//	int n[7] = { 2,3,6,7,10,11,0 };
//	vector<int> nums(n, n + 4);
//	s.combinationSum(nums, 7);
//	system("pause");
//	return 0;
//}



/****************************************第三十六题*********************************************/
//#include <vector>;
//class Solution {
//public:
//	bool isValidSudoku(vector<vector<char>>& board) {
//		//solution
//		int count[9][9] = { 0 };
//		int count0[9][9] = { 0 };
//		int count00[9][9] = { 0 };
//		for (int i = 0; i < 9; i++) {
//			for (int j = 0; j < 9; j++) {
//				char t = board[i][j] - '0' - 1;
//				if (board[i][j] != '.') {
//					if (count[i][t] == 1)
//						return false;
//					count[i][t]++;
//					if (count0[t][j] == 1)
//						return false;
//					count0[t][j]++;
//					if (count00[i / 3 * 3 + j / 3][t] == 1)
//						return false;
//					count00[i / 3 * 3 + j / 3][t]++;
//				}
//			}
//		}
//
//		//检查横竖
//		//for (int i = 0; i < 9; i++) {
//		//	int count[9] = { 0 };
//		//	int count0[9] = { 0 };
//		//	for (int j = 0; j < 9; j++) {
//		//		char t = board[i][j];
//		//		if (t != '.') {
//		//			if (count[t - '0' - 1] == 1)
//		//				return false;
//		//			count[t - '0' - 1]++;
//		//		}
//		//		t = board[j][i];
//		//		if (t != '.') {
//		//			if (count0[t - '0' - 1] == 1)
//		//				return false;
//		//			count0[t - '0' - 1]++;
//		//		}
//		//	}
//		//	//检查小块
//		//	int count00[9] = { 0 };
//		//	for (int k = 0; k < 3; k++) {
//		//		for (int j = 0; j < 3; j++) {
//		//			char t = board[k + 3 * (i / 3)][j + 3 * (i % 3)];
//		//			//cout << k + 3 * (i / 3) << " " << j + 3 * (i % 3) << "    ";
//		//			if (t != '.') {
//		//				if (count00[t - '0' - 1] == 1)
//		//					return false;
//		//				count00[t - '0' - 1]++;
//		//			}
//		//		}
//		//	}
//		//}
//
//		//cout << "tttttt";
//		return true;
//	}
//};
//
//int main() {
//	Solution s;
//	vector<vector<char>> b{
//		{ '.','.','.','.','5','.','.','1','.'},
//		{'.','4','.','3','.','.','.','.','.'},
//		{'.','.','.','.','.','3','.','.','1'},
//		{'8','.','.','.','.','.','.','2','.'},
//		{'.','.','2','.','7','.','.','.','.'},	
//		{'.','1','5','.','.','.','.','.','.'},
//		{'.','.','.','.','.','2','.','.','.'},
//		{'.','2','.','9','.','.','.','.','.'},
//		{'.','.','4','.','.','.','.','.','.' }
//	};
//	s.isValidSudoku(b);
//	system("pause");
//	return 0;
//}



/****************************************第三十四题*********************************************/
//#include<vector>;
//class Solution {
//public:
//	vector<int> searchRange(vector<int>& nums, int target) {
//		int len = nums.size();
//		vector<int> tmp{ -1,-1 };
//		for (int i = 0; i < len; i++) {
//			if (nums[i] > target) break;
//			else if (nums[i] == target) {
//				if (i == 0 || nums[i - 1] < target) {
//					tmp[0]=i;
//				}
//				if (i == len - 1 || nums[i + 1] > target) {
//					tmp[1]=i;
//					break;
//				}
//			}
//		}
//		//cout << tmp[0] << " " << tmp[1];
//		return tmp;
//	}
//};
//
//int main() {
//	Solution s;
//	int n[7] = { 5,7,7,8,8,10,11 };
//	vector<int> nums(n, n + 6);
//	s.searchRange(nums, 5);
//	system("pause");
//	return 0;
//}



/****************************************第三十三题*********************************************/
//#include<vector>;
//class Solution {
//public:
//	int search(vector<int>& nums, int target) {
//		//solution 二分
//		//int len = nums.size();
//		//if (len == 0)
//		//	return -1;
//		//int left = 0;
//		//int right = len - 1;
//		//int mid = (left + right) / 2;
//		//while (left <= right) {
//		//	mid = (left + right) / 2;
//		//	cout << left << " " << right << " " << mid << endl;
//		//	if (target > nums[mid]) {
//		//		if (nums[left] > target) {
//		//			left = mid + 1;
//		//		}
//		//		else {
//		//			if (nums[left] < nums[mid]) {
//		//				left = mid + 1;
//		//			}
//		//			else {
//		//				if (nums[right] < target) {
//		//					right = mid - 1;
//		//				}
//		//				else left = mid + 1;
//		//			}
//		//		}
//		//	}
//		//	else if (target < nums[mid]) {
//		//		if (nums[right] < target) {
//		//			right = mid - 1;
//		//		}
//		//		else {
//		//			if (nums[mid] < nums[right]) {
//		//				right = mid - 1;
//		//			}
//		//			else {
//		//				if (nums[left] > target) {
//		//					left = mid + 1;
//		//				}
//		//				else right = mid - 1;
//		//			}
//		//		}
//		//	}
//		//	else {
//		//		cout << mid;
//		//		return mid;
//		//	}
//		//}
//		//return -1;
//
//		//思路
//		int len = nums.size();
//		if (len == 0)
//			return -1;
//		if (nums[0] < target) {
//			for (int i = 0; i < len; i++) {
//				if (nums[i] > target || nums[i] < nums[0])
//					return -1;
//				else if (nums[i] == target) {
//					cout << i;
//					return i;
//				}
//			}
//			return -1;
//		}
//		else if (nums[0] == target) return 0;
//		else if (nums[len - 1] > target) {
//			for (int i = len - 1; i >= 0; i--) {
//				if (nums[i] < target || nums[i]>nums[len - 1])
//					return -1;
//				else if (nums[i] == target) {
//					cout << i;
//					return i;
//				}
//			}
//			return -1;
//		}
//		else if (nums[len - 1] == target )return len - 1;
//		else return -1;
//	}
//};
//
//int main() {
//	Solution s;
//	int n[7] = { 5,1,2,3,4,1,2 };
//	vector<int> nums(n, n + 5);
//	s.search(nums, 1);
//	system("pause");
//	return 0;
//}



/****************************************第三十一题*********************************************/
//#include <vector>;
//class Solution {
//public:
//	void nextPermutation(vector<int>& nums) {
//		int len = nums.size();
//		if (len == 1 || len == 0) {
//			return;
//		}
//		int i = 0;
//		//判断是不是全是逆序
//		for (i; i < len-1; i++) {
//			if (nums[i] < nums[i + 1])
//				break;
//		}
//		//全是逆序，没有更大的排序
//		if (i == len-1) {
//			for (i = 0; i < len / 2; i++) {
//				int tmp = nums[i];
//				nums[i] = nums[len - i - 1];
//				nums[len - i - 1] = tmp;
//			}
//		}
//		//排成下一个更大的排序
//		else {
//			int left = len - 2;
//			int right = len - 1;
//			//从右边找到第一个比右边数字小的数字
//			while (left >= 0) {
//				if (nums[left] < nums[left+1]) {
//					break;
//				}
//				else left--;
//			}
//			//找到left右边比它大的最小的
//			int tmp = right;
//			//先找到第一个比它大的
//			while (right > left) {
//				if (nums[right] > nums[left]) {
//					tmp = right;
//					break;
//				}
//				right--;
//			}
//			//然后再找最小的
//			while (right > left) {
//				if (nums[right] > nums[left] && nums[right] < nums[tmp]) {
//					tmp = right;
//				}
//				right--;
//			}
//			right = tmp;
//			cout << left << " " << right;
//			//交换这两个
//			tmp = nums[right];
//			nums[right] = nums[left];
//			nums[left] = tmp;
//
//			//把后面的全部倒序
//			for (int j = left + 1; j <= (len - 1 + left) / 2; j++) {
//				//cout << nums[j] << " " << nums[len + left - j] << endl;
//				tmp = nums[j];
//				nums[j] = nums[len + left - j];
//				nums[len + left - j] = tmp;
//			}
//		}
//
//		for (int j = 0; j < len; j++) {
//			cout << nums[j] << " ";
//		}
//	}
//};
//
//int main() {
//	Solution s;
//	int n[5] = {2,3,1,3,3 };
//	vector<int> nums(n, n + 5);
//	s.nextPermutation(nums);
//	system("pause");
//	return 0;
//}



/****************************************第二十九题*********************************************/
//class Solution {
//public:
//	int divide(int dividend, int divisor) {
//		//solution
//		if (dividend == 0)
//			return 0;
//		if (divisor == 1) 
//			return dividend;			
//		if (divisor == -1) {
//			if (dividend == (-2147483647 - 1)) {
//				return 2147483647;
//			}				
//			return -dividend;
//		}			
//
//		int res = 0;
//		int flag = 1;
//		unsigned int udividend = dividend;
//		unsigned int udivisor = divisor;
//		if (dividend < 0) {
//			flag = -flag;
//			udividend = -dividend;
//		}
//		if (divisor < 0) {
//			flag = -flag;
//			udivisor = -divisor;
//		}
//		cout << udividend << " ";
//
//		while (udividend >= udivisor) {
//			long long  i = udivisor;
//			int count = 1;
//			while (udividend >= (i<<1)) {
//				i = i << 1;
//				count =count<<1;
//			}
//			udividend -= i;
//			res += count;
//		}
//
//		if (flag < 0)
//			res = -res;
//		cout << res;
//		return res;
//
//		//思路
//		//if (dividend == 0)
//		//	return 0;
//		//if (divisor == 1) 
//		//	return dividend;			
//		//if (divisor == -1) {
//		//	if (dividend == (-2147483647 - 1)) {
//		//		return 2147483647;
//		//	}				
//		//	return -dividend;
//		//}			
//
//		//int res = 0;
//		//int flag = 1;
//		//unsigned int udividend = dividend;
//		//unsigned int udivisor = divisor;
//		//if (dividend < 0) {
//		//	flag = -flag;
//		//	udividend = -dividend;
//		//}
//		//if (divisor < 0) {
//		//	flag = -flag;
//		//	udivisor = -divisor;
//		//}
//		//cout << udividend << " " << udivisor << " ";
//		//
//		//int two = 0, four = 0, eight = 0, sixteen = 0, thirtytwo = 0;
//		//two = udivisor + udivisor;
//		//if (two > 0) {
//		//	four = two + two;
//		//	if (four > 0) {
//		//		eight = four + four;
//		//		if (eight > 0) {
//		//			sixteen = eight + eight;
//		//			if (sixteen > 0) {
//		//				thirtytwo = sixteen + sixteen;
//		//			}
//		//		}
//		//	}
//		//}
//		////cout << two << "             " << four << "             " << eight << "             " << sixteen << "             " << thirtytwo << "             ";
//		//while (udividend >= udivisor) {
//		//	if (thirtytwo > 0 && udividend > thirtytwo) {
//		//		udividend -= thirtytwo;
//		//		res += 32;
//		//	}
//		//	else if (sixteen > 0 && udividend > sixteen) {
//		//		udividend -= sixteen;
//		//		res += 16;
//		//	}
//		//	else if (eight > 0 && udividend > eight) {
//		//		udividend -= eight;
//		//		res += 8;
//		//	}
//		//	else if (four > 0 && udividend > four) {
//		//		udividend -= four;
//		//		res += 4;
//		//	}
//		//	else if (two > 0 && udividend > two) {
//		//		udividend -= two;
//		//		res += 2;
//		//	}
//		//	else {
//		//		udividend -= udivisor;
//		//		res += 1;
//		//	}
//		//}
//		//if (flag < 0)
//		//	res = -res;
//		////cout << res;
//		//return res;
//	}
//};
//
//int main() {
//	Solution s;
//	s.divide(-2147483647-1,2);
//	system("pause");
//	return 0;
//}



/****************************************第二十四题*********************************************/
////Definition for singly-linked list.
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//	ListNode * swapPairs(ListNode* head) {
//		if (!head || !head->next) {
//			return head;
//		}
//
//		ListNode* first = head->next;
//		ListNode* second = head;
//		ListNode* last = nullptr;
//		head = first;
//
//		while(first&&second) {
//			second->next = first->next;
//			first->next = second;
//			if(last)
//				last->next = first;
//
//			last = second;
//			second = second->next;
//			if (second) {				
//				first = second->next;
//			}
//		}
//
//		//while (head) {
//		//	cout << head->val << "  ";
//		//	head = head->next;
//		//}
//		return head;
//	}
//};
//
//int main() {
//	Solution s;
//	ListNode l1(1);
//	ListNode l2(2);
//	ListNode l3(3);
//	ListNode l4(4);
//	ListNode l5(5);
//	l4.next = &l5;
//	l3.next = &l4;
//	l2.next = &l3;
//	l1.next = &l2;
//	s.swapPairs(&l1);
//	system("pause");
//	return 0;
//}



/****************************************第二十二题*********************************************/
//#include<vector>;
//class Solution {
//public:
//	vector<string> generateParenthesis(int n) {
//		vector<string> res;
//		int left = 0;
//		string str = "(";
//		parenthesis(n, 1, str, &res);
//		//cout << res.size();
//		return res;
//	}
//
//	void parenthesis(int n, int left, string str, vector<string>* res ) {
//		int len = str.size();
//		if (len < 2 * n-1) {
//			if (left > len - left) {
//				parenthesis(n, left, str + ")", res);
//			}
//			if (left < n) {
//				parenthesis(n, left + 1, str + "(", res);
//			}
//		}
//		else {
//			str += ")";
//			res->push_back(str);
//			//cout << str.c_str() << endl;
//		}		
//	}
//};
//
//int main() {
//	Solution s;
//	s.generateParenthesis(3);
//	system("pause");
//	return 0;
//}



/****************************************第十九题*********************************************/
////Definition for singly-linked list.
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};

//class Solution {
//public:
//	ListNode * removeNthFromEnd(ListNode* head, int n) {
//		ListNode* last = head;
//		ListNode* tmp;
//		
//		while (n > 0) {
//			last = last->next;
//			n--;
//		}
//
//		if (!last) {
//			head = head->next;
//		}
//		else {
//			tmp = head;
//			while (last->next) {
//				last = last->next;
//				tmp = tmp->next;
//			}
//			tmp->next = tmp->next->next;
//		}
//
//		//while (head) {
//		//	cout << head->val << " ";
//		//	head = head->next;
//		//}
//		return head;
//	}
//};
//
//int main() {
//	Solution s;
//	ListNode l1(1);
//	ListNode l2(2);
//	ListNode l3(3);
//	ListNode l4(4);
//	ListNode l5(5);
//	l4.next = &l5;
//	l3.next = &l4;
//	l2.next = &l3;
//	l1.next = &l2;
//	s.removeNthFromEnd(&l1, 1);
//	system("pause");
//	return 0;
//}



/****************************************第十八题*********************************************/
//#include <vector>;
//#include<algorithm>;
//class Solution {
//public:
//	vector<vector<int>> fourSum(vector<int>& nums, int target) {
//		vector<vector<int>> res;
//		int len = nums.size();
//		if (len == 0)
//			return res;
//		if (len < 4)
//			return res;
//
//		//先排序
//		sort(nums.begin(), nums.end());
//
//		for (int i = 0; i < len - 3; i++) {
//			for (int j = len - 1; j > i&&j > 2; j--) {
//				int t = i + 1;
//				int k = j - 1;
//				if ((nums[i] + nums[j] + nums[t] + nums[t + 1] > 0) || (nums[i] + nums[j] + nums[k] + nums[k - 1]) < 0)
//					t = k;
//				while (t < k) {
//					int sum = nums[i] + nums[j] + nums[t] + nums[k];
//					if (sum == target) {
//						vector<int> tmp = { nums[i],nums[j],nums[t],nums[k] };
//						res.push_back(tmp);
//						while (nums[t] == nums[t + 1]) {
//							t++;
//						}
//						t++;
//						while (nums[k] == nums[k - 1]) {
//							k--;
//						}
//						k--;
//					}
//					else if (sum < target) {
//						t++;
//					}
//					else k--;
//				}
//				while (nums[j] == nums[j - 1]) {
//					j--;
//				}
//			}
//			while (nums[i] == nums[i + 1]) {
//				i++;
//			}
//		}
//
//		for (int i = 0; i < res.size(); i++) {
//			for (int j = 0; j < res[i].size(); j++) {
//				cout << res[i][j] << " ";
//			}
//			cout << endl;
//		}
//
//		return res;
//	}
//};
//
//int main() {
//	Solution s;	
//	int n[6] = { 1, 0, -1, 0, -2, 2 };
//	vector<int> nums(n, n + 6);
//	s.fourSum(nums, 0);
//	system("pause");
//	return 0;
//}



/****************************************第十七题*********************************************/
//class Solution {
//public:
//	vector<string> letterCombinations(string digits) {
//		vector<string> res;
//		int len = digits.length();
//		for (int i = 0; i < len; i++) {
//			char l1;
//			char l2;
//			char l3;
//			char l4 = ' ';
//			switch (digits[i]) {
//			case '2': {
//				l1 = 'a'; l2 = 'b'; l3 = 'c'; break;
//			}
//			case '3': {
//				l1 = 'd'; l2 = 'e'; l3 = 'f'; break;
//			}
//			case '4': {
//				l1 = 'g'; l2 = 'h'; l3 = 'i'; break;
//			}
//			case '5': {
//				l1 = 'j'; l2 = 'k'; l3 = 'l'; break;
//			}
//			case '6': {
//				l1 = 'm'; l2 = 'n'; l3 = 'o'; break;
//			}
//			case '7': {
//				l1 = 'p'; l2 = 'q'; l3 = 'r'; l4 = 's'; break;
//			}
//			case '8': {
//				l1 = 't'; l2 = 'u'; l3 = 'v'; break;
//			}
//			case '9': {
//				l1 = 'w'; l2 = 'x'; l3 = 'y'; l4 = 'z'; break;
//			}
//			}
//
//			if (i == 0) {
//				string tmp;
//				tmp = l1;
//				res.push_back(tmp);
//				tmp = l2;
//				res.push_back(tmp);
//				tmp = l3;
//				res.push_back(tmp);
//				if (l4 != ' ') {
//					tmp = l4;
//					res.push_back(tmp);
//				}
//			}
//			else {
//				int size = res.size();
//				for (int j = 0; j < size; j++) {
//					string str = res[j];
//					res[j] += l1;
//					//cout << res[j]<<" ";
//					//cout << str + l2 << endl;
//					res.push_back(str + l2);
//					res.push_back(str + l3);
//					if (l4 != ' ') {
//						res.push_back(str + l4);
//					}
//				}
//			}
//		}
//
//		//for (int i = 0; i < res.size(); i++) {
//		//	cout << res[i] << " ";
//		//}
//		return res;
//	}
//};
//
//int main() {
//	Solution s;
//	string d = "23";
//	s.letterCombinations(d);
//	system("pause");
//	return 0;
//}



/****************************************第十六题*********************************************/
//#include<vector>;
//#include<algorithm>;
//class Solution {
//public:
//	int threeSumClosest(vector<int>& nums, int target) {
//		
//		//solution
//		//sort(nums.begin(),nums.end());
//
//		//int res = nums[0] + nums[1] + nums[2];
//		//int len = nums.size();
//		//int lastdis = target > res ? (target - res) : (res - target);
//		//int dis = 0;
//		//for (int i = 0; i < len-2; i++) {
//		//	int j = i + 1;
//		//	int k = len - 1;
//		//	while (j < k) {
//		//		int sum = nums[i] + nums[j] + nums[k];
//		//		if (target == sum) {
//		//			return sum;
//		//		}
//		//		dis = target - sum;
//		//		if (dis > 0) {
//		//			j++;
//		//		}
//		//		else {
//		//			k--;
//		//			dis = 0 - dis;
//		//		}
//		//		if (dis < lastdis) {
//		//			lastdis = dis;
//		//			res = sum;
//		//		}
//		//	}
//		//}
//
//		//基础思路
//		int res = nums[0] + nums[1] + nums[2];
//		int len = nums.size();
//		int lastdis = target > res ? (target - res) : (res - target);
//		int dis = 0;
//		for (int i = 0; i < len-2; i++) {
//			for (int j = i + 1; j < len-1; j++) {
//				for (int k = j + 1; k < len; k++) {
//					int sum = nums[i] + nums[j] + nums[k];
//					if (target == sum) {
//						return sum;
//					}
//					dis = target > sum ? (target - sum) : (sum - target);
//					if (dis < lastdis) {
//						res = sum;
//						lastdis = dis;
//					}
//				}
//			}
//		}
//
//		cout << res;
//		return res;
//	}
//};
//
//int main() {
//	Solution s;
//	int n[4] = { -1,2,1,-4 };
//	vector<int> nums(n, n + 4);
//	s.threeSumClosest(nums, 1);
//	system("pause");
//	return 0;
//}



/****************************************第十五题*********************************************/
//#include<vector>;
//#include <algorithm>;
//class Solution {
//public:
//	vector<vector<int>> threeSum(vector<int> &nums) {
//		//solution1
//		vector<vector<int>> res;
//		int len = nums.size();
//		if (len == 0)
//			return res;
//		if (len < 3)
//			return res;
//
//		//先排序
//		sort(nums.begin(), nums.end());
//
//		//后处理
//		//左边负的，右边正的
//		for (int i = 0; i < len - 2; i++) {
//			int j = i + 1;
//			int k = len - 1;
//			while (j < k) {
//				int sum = nums[i] + nums[j] + nums[k];
//				if (sum == 0) {
//					vector<int> tmp = { nums[i],nums[j],nums[k] };
//					res.push_back(tmp);
//					while (nums[j] == nums[j + 1]) {
//						j++;
//					}
//					j++;
//					while (nums[k] == nums[k - 1]) {
//						k--;
//					}
//					k--;
//				}
//				else if (sum < 0) {
//					j++;
//				}
//				else k--;
//			}
//			while (nums[i] == nums[i + 1]) {
//				i++;
//			}
//		}
//
//		////思路，太慢了		
//		//vector<vector<int>> res;
//		//int len = nums.size();
//		//if (len == 0)
//		//	return res;
//		//if (len < 3)
//		//	return res;
//		////先排序
//		//sort(nums.begin(), nums.end());
//
//		////后处理
//		//int left = 0;
//		//int right = len - 1;
//		//int third = 0;
//		//int target = 0;
//		////左边负的，右边正的
//		//while (left < len&&nums[left] <= 0) {
//		//	while (right > (left+1) && nums[right] >= 0) {
//		//		target = 0 - nums[left] - nums[right];
//		//		//cout << target << " ";
//		//		//第三个指针从右边检查正的
//		//		if (target > 0) {
//		//			third = right - 1;
//		//			while (nums[third] >= 0) {
//		//				//cout << nums[left] << " " << nums[right] << " " << nums[third] << endl;
//		//				if (nums[third] == target) {
//		//					vector<int> tmp = { nums[left],nums[right],nums[third] };
//		//					res.push_back(tmp);							
//
//		//					break;
//		//				}
//		//				//最大的也不够大
//		//				else if (nums[third] < target) {
//		//					break;
//		//				}
//		//				else third--;
//		//			}
//		//		}
//		//		//第三个指针从左边检查负的
//		//		else {
//		//			third = left + 1;
//		//			while (nums[third] <= 0) {
//		//				//cout << nums[left] << " " << nums[right] << " " << nums[third] << endl;
//		//				if (nums[third] == target) {
//		//					vector<int> tmp = { nums[left],nums[right],nums[third] };
//		//					res.push_back(tmp);							
//
//		//					break;
//		//				}
//		//				//最小的还不够小
//		//				else if (nums[third] > target) {
//		//					break;
//		//				}
//		//				else third++;
//		//			}
//		//		}
//		//		//先左移，然后对当前检查是否和上一位相同
//		//		right--;
//		//		while (right>=0&&nums[right] == nums[right+1]) {
//		//			right--;
//		//		}
//		//	}
//		//	//先右移，然后检查是否和上一位相同
//		//	left++;
//		//	while (left<len&&nums[left] == nums[left-1]) {
//		//		left++;
//		//	}
//		//	right = len - 1;
//		//}
//
//		for (int i = 0; i < res.size(); i++) {
//			for (int j = 0; j < res[i].size(); j++) {
//				cout << res[i][j] << " ";
//			}
//			cout << endl;
//		}
//
//		return res;
//	}
//};
//
//int main() {
//	Solution s;
//	//int n[6] = { 0,0,0,2,-1,4 };
//	int n[16] = { -4,-2,-2,-2,0,0,0,0,2,3,3,4,4,6,6};
//	vector<int> nums(n, n + 15);
//	s.threeSum(nums);
//	system("pause");
//	return 0;
//}



/****************************************第十二题*********************************************/
//#include <string>;
//class Solution {
//public:
//	string intToRoman(int num) {
//		string res = "";
//		int nums[13] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
//		string roman[13] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
//		int pointer = 0;
//		int t = 0;
//		while (num > 0) {
//			if (num >= nums[pointer]) {
//				res += roman[pointer];
//				num = num - nums[pointer];
//			}
//			else pointer++;
//		}
//		cout << res.c_str();
//		return res;
//
//		//基础思路
//		//string res = "";
//		//int nums[7] = { 1000,500,100,50,10,5,1 };
//		//char roman[7] = { 'M','D','C','L','X','V','I' };
//		//int pointer = 0;
//		//while (num > 0) {
//		//	//当前位
//		//	int t = num / nums[pointer];
//		//	//下一位
//		//	int t0 = 0;
//		//	//如果没到结尾
//		//	if (pointer <= 6)
//		//		t0 = num / nums[pointer+1];
//
//		//	//如果当前位是4要处理
//		//	if (t == 4) {
//		//		res += roman[pointer];
//		//		res += roman[pointer - 1];
//		//	}
//		//	//如果下一位是9
//		//	else if (t0 == 9) {
//		//		res += roman[pointer + 1];
//		//		res += roman[pointer - 1];
//		//		pointer++;
//		//	}
//		//	//如果是普通情况
//		//	else {
//		//		for (int i = 0; i < t; i++) {
//		//			res += roman[pointer];
//		//		}
//		//	}
//		//	//cout << res.c_str() <<" "<< nums[pointer] <<" "<<t << endl;
//		//	num = num % nums[pointer];
//		//	pointer++;
//		//}
//		//cout << res.c_str();
//		return res;
//	}
//};
//
//int main() {
//	Solution s;
//	int n = 58;
//	s.intToRoman(n);
//	system("pause");
//	return 0;
//}



/****************************************第十一题*********************************************/
//#include<vector>;
//#include<algorithm>;
//class Solution {
//public:
//	int largest(vector<int>& height){
//		//solution
//		int len = height.size();
//		int res = 0;
//		int i = 0;
//		int j = len - 1;
//		while (i < j) {
//			int tmp;
//			if (height[i] <= height[j]) {
//				tmp = height[i] * (j - i);
//				i++;
//			}
//			else {
//				tmp = height[j] * (j - i);
//				j--;
//			}
//			res = max(tmp, res);
//		}
//		//cout << res;
//		return res;
//
//		//基础思路
//		//int len = height.size();
//		//int res = 0;
//		//for (int i = 0; i < len; i++) {
//		//	for (int j = i + 1; j < len; j++) {
//		//		int tmph = min(height[i], height[j]);
//		//		int tmp = tmph * (j - i);
//		//		res = max(tmp, res);
//		//	}
//		//}
//		////cout << res;
//		//return res;
//	}
//};
//
//int main() {
//	int num[9] = { 1,8,6,2,5,4,8,3,7 };
//	vector<int> nums(num, num + 9);
//	Solution s;
//	s.largest(nums);
//	system("pause");
//	return 0;
//}



/****************************************第八题*********************************************/
//#include<string>;
//class Solution {
//public:
//	int getint(string str) {
//		int res=0;
//		int i = 0;
//		//正负标记
//		int flag = 1;
//		//溢出标记
//		int flagout = 0;
//		//处理空格
//		while (str[i] == ' ') {
//			i++;
//		}
//		//处理符号
//		if (str[i] == '-') {
//			flag = 0;
//			i++;
//		}
//		else if (str[i] == '+') {
//			i++;
//		}
//
//		//处理数字，如果溢出？？？？
//		while (str[i] >= 48 && str[i] <= 57) {
//			if (res >= 214748365) {
//				flagout = 1;
//				res = 2147483647;
//				break;
//			}
//			res *= 10;
//			int tmp = str[i] - '0';
//			res += tmp;
//			if (res < 0) {
//				flagout = 1;
//				res = 2147483647;
//				break;
//			}
//			i++;
//		}
//		//处理结果
//		if (flag == 0) {
//			res = -res;
//		}
//		if (flag==0&&flagout==1){
//			res = 2147483648;
//			res = -res;
//		}
//		//cout << res;
//		return res;
//	}
//};
//
//int main() {
//	string ss= "2147483646";
//	Solution s;
//	s.getint(ss);
//	system("pause");
//	return 0;
//}



/****************************************第六题*********************************************/
//#include <string>;
//#include <vector>;
//class Solution {
//public:
//	string getz(string s,int numRows) {
//		//solution1关键是遇到空格就不记录！
//		string res;
//		float len = s.length();
//		int rows = numRows - 1;
//
//		if (numRows == 1 || len < numRows) {
//			return s;
//		}
//
//		vector<string> z(numRows);
//
//		//i:string的迭代器，j:行数迭代器，k:列数，tmp:余数
//		int i = 0; int j = 0; int k = 0; int tmp = 0;
//		//每次循环处理一个
//		while (i < len)
//		{
//			//如果是满的列
//			if (tmp == 0) {
//				z[j]+= s[i];
//				i++;
//			}
//			//如果是不满的列，先全部置空然后修改对的一个
//			else {
//				if (j == (rows - tmp)) {
//					z[rows - tmp]+=s[i];
//					i++;
//				}
//			}
//
//			j++;
//			//换列
//			if (j == numRows) {
//				k++;
//				tmp = k % rows;
//				j = 0;
//			}
//		}
//
//		for (int i = 0; i < numRows; i++) {
//			res += z[i];
//			//cout << endl;
//		}
//
//		//cout << res;
//		return res;
		//
		////稍微改一下
		////if (numRows == 1) {
		////	return s;
		////}
		////string res;
		////float len = s.length();
		////int rows = numRows - 1;
		////char **z;
		//////分配空间
		////z = new char *[numRows];
		////int t = (numRows - 1) * ceil(len / (2 * numRows - 2));
		////for (int i = 0; i < numRows; i++) {
		////	z[i] = new char[t]();
		////}

		//////i:string的迭代器，j:行数迭代器，k:列数，tmp:余数
		////int i = 0; int j = 0; int k = 0; int tmp = 0;
		//////每次循环处理一个
		////while (i < len)
		////{
		////	//如果是满的列
		////	if (tmp == 0) {
		////		z[j][k] = s[i];
		////		i++;
		////	}
		////	//如果是不满的列，先全部置空然后修改对的一个
		////	else {
		////		z[j][k] = 0;
		////		if (j == (rows - tmp)) {
		////			z[j][k] = s[i];
		////			i++;
		////		}
		////	}

		////	j++;
		////	//换列
		////	if (j == numRows) {
		////		k++;
		////		tmp = k % rows;
		////		j = 0;
		////	}
		////}

		////for (int i = 0; i < numRows; i++) {
		////	for (int j = 0; j < t; j++) {
		////		//cout << z[i][j] << " ";
		////		if (z[i][j] != 0) {
		////			res += z[i][j];
		////		}
		////	}
		////	//cout << endl;
		////}

		////cout << res;
		//////释放空间
		////for (int i = 0; i < numRows; i++) {
		////	delete z[i];
		////}
		////delete z;
		////return res;
//	}
//};
//
//int main() {
//	string ss = "PA";
//	Solution s;
//	s.getz(ss,4);
//
//	system("pause");
//	return 0;
//}



/****************************************第五题*********************************************/
//#include <string.h>;
//#include <vector>;
//class Solution {
//public:
//	string longestPalindrome(string s) {
//		string res = "";
//      //
//		//倒序字符串
//		string s0 = s;
//		int len = s.length();
//		for (int i = 0; i < len; i++) {
//			s0[len - i-1] = s[i];
//		}
//		//cout << s0.c_str() << endl;
//		for (int i = 0; i < len-res.length(); i++) {
//			for (int j = i+1; j < len; j++) {
//				string tmp = s0.substr(i, j - i+1);
//				if (s.find(tmp) != s.npos) {
//					string tmprev = tmp;
//					int tmplen = tmp.length();
//					for (int k = 0; k < tmplen; k++) {
//						tmprev[tmplen - k - 1] = tmp[k];
//					}
//					if (s.find(tmp) == s.find(tmprev)) {
//						//cout << tmp.c_str() << endl;
//						if (res.length() < tmp.length())
//							res = tmp;
//					}
//				}
//			}
//		}
//		if (res == "")
//			res = s[0];
//		
//		//基础思路
//		//for (int i = 0; i < s.length() - res.length(); i++) {
//		//	for (int j = s.length(); j > (i+res.size()); j--) {
//		//		//判断s(i,j)是否回文
//		//		int k;
//		//		for (k = 0; k < ((j - i) / 2); k++) {	
//		//			if (s[i + k] != s[j - k - 1])
//		//				break;
//		//		}
//		//		if (k == (j - i) / 2) {
//		//			//cout << res.c_str() << " " << s.substr(i, j - i).c_str() << endl;
//		//			if(res.length()<(j-i))
//		//				res = s.substr(i, j - i);
//		//		}
//		//	}
//		//}
//		cout << res.c_str() << endl;
//		return res;
//	}
//};
//
//int main() {
//	string ss = "aacdefcaa";
//	Solution s;
//	s.longestPalindrome(ss);
//
//	system("pause");
//	return 0;
//}



/****************************************第三题*********************************************/
//#include <string.h>;
//#include <map>;
//#include <algorithm>;
//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) {
//		//葛林成思路
//		int length = 0;
//		map<char,int> pos;
//		//初始化pos
//		char tmp;
//		for (int i = 0; i < s.length(); i++) {
//			tmp = s[i];
//			pos[tmp] = 0;
//		}
//		//距离最近的上一个重复位(类似左指针）
//		int lasti = 0;
//		for (int i = 0; i < s.length(); i++) {
//			//遇到有重复
//			if (pos[s[i]] != 0) {
//				length = max(length , (i-lasti));
//				lasti = max(lasti , (pos[s[i]]));
//				//cout <<length<<" "<< lennew <<" "<< lasti << " " << pos[s[i]] << endl;
//			}
//			//结束后处理最后一段
//			if (i == (s.length() - 1)) {
//				length = (length > (s.length() - lasti)) ? length : (s.length() - lasti);
//			}
//			pos[s[i]] = i + 1;
//		    //cout << pos[s[i]] << " " << s[i] << endl;
//		}
//
//		////存疑思路
//		//int length = 0;
//		//for (int i = 0; i < s.length(); i++) {
//		//	int pos = i;
//		//	length = pos;
//		//	int position = s.find(s[i], pos+1);
//		//	//没有和它重复的，就把position设为最后
//		//	if (position == -1) {
//		//		length = s.length() - i;
//		//	}
//		//	//找出和当前位不重复的最长子串
//		//	while (position != -1) {
//		//		position = s.find(s[i], pos);
//		//		cout << position <<" "<<i<< endl;
//		//		if (length < (position - i)) {
//		//			length = position - i;
//		//			//i=
//		//		}
//		//		pos ++;
//		//		cout << length << endl;
//		//	}
//		//	s = s.substr(i, length);
//		//	cout << s.c_str() << endl;
//		//	length = lengthOfLongestSubstring(s);
//		//}
//
//		//思路1
//		//int length = 0;
//		//for (int i = 0; i < s.length() - length; i++) {
//		//	int j = i + 1;
//		//	for (j = i+1; j < s.length(); j++) {
//		//		int k = i;
//		//		for (k = i; k < j; k++) {
//		//			if (s[k] == s[j])
//		//				break;
//		//		}
//		//		if (k != j) {
//		//			break;
//		//		}
//		//	}
//		//	length = (length >(j - i)) ? length : (j - i);
//		//}
//		cout << length << endl;
//		return length;
//	}
//};
//
//int main() {
//	string ss = "tmmzuxt";
//	Solution s;
//	s.lengthOfLongestSubstring(ss);
//
//	system("pause");
//	return 0;
//}



/****************************************第二题*********************************************/
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
//		ListNode* res;
//		ListNode ret(-1);
//		res = &ret;
//		//cout << ret->val << endl;
//	    int n1 = 0;
//		int n2 = 0;
//		int num = 0;
//		int tmp = 0;
//		while (l1||l2) {
//			if (l1){
//				n1 = l1->val;
//				l1 = l1->next;
//			}
//			else n1 = 0;
//			if (l2) {
//				n2 = l2->val;
//				l2 = l2->next;
//			}
//			else n2 = 0;
//			num = n1 + n2 + tmp;
//			tmp = num / 10;
//			ListNode* t = new ListNode(num % 10);
//			res->next = t;
//			//cout << ret.val << endl;
//			//if (ret.val == 0) {
//			//	ret = res;
//			//}
//			//cout << res.val << endl;
//			res = res->next;
//		}
//		if (tmp != 0) {
//			ListNode* t = new ListNode(tmp);
//			res->next = t;
//			//cout << res->val << endl;
//			//res = *res.next;
//		}
//		//while (ret.next) {
//		//	cout << ret.val << endl;
//		//	ret = *ret.next;
//		//}
//		return ret.next;
//	}
//};
//
//int main() {
//	ListNode l1(5);
//	ListNode l2(6);
//	ListNode tmp21(9);
//	ListNode tmp22(9);
//	tmp21.next = &tmp22;
//	l2.next = &tmp21;
//
//	Solution s;
//	s.addTwoNumbers(&l1, &l2);
//	system("pause");
//	return 0;
//}