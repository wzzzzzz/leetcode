#include <iostream>;
using namespace std;

#include<vector>;
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		int len = s.length();
		vector<string> res;
		if (len < 4) {
			return res;
		}
		if (len == 12) {
			string tmp;
			for (int i = 0; i < 12; i+=3) {
				int t = (s[i] - '0') * 100 + (s[i + 1] - '0') * 10 + s[i + 2] - '0';
				if (t > 255 || t < 1) {
					cout << t<<" ";
					return res;
				}
				else {
					tmp = tmp + s[i] + s[i + 1] + s[i + 2];
					if (i < 9) {
						tmp += ".";
					}
				}
			}
			res.push_back(tmp);
		}
		else {
			string tmp = "";
			getip(&res,s, tmp, 0, 0, len);
		}
		for(int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++) {
				cout << res[i][j];
			}
			cout << endl;
		}
		return res;
	}
	void getip(vector<string>* res,string s,string tmp,int ind,int index, int len) {
		if (index==len) {			
			tmp = tmp.substr(0, tmp.size() - 1);
			(*res).push_back(tmp);
			return;
		}
		if (ind > 3) {
			return;
		}
		int left = len - 1 - index;
		if (left > 3 * (4 - ind) || left < 1 * (4 - ind)) {
			return;
		}
		string t = tmp;
		if (s[index] - '0' >=0) {
			tmp = tmp + s[index] + ".";
			getip(res, s, tmp, ind + 1, index + 1, len);
			tmp = t;
		}
		if (index < len - 1 && s[index] - '0'>0) {
			tmp = tmp + s[index] + s[index + 1] + ".";
			getip(res, s, tmp, ind + 1, index + 2, len);
			tmp = t;
		}
		if (index < len - 2 && s[index] - '0'>0 && s[index+1] - '0'>0 && ((s[index] - '0') * 100 + (s[index + 1] - '0') * 10 + s[index + 2] - '0') < 256) {
			tmp = tmp + s[index] + s[index + 1] + s[index + 2] + ".";
			getip(res, s, tmp, ind + 1, index + 3, len);
			tmp = t;
		}
	}
};

int main() {
	string ss = "25525511135";
	Solution s;
	s.restoreIpAddresses(ss);
	system("pause");
	return 0;
}



/****************************************第九十二题*********************************************/
//Definition for singly-linked list.
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//	ListNode * reverseBetween(ListNode* head, int m, int n) {
//		if (m == n)
//			return head;
//		ListNode* res = head;
//		ListNode reverse = NULL;
//		ListNode* reversefirst = head;
//		ListNode tmp = NULL;
//		ListNode* before = NULL;
//		ListNode* later = head;
//		int ind = 1;
//		while (head&&ind <= n+1) {
//			if (ind == m - 1) {
//				before = head;
//				ind++;
//				head = head->next;
//			}
//			if (ind >= m && ind <= n) {
//				if (ind == m) {
//					reversefirst = head;
//				}	
//				tmp = ListNode(head->val);
//				head = head->next;
//				tmp.next = &reverse;
//				ListNode tmpp = tmp;
//
//				int t = tmp.val;
//				reverse.val = t;
//				cout << tmpp.val << endl;
//				if (ind > m) {
//					cout << tmpp.next->val << endl;
//				}
//				reverse.next = &tmpp;
//				//cout << tmp.val << " " << tmp.next->val << endl;
//				//cout << reverse.val << " " << reverse.next->val << " ";
//				if (ind > m + 1) {
//					//cout << reverse.next->next->val << endl;
//				}
//				cout << tmpp.val << endl;
//				if (ind > m) {
//					cout << tmpp.next->val << endl;
//				}
//				//tmp = *head;
//				//head = head->next;
//				//tmp.next = &reverse;
//				//reverse.next = tmp.next;
//				//cout << tmp.val << " " << tmp.next->val << endl;
//				//cout << reverse.val << " " << tmp.val << endl;
//				//int t = tmp.val;
//				//reverse.val = t;
//				//cout << tmp.val << " " << tmp.next->val << endl;
//				//cout << reverse.val << " " << reverse.next->val << " " << reverse.next->next->val << endl;
//				ind++;
//			}
//			if (ind == n + 1) {
//				later = head;
//				break;
//			}
//		}
//		cout << reverse.val << " " << reverse.next->val << " " << reverse.next->next->val << endl;
//		before->next = &reverse;
//		reversefirst->next = later;
//		
//		//while (reverse.next) {
//		//	cout << reverse.val << " ";
//		//	reverse = *reverse.next;
//		//}
//		return res;
//	}
//};
//
//int main() {
//	ListNode l1(1);
//	ListNode l2(2);
//	ListNode l3(3);
//	ListNode l4(4);
//	ListNode l5(5);
//	ListNode l6(6);
//	l1.next = &l2;
//	l2.next = &l3;
//	l3.next = &l4;
//	l4.next = &l5;
//	l5.next = &l6;
//
//	Solution s;
//	s.reverseBetween(&l1,2,5);
//	system("pause");
//	return 0;
//}



/****************************************第九十一题*********************************************/
//#include<vector>;
//class Solution {
//public:
//	int numDecodings(string s) {
//		int len = s.length();
//		vector<int> res(len + 1, 0);
//		if (len == 0)
//			return 0;
//		if (s[0] == '0')
//			return 0;
//		if (len == 1) {
//			return 1;
//		}
//
//		res[0] = 1;
//		for (int i = 1; i < len; i++) {
//			if (s[i] == '0') {
//				if (s[i - 1] - '0' > 2 || s[i - 1] == '0') {
//					return 0;
//				}
//				else {
//					if (i == 1) {
//						res[i] = 1;
//					}
//					else res[i] = res[i - 2];
//				}
//			}
//			else {
//				if ((s[i - 1] - '0') * 10 + s[i] - '0'>26 || s[i - 1] == '0') {
//					res[i] = res[i - 1];
//				}
//				else {
//					if (i == 1) {
//						res[i] = 2;
//					}
//					else res[i] = res[i - 1] + res[i - 2];
//				}
//			}
//		}
//
//		return res[len - 1];
//	}
//};
//
//int main() {
//	Solution s;
//	string ss = "1022";
//	s.numDecodings(ss);
//	system("pause");
//	return 0;
//}



/****************************************第九十题*********************************************/
//#include<vector>;
//#include<algorithm>;
//class Solution {
//public:
//	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//		int len = nums.size();
//		sort(nums.begin(), nums.end());
//
//		vector<vector<int>> res;
//		res.push_back(vector<int>{});
//		vector<int> max;
//		for (int i = 0; i < len; i++) {
//			res.push_back(vector<int>{nums[i]});
//			max.push_back(nums[i]);
//			while (i < len - 1 && nums[i] == nums[i + 1]) {
//				i++;
//				max.push_back(nums[i]);
//			}
//		}
//		if (len > 1) {
//			res.push_back(max);
//		}
//		vector<int> tmp;
//		vector<int> nextnums = nums;
//		//i是结果的长度
//		for (int i = 2; i < len; i++) {
//			getsubsets(res, tmp, nextnums, i);
//		}
//
//		for (int i = 0; i < res.size(); i++) {
//			for (int j = 0; j < res[i].size(); j++) {
//				cout << res[i][j] << " ";
//			}
//			cout << endl;
//		}
//		return res;
//	}
//
//	//res是结果，tmp是暂存的当前数组，nums是剩下的可用的数组，k是还剩几个名额
//	void getsubsets(vector<vector<int>> &res, vector<int> &tmp, vector<int>& nums, int k) {
//		int len = nums.size();
//		if (k == 1) {
//			for (int j =len-1; j >=0; j--) {
//				tmp.push_back(nums[j]);
//				res.push_back(tmp);
//				tmp.pop_back();
//				while (j >0 && nums[j] == nums[j - 1]) {
//					j--;
//				}
//			}
//			return;
//		}
//		vector<int> nextnums = nums;
//		for (int j = len; j >= k; j--) {
//			tmp.push_back(nums[j-1]);
//			nextnums.pop_back();
//			getsubsets(res, tmp, nextnums, k - 1);
//			tmp.pop_back();
//			while (j > k&&nums[j-2] == nums[j - 1]) {
//				j--;
//				nextnums.pop_back();
//			}
//		}
//	}
//};
//
//int main() {
//	Solution s;
//	vector<int> nums{ 1,4,3,4,4,0};
//	s.subsetsWithDup(nums);
//	system("pause");
//	return 0;
//}



/****************************************第八十九题*********************************************/
//#include<vector>;
//#include<algorithm>;
//class Solution {
//public:
//	vector<int> grayCode(int n) {
//		vector<int> res;
//		if (n == 0) {
//			return vector<int>{0};
//		}
//		vector<vector<int>> restwo;
//		restwo.push_back(vector<int>{0});
//		restwo.push_back(vector<int>{1});
//		for (int i = 2; i <= n; i++) {
//			int len = restwo.size();
//			for (int j = len-1; j >=0; j--) {
//				vector<int> tmp = restwo[j];
//				restwo[j].push_back(0);
//				tmp.push_back(1);
//				restwo.push_back(tmp);
//			}
//		}
//		for (int i = 0; i < restwo.size(); i++) {
//			res.push_back(twoToten(restwo[i]));
//		}
//		return res;
//	}
//	int twoToten(vector<int> nums) {
//		int len = nums.size();
//		int res = 0;
//		for (int i = 0; i < len; i++) {
//			res *= 2;
//			res += nums[i];
//		}
//		return res;
//	}
//};
//
//int main() {
//	Solution s;
//	s.grayCode(0);
//	system("pause");
//	return 0;
//}



/****************************************第八十六题*********************************************/
//Definition for singly-linked list.
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//	ListNode * partition(ListNode* head, int x) {
//		if (head == NULL || head->next == NULL) {
//			return head;
//		}
//		ListNode* beforelarge = NULL;
//		ListNode* large = head;
//		ListNode* small = head->next;
//		ListNode* beforesmall = head;
//		while (large) {
//			if (large->val < x) {
//				beforelarge = large;
//				large = large->next;
//			}
//			else break;
//		}
//
//		if (large) {
//			beforesmall = large;
//			small = large->next;
//		}
//		else return head;
//
//		while (small) {
//			if (small->val < x) {
//				//移动
//				beforesmall->next = small->next;
//				small->next = large;
//				if (beforelarge == NULL) {
//					head = small;
//					beforelarge = small;
//				}
//				else {
//					beforelarge->next = small;
//					beforelarge = small;
//				}
//				small = beforesmall->next;
//			}
//			else {
//				beforesmall = small;
//				small = small->next;
//			}
//		}
//
//		while (head) {
//			cout << head->val<<" ";
//			head = head->next;
//		}
//		return head;
//	}
//};
//
//int main() {
//	ListNode l1(1);
//	ListNode l2(1);
//	//ListNode l3(3);
//	//ListNode l4(2);
//	//ListNode l5(5);
//	//ListNode l6(2);
//	l1.next = &l2;
//	//l2.next = &l3;
//	//l3.next = &l4;
//	//l4.next = &l5;
//	//l5.next = &l6;
//
//	Solution s;
//	s.partition(&l1,3);
//	system("pause");
//	return 0;
//}



/****************************************第八十题*********************************************/
//#include<vector>;
//class Solution {
//public:
//	int removeDuplicates(vector<int>& nums) {
//		int len = nums.size();
//		int res = len;
//		if (len < 3)
//			return res;
//		int flag = nums[0] - 1;
//		int num = nums[0];
//		int count = 1;
//		for (int i = 1; i < len; i++) {
//			if (nums[i] == num) {
//				count++;
//			}
//			else {
//				count = 1;
//				num = nums[i];
//			}
//			if (count > 2) {
//				nums[i] = flag;
//				res--;
//			}
//		}
//		//i是重复的，j是被交换的
//		int i = 0, j = 1;
//		while ( i < len&&j < len) {
//			if (nums[i] != flag) {
//				i++;
//				j = i;
//			}
//			else {
//				if (nums[j] == flag) {
//					j++;
//				}
//				else {
//					int tmp = nums[i];
//					nums[i] = nums[j];
//					nums[j] = tmp;
//					i++;
//					j++;
//				}
//			}
//		}
//		for (int i = 0; i < len; i++) {
//			cout << nums[i] << " ";
//		}
//		cout << res;
//		return res;
//	}
//};
//
//int main() {
//	Solution s;
//	vector<int> nums = { 0,1 ,1,1,1,1,2,3,3,3 };
//	s.removeDuplicates(nums);
//	system("pause");
//	return 0;
//}



/****************************************第七十九题？？？？？？？？？？？？？？*********************************************/
//#include<vector>;
//class Solution {
//public:
//	bool exist(vector<vector<char>>& board, string word) {
//		int m = board.size();
//		int n = board[0].size();
//		int len = word.length();
//		int res = 0;
//		if (len > m*n)
//			return false;
//		vector<vector<int>> flag( m,vector<int>(n,0) );
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				if (board[i][j] == word[0]) {
//					board[i][j] = ' ';
//					findcharactor(board, word, 1, i, j, res);
//					//cout << res << "   ";
//					if (res==1) {
//						return true;
//					}
//					board[i][j] = word[0];
//				}
//			}
//		}
//		return false;
//	}
//
//	void findcharactor(vector<vector<char>>& board, string word, int ind, int xind, int yind, int &res) {
//		int m = board.size();
//		int n = board[0].size();
//		//for (int i = 0; i < m; i++) {
//		//	for (int j = 0; j < n; j++) {
//		//		cout << board[i][j] << "  ";
//		//	}
//		//	cout << endl;
//		//}
//		//cout << endl;
//		char target = word[ind];
//		if (ind > word.size() - 1) {
//			res = 1;
//			return;
//		}
//		if (ind == word.size()-1) {
//			if (xind>0 && board[xind - 1][yind] == target) {
//				res = 1;
//				return;
//			}
//			else if (xind<m-1 && board[xind + 1][yind] == target) {
//				res = 1;
//				return;
//			}
//			else if (yind>0 && board[xind][yind - 1] == target) {
//				res = 1;
//				return;
//			}
//			else if (yind<n-1 && board[xind][yind + 1] == target) {
//				res = 1;
//				return;
//			}
//			return;
//		}
//		else {	
//			int flag = 0;
//			if (xind>0 && board[xind - 1][yind] == target) {
//				board[xind - 1][yind] = ' ';
//				findcharactor(board, word, ind + 1, xind - 1, yind, res);
//				board[xind - 1][yind] = target;
//				flag = 1;
//			}
//			if (xind<m-1 && board[xind + 1][yind] == target) {
//				board[xind + 1][yind] = ' ';
//				findcharactor(board, word, ind + 1, xind + 1, yind, res);
//				board[xind + 1][yind] = target;
//				flag = 1;
//			}
//			if (yind>0 && board[xind][yind - 1] == target) {
//				board[xind][yind - 1] = ' ';
//				findcharactor(board, word, ind + 1, xind, yind - 1, res);
//				board[xind][yind - 1] = target;
//				flag = 1;
//			}
//			if (yind<n-1 && board[xind][yind + 1] == target) {
//				board[xind][yind + 1] = ' ';
//				findcharactor(board, word, ind + 1, xind, yind + 1, res);
//				board[xind][yind + 1] = target;
//				flag = 1;
//			}
//			if(flag==0)
//				return;
//		}
//	}
//};
//
//int main() {
//	Solution s;
//	vector<vector<char>> b = {
//		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//	    {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
//		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//	    {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//	    {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//	    {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//	    {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//	    {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//	    {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//	    {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//	    {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//	    {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 	    
//	    {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//	    {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//	    {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//		{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//	    {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//	    {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'}, 
//	    {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'b'}
//	};
//	string w = "baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
//	s.exist(b, w);
//	system("pause");
//	return 0;
//}



/****************************************第七十八题*********************************************/
//#include<vector>;
//class Solution {
//public:
//	vector<vector<int>> subsets(vector<int>& nums) {
//		int len = nums.size();
//		vector<vector<int>> res;
//		res.push_back(vector<int>{});
//		vector<int> max;
//		for (int i = 0; i < len; i++) {
//			res.push_back(vector<int>{nums[i]});
//			max.push_back(nums[i]);
//		}
//		if (len > 1) {
//			res.push_back(max);
//		}
//		vector<int> tmp;
//		vector<int> nextnums = nums;
//		for (int i = 2; i < len; i++) {
//			getcombine(res, tmp, nextnums, i);
//		}
//
//		for (int i = 0; i < res.size(); i++) {
//			for (int j = 0; j < res[i].size(); j++) {
//				cout << res[i][j] << " ";
//			}
//			cout << endl;
//		}
//		return res;
//	}
//
//	void getcombine(vector<vector<int>> &res, vector<int> &tmp, vector<int>& nums, int k) {
//		int len = nums.size();
//		if (k == 1) {
//			for (int j = 0; j < len; j++) {
//				tmp.push_back(nums[j]);
//				res.push_back(tmp);
//				tmp.pop_back();
//			}
//			return;
//		}
//		vector<int> nextnums = nums;
//		for (int j = len; j >= k; j--) {
//			tmp.push_back(nums[j-1]);
//			nextnums.pop_back();
//			getcombine(res, tmp, nextnums, k - 1);
//			tmp.pop_back();
//		}
//	}
//};
//
//int main() {
//	Solution s;
//	vector<int> nums{ 1,2,0,4};
//	s.subsets(nums);
//	system("pause");
//	return 0;
//}



/****************************************第七十七题*********************************************/
//#include<vector>;
//class Solution {
//public:
//	vector<vector<int>> combine(int n, int k) {
//		vector<vector<int>> res;
//		vector<int> tmp;
//		if (k == 0 || n == 0)
//			return res;
//		getcombine(res, tmp, k, n);
//		//for (int i = 0; i < res.size(); i++) {
//		//	for (int j = 0; j < res[i].size(); j++) {
//		//		cout << res[i][j] << " ";
//		//	}
//		//	cout << endl;
//		//}
//		return res;
//	}
//
//	void getcombine(vector<vector<int>> &res, vector<int> &tmp, int k, int n) {
//		if (k == 1) {
//			for (int j = 1; j <= n; j++) {
//				tmp.push_back(j);
//				res.push_back(tmp);
//				tmp.pop_back();
//			}
//			return;
//		}
//		for (int j = n; j >= k; j--) {
//			tmp.push_back(j);
//			getcombine(res, tmp, k - 1, j - 1);
//			tmp.pop_back();
//		}
//	}
//};
//
//int main() {
//	Solution s;
//	int n = 4;
//	int k = 2;
//	s.combine(5, 1);
//	system("pause");
//	return 0;
//}



/****************************************第七十五题*********************************************/
//#include<vector>;
//class Solution {
//public:
//	void sortColors(vector<int>& nums) {
//		int len = nums.size();
//		int i = 0;
//		int j = len - 1;
//		while (i < j) {
//			if (nums[i] == 0)
//				i++;
//			else if (nums[j] == 2)
//				j--;
//			else if (nums[j] == 0) {
//				nums[j] = nums[i];
//				nums[i] = 0;
//				i++;
//			}
//			else if (nums[i] == 2) {
//				nums[i] = nums[j];
//				nums[j] = 2;
//				j--;
//			}
//			else {
//				int t = i;
//				while (t < j) {
//					if (nums[t] == 0) {
//						nums[t] = 1;
//						nums[i] = 0;
//						i++;
//						break;
//					}
//					else if (nums[t] == 2) {
//						nums[t] = 1;
//						nums[j] = 2;
//						j--;
//						break;
//					}
//					else t++;
//				}
//				if (t == j)
//					break;
//			}
//		}
//		for (i = 0; i < len; i++) {
//			cout << nums[i];
//		}
//	}
//};
//
//int main() {
//	Solution s;
//	vector<int> nums = { 1,2,2,2,2,0,0,0,1,1};
//	s.sortColors(nums);
//	system("pause");
//	return 0;
//}



/****************************************第七十四题*********************************************/
//#include<vector>;
//class Solution {
//public:
//	bool searchMatrix(vector<vector<int>>& matrix, int target) {
//		int m = matrix.size();
//		if (m == 0)
//			return false;
//		int n = matrix[0].size();
//		if (n == 0)
//			return false;
//		if (matrix[0][0] > target || matrix[m - 1][n - 1] < target)
//			return false;
//		int i = 0;
//		int j = 0;
//		for (i = 0; i < m; i++) {
//			if (matrix[i][0] == target)
//				return true;
//			if (matrix[i][0] > target)
//				break;
//		}
//		for (j = 0; j < n; j++) {
//			if (matrix[i-1][j] == target)
//				return true;
//			if (matrix[i-1][j] > target)
//				break;
//		}
//		cout << "f";
//		return false;
//	}
//};
//
//int main() {
//	Solution s;
//	vector<vector<int>> b{
//		{1/*,3,5,7*/},
//		//{10,11,15,20},
//		//{23,30,35,40}
//	};
//	s.searchMatrix(b,0);
//	system("pause");
//	return 0;
//}



/****************************************第七十三题*********************************************/
//#include<vector>;
//class Solution {
//public:
//	void setZeroes(vector<vector<int>>& matrix) {
//		//更慢了
//		//int m = matrix.size();
//		//int n = matrix[0].size();
//		//int flag = 1;
//		//vector<int> col(n, 1);
//		//for (int i = 0; i < m; i++) {
//		//	for (int j = 0; j < n; j++) {
//		//		if (matrix[i][j] == 0) {
//		//			flag = 0;
//		//			col[j] = 0;
//		//		}
//		//	}
//		//	if (flag == 0) {
//		//		matrix[i] = vector<int>(n, 0);
//		//		flag = 1;
//		//	}
//		//}
//		//for (int i = 0; i < m; i++) {
//		//	for (int j = 0; j < n; j++) {
//		//		cout << matrix[i][j];
//		//	}
//		//	cout << endl;
//		//}
//		//for (int j = 0; j < n; j++) {
//		//	if (col[j] == 0) {
//		//		for (int i = 0; i < m; i++) {				
//		//			matrix[i][j] = 0;
//		//		}
//		//	}
//		//}
//		
//		//额外空间m+n的做法
//		//int m = matrix.size();
//		//int n = matrix[0].size();
//		//vector<int> row(m, 1);
//		//vector<int> col(n, 1);
//		//for (int i = 0; i < m; i++) {
//		//	for (int j = 0; j < n; j++) {
//		//		if (matrix[i][j] == 0) {
//		//			row[i] = 0;
//		//			col[j] = 0;
//		//		}
//		//	}
//		//}
//		//for (int i = 0; i < m; i++) {
//		//	if (row[i] == 0) {
//		//		matrix[i] = vector<int>(n, 0);
//		//	}
//		//	for (int j = 0; j < n; j++) {
//		//		if (col[j] == 0) {
//		//			matrix[i][j] = 0;
//		//		}
//		//	}
//		//}
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				cout << matrix[i][j];
//			}
//			cout << endl;
//		}
//	}
//};
//
//int main() {
//	Solution s;
//	vector<vector<int>> b{
//		{1,1,2,1},
//		{1,0,1,5},
//		{1,1,1,7},
//		{1,1,8,7},
//	};
//	s.setZeroes(b);
//	system("pause");
//	return 0;
//}



/****************************************第七十一题*********************************************/
//#include<string>;
//#include<vector>;
//#include<stack>;
//class Solution {
//public:
//	string simplifyPath(string path) {
//		stack<string> paths;
//		string tmp;
//		string res = "";
//		int len = path.length();
//		for (int i = 0; i <= len; i++) {
//			if (i == len || path[i] == '/') {
//				if (tmp != "")
//				{
//					if (tmp == "..") {
//						if (!paths.empty()) 
//							paths.pop();
//					}
//					else if (tmp != "." && tmp != "")
//						paths.push(tmp);
//				}
//				tmp = "";
//			}
//			else {
//				tmp += path[i];
//			}
//		}
//		while (!paths.empty()) {
//			if (paths.size() == 0 && paths.top() == "..") {
//				break;
//			}
//			res = paths.top() + res;
//			res = '/' + res;
//			paths.pop();
//		}
//		if (res == "")
//			res = "/";
//		cout << res;
//		return res;
//	}
//};
//
//int main() {
//	string path = "/...";
//	Solution s;
//	s.simplifyPath(path);
//	system("pause");
//	return 0;
//}



/****************************************第六十四题*********************************************/
//#include<vector>;
//#include<algorithm>;
//class Solution {
//public:
//	int minPathSum(vector<vector<int>>& grid) {
//		int m = grid.size();
//		int n = grid[0].size();
//		vector<vector<int>> res(m, vector<int>(n, 0));
//		res[0][0] = grid[0][0];
//		for (int i = 1; i < m; i++) {
//			res[i][0] = res[i - 1][0] + grid[i][0];
//		}
//		for (int i = 1; i < n; i++) {
//			res[0][i] = res[0][i - 1] + grid[0][i];
//		}
//		for (int i = 1; i < m; i++) {
//			for (int j = 1; j < n; j++) {
//				int left = res[i - 1][j] + grid[i][j];
//				int up = res[i][j - 1] + grid[i][j];
//				res[i][j] = min(left, up);
//			}
//		}
//		cout << res[m - 1][n - 1];
//		return res[m - 1][n - 1];
//	}
//};
//
//int main() {
//	Solution s;
//	vector<vector<int>> b{
//		{1,3,1},
//		{1,5,1},
//		{4,2,1}
//	};
//	s.minPathSum(b);
//	system("pause");
//	return 0;
//}



/****************************************第六十三题*********************************************/
//#include<vector>;
//class Solution {
//public:
//	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//		int n = obstacleGrid.size();
//		int m = obstacleGrid[0].size();
//		vector<vector<int>> path(n, vector<int>(m, 0));
//		if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1) {
//			return 0;
//		}
//		path[0][0] = 1;
//		for (int i = 1; i < n; i++) {
//			if (obstacleGrid[i - 1][0] == 1 || path[i - 1][0] == 0) {
//				path[i][0] = 0;
//			}
//			else path[i][0] = 1;
//		}
//		for (int j = 1; j < m; j++) {
//			if (obstacleGrid[0][j - 1] == 1 || path[0][j - 1] == 0) {
//				path[0][j] = 0;
//			}
//			else path[0][j] = 1;
//		}
//		for (int i = 1; i < n; i++) {
//			for (int j = 1; j < m; j++) {
//				if (obstacleGrid[i - 1][j] == 1 && obstacleGrid[i][j - 1] == 1) {
//					path[i][j] = 0;
//				}
//				else if (obstacleGrid[i - 1][j] == 1) {
//					path[i][j] = path[i][j - 1];
//				}
//				else if (obstacleGrid[i][j - 1] == 1) {
//					path[i][j] = path[i - 1][j];
//				}
//				else path[i][j] = path[i - 1][j] + path[i][j - 1];
//			}
//		}
//
//		return path[n - 1][m - 1];
//	}
//};



/****************************************第六十二题*********************************************/
//class Solution {
//public:
//	int res=0;
//	int uniquePaths(int m, int n) {
//		if (m == 1 && n == 1)
//			return 0;
//		int i = 0; 
//		int j = 0;
//		m--;
//		n--;
//		path(i, j, m, n);
//		cout << res;
//		return res;
//	}
//
//	void path(int i, int j, int m, int n) {
//		if (i == m && j == n) {
//			res++;
//			return;
//		}
//		if (i < m) {
//			path(i + 1, j, m, n);
//		}
//		if (j < n) {
//			path(i, j + 1, m, n);
//		}
//	}
//};
//
//int main() {
//	Solution s;
//	s.uniquePaths(23, 12);
//	system("pause");
//	return 0;
//}



/****************************************第六十一题*********************************************/
////Definition for singly-linked list.
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//	ListNode * rotateRight(ListNode* head, int k) {
//		ListNode* res = head;
//		int len = 0;
//		while (res) {
//			len++;
//			res = res->next;
//		}
//		if (len == 0)
//			return head;
//		k = k % len;
//		if (k == 0)
//			return head;
//		int start = len - k;
//		res = head;
//		while (start > 1) {
//			res = res->next;
//			start--;
//		}
//		ListNode* end = res;
//		res = end->next;
//		end->next = NULL;
//		ListNode* mid = res;
//		while (mid->next) {
//			mid = mid->next;
//		}
//		mid->next = head;
//
//		while (res) {
//			cout << res->val << " ";
//			res = res->next;
//		}
//		return res;
//	}
//};
//
//int main() {
//	ListNode l1(1);
//	//ListNode l2(2);
//	//ListNode l3(3);
//	//ListNode l4(4);
//	//ListNode l5(5);
//	//l1.next = &l2;
//	//l2.next = &l3;
//	//l3.next = &l4;
//	//l4.next = &l5;
//
//	Solution s;
//	s.rotateRight(&l1,0);
//	system("pause");
//	return 0;
//}



/****************************************第六十题*********************************************/
//#include<string>;
//class Solution {
//public:
//	string getPermutation(int n, int k) {
//		k--;
//		//阶乘数
//		int factorial[8] = { 1,2,6,24,120,720,5040,40320};
//		//中介数
//		int num[9] = { 0,-1,-1,-1,-1,-1,-1,-1,-1 };
//		string res;
//		//计算中介数
//		for (int i = n-2; i >=0; i--) {
//			num[i+1] = k / factorial[i];
//			k = k % factorial[i];
//		}
//
//		for (int i = n - 1; i >= 0; i--) {
//			int compared[9] = { -1,-1,-1,-1,-1,-1,-1,-1,-1 };
//			if (num[i] != -1) {
//				int tmp = num[i] + 1;
//				cout << tmp << "   ";
//				for (int j = 0; j < n - i - 1; j++) {
//					if (tmp >= (int)res[j] - '0'&&compared[j]==-1) {
//						tmp++;
//						compared[j] = 1;
//						j = -1;
//					}
//				}
//				res += to_string(tmp);
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
//	s.getPermutation(4, 8);
//	system("pause");
//	return 0;
//}



/****************************************第五十九题*********************************************/
//#include<vector>;
//class Solution {
//public:
//	vector<vector<int>> generateMatrix(int n) {
//		vector<vector<int>> res(n, vector<int>(n, 0));
//		int nn = (int)ceil((float)n / (float)2);
//		int num = 1;
//		for (int i = 0; i < nn; i++) {
//			//第一行
//			for (int j = i; j < n - i - 1; j++) {
//				res[i][j] = num;
//				num++;
//			}
//			//最后一列
//			for (int j = i; j < n - i; j++) {
//				res[j][n - 1 - i]=num;
//				num++;
//			}
//			//不是最后一循环且中间只有一个的情况
//			if (!(i == nn - 1 && n % 2 == 1)) {
//				num--;
//				//最后一行
//				for (int j = i; j < n - i - 1; j++) {
//					res[n - 1 - i][n - 1 - j] = num;
//					num++;
//				}
//				//第一列
//				for (int j = i; j < n -1 -i; j++) {
//					res[n - 1 - j][i]=num;
//					num++;
//				}
//			}
//		}
//
//		for (int j = 0; j < n; j++) {
//			for (int k = 0; k < n; k++) {
//				cout << res[j][k] << " ";
//			}
//			cout << endl;
//		}
//		return res;
//	}
//};
//
//int main() {
//	Solution s;
//	s.generateMatrix(5);
//	system("pause");
//	return 0;
//}



/****************************************第五十六题*********************************************/
//#include<vector>;
//#include<algorithm>;
////Definition for an interval.
//struct Interval {
//    int start;
//    int end;
//    Interval() : start(0), end(0) {}
//    Interval(int s, int e) : start(s), end(e) {}
//};
//bool mysort(Interval &a, Interval &b) {
//	return (a.start < b.start);
//}
//
//class Solution {
//public:
//	vector<Interval> merge(vector<Interval>& intervals) {
//		//solution
//		vector<Interval> res;
//		int len = intervals.size();
//		if (len == 1 || len == 0)
//			return intervals;
//		std::sort(intervals.begin(), intervals.end(), mysort);
//		res.push_back(intervals[0]);
//		for (int i = 1; i < len; i++) {
//			//合并
//			if (intervals[i].start <= res.back().end) {
//				res.back().end = max(res.back().end, intervals[i].end);
//			}
//			else {
//				res.push_back(intervals[i]);
//			}
//		}
//
//		//思路2
//		//int len = intervals.size();
//		//std::sort(intervals.begin(), intervals.end(), mysort);
//		//for (int i = 0; i < len - 1; i++) {
//		//	for (int j = i + 1; j < len; j++) {
//		//		//合并
//		//		if (intervals[j].start <= intervals[i].end) {
//		//			intervals[i].end = max(intervals[i].end, intervals[j].end);
//		//			intervals.erase(intervals.begin() + j);
//		//			len--;
//		//			j--;
//		//		}
//		//	}
//		//}
//
//		//思路1
//		//int len = intervals.size();
//		//for (int i = 0; i < len-1; i++) {
//		//	for (int j = i+1; j < len; j++) {
//		//		//合并
//		//		if ((intervals[i].end >= intervals[j].start&&intervals[i].end <= intervals[j].end) || (intervals[j].end >= intervals[i].start&&intervals[j].end <= intervals[i].end)) {
//		//			intervals[i].start = min(intervals[i].start, intervals[j].start);
//		//			intervals[i].end = max(intervals[i].end, intervals[j].end);
//		//			intervals.erase(intervals.begin() + j);
//		//			len--;
//		//			i--;
//		//			break;
//		//		}
//		//	}
//		//}
//		for (int i = 0; i < res.size(); i++) {
//			cout << res[i].start << " " << res[i].end << endl;
//		}
//		return intervals;
//	}
//
//};
//
//int main() {
//	Solution s;
//	vector<Interval> b{
//		{1,3},
//		{2,6},
//		{ 8,10 },
//		{15,18}
//	};
//	s.merge(b);
//	system("pause");
//	return 0;
//}



/****************************************第五十五题*********************************************/
//#include<vector>;
//class Solution {
//public:
//	bool canJump(vector<int>& nums) {
//		int len = nums.size();
//		int i = 0;
//		int maxind = 0;
//		bool res;
//		for (i = 0; i < len; i++) {
//			if (maxind < i)
//				return false;
//			else {
//				if (i + nums[i] > maxind)
//					maxind = i + nums[i];
//			}
//		}
//		if (i >=len-1) {
//			cout << "111";
//			return true;
//		}
//	}
//};
//
//int main() {
//	Solution s;
//	int n[7] = { 2,0,1,1,4,0,0 };
//	vector<int> nums(n, n +5);
//	s.canJump(nums);
//	system("pause");
//	return 0;
//}



/****************************************第五十四题*********************************************/
//#include<vector>;
//#include<algorithm>;
//class Solution {
//public:
//	vector<int> spiralOrder(vector<vector<int>>& matrix) {
//		vector<int> res;
//		int m = matrix.size();
//		if (m == 0)
//			return res;
//		//if (m == 1)
//		//	return matrix[0];
//		int n = matrix[0].size();
//		int mm = (int)ceil((float)m / (float)2);
//		int nn = (int)ceil((float)n / (float)2);
//		int ll = min(mm, nn);
//		int l = max(m, n);
//		int last = 0;
//		for (int i = 0; i < ll; i++) {
//			//第一行
//			for (int j = i; j < l - i; j++) {
//				if (j < n - i) {
//					res.push_back(matrix[i][j]);
//				}
//			}
//			res.pop_back();
//			//最后一列
//			for (int j = i; j < l - i; j++) {
//				if (j < m - i) {
//					res.push_back(matrix[j][n - 1 - i]);
//				}
//			}
//			//最后一循环中间只有一行或者一列时，不计算最后一行和第一列
//			bool hang = !(i == ll - 1 && m % 2 == 1 && mm == ll);
//			bool lie = !(i == ll - 1 && n % 2 == 1 && ll == nn);
//			if (hang &&lie) {
//				res.pop_back();
//				//最后一行
//				for (int j = i; j < l - i; j++) {
//					if (j < n - i) {
//						res.push_back(matrix[m - 1 - i][n - 1 - j]);
//					}
//				}
//				res.pop_back();
//				//第一列
//				for (int j = i; j < l - i; j++) {
//					if (j < m - i) {
//						res.push_back(matrix[m - 1 - j][i]);
//					}
//				}
//				res.pop_back();
//			}
//		}
//
//
//		//思路1
//		//vector<int> res;
//		//int m = matrix.size();
//		//if (m == 0)
//		//	return res;
//		////if (m == 1)
//		////	return matrix[0];
//		//int n = matrix[0].size();
//		//int mm = (int)ceil((float)m / (float)2);
//		//int nn = (int)ceil((float)n / (float)2);
//		//int ll = min(mm, nn);
//		//int l = max(m, n);
//		//int last = 0;
//		//for (int i = 0; i < ll; i++) {
//		//	vector<int> res1;
//		//	vector<int> res2;
//		//	vector<int> res3;
//		//	vector<int> res4;
//		//	for (int j = i; j < l - i; j++) {
//		//		//第一行
//		//		if (j < n - i) {
//		//			res1.push_back(matrix[i][j]);
//		//		}
//		//		//最后一列
//		//		if (j < m - i) {
//		//			res2.push_back(matrix[j][n - 1 - i]);
//		//		}
//		//		//最后一循环中间只有一行或者一列时，不计算最后一行和第一列
//		//		bool hang = !(i == ll - 1 && m % 2 == 1 && mm == ll);
//		//		bool lie = !(i == ll - 1 && n % 2 == 1 && ll == nn );
//		//		cout << "00000"<<hang << " " << lie << endl;
//		//		if (hang &&lie) {
//		//			//最后一行
//		//			if (j < n - i) {
//		//				res3.push_back(matrix[m - 1 - i][n - 1 - j]);
//		//			}
//		//			//第一列
//		//			if (j < m - i) {
//		//				res4.push_back(matrix[m - 1 - j][i]);
//		//			}
//		//		}
//		//	}
//
//		//	for (int j = 0; j < res1.size(); j++) {
//		//		res.push_back(res1[j]);
//		//	}
//		//	last = res.back();
//		//	res.pop_back();
//		//	for (int j = 0; j < res2.size(); j++) {
//		//		res.push_back(res2[j]);
//		//	}
//		//	if (res2.size() != 0) {
//		//		last = res.back();
//		//		res.pop_back();
//		//	}
//		//	for (int j = 0; j < res3.size(); j++) {
//		//		res.push_back(res3[j]);
//		//	}
//		//	if (res3.size() != 0) {
//		//		last = res.back();
//		//		res.pop_back();
//		//	}
//		//	for (int j = 0; j < res4.size(); j++) {
//		//		res.push_back(res4[j]);
//		//	}
//		//	if (res4.size() != 0) {
//		//		last = NULL;
//		//		res.pop_back();
//		//	}
//		//}
//		//if (last) {
//		//	res.push_back(last);
//		//}
//
//		for (int i = 0; i < res.size(); i++) {
//			cout << res[i] << " ";
//		}
//		return res;
//	}
//};
//
//int main() {
//	Solution s;
//	vector<vector<int>> b{
//		{1,5,6},
//		{2,4,7},
//		{15,3,8},
//		//{19,2,9 }
//	};
//	s.spiralOrder(b);
//	system("pause");
//	return 0;
//}



/****************************************第五十题*********************************************/
//class Solution {
//public:
//	double myPow(double x, int n) {
//		if (n == 1)
//			return x;
//		if (n == -1)
//			return 1/x;
//		if (n == 0)
//			return 1;
//
//		long double res;
//		if (n > 0) {
//			res = x * x;
//			double last = x;
//			int lasti = 1;
//			int i = 2;
//			while (i < n) {
//				if (i <= n / 2) {
//					last = res;
//					lasti = i;
//					res *= res;
//					i *= 2;
//				}
//				else if (i + lasti <= n) {
//					res *= last;
//					i += lasti;
//				}
//				else {
//					res *= x;
//					i++;
//				}
//				cout << res << " ";
//			}
//		}
//		else {
//			res = 1 / (x * x);
//			double last = 1 / x;
//			int lasti = -1;
//			int i = -2;
//			while (i > n) {
//				if (i >= n / 2) {
//					last = res;
//					lasti = i;
//					res *= res;
//					i *= 2;
//				}
//				else if (i + lasti >= n) {
//					res *= last;
//					i += lasti;
//				}
//				else {
//					res /= x;
//					i--;
//				}
//			}
//		}		
//		cout << res;
//		return res;
//	}
//};
//
//int main() {
//	double x = 0.01;
//	int n = 21474;
//	Solution s;
//	s.myPow(x, n);
//	system("pause");
//	return 0;
//}



/****************************************第四十九题*********************************************/
//#include<vector>;
//#include<string>;
//#include<algorithm>;
//#include<map>;
//class Solution {
//public:
//	vector<vector<string>> groupAnagrams(vector<string>& strs) {
//		//glc
//		map<string, vector<string> > dic;
//		for (int i = 0; i< strs.size(); ++i) {
//			string tmp = strs[i];
//			sort(tmp.begin(), tmp.end());
//			if (dic.find(tmp) != dic.end()) {
//				dic[tmp].push_back(strs[i]);
//			}
//			else {
//				vector<string> t = { strs[i] };
//				dic[tmp] = t;
//			}
//		}
//		vector<vector<string> > res;
//		for (auto i : dic) {
//			res.push_back(i.second);
//		}
//		return res;
//
//		//排序思路
//		int len = strs.size();
//		vector<vector<string>> res{ {strs[0]} };
//		vector<vector<int>> resind{ { 0 } };
//		vector<string> strssort(len);
//		for (int i = 0; i < len; i++) {
//			strssort[i] = strs[i];
//			sort(strssort[i].begin(), strssort[i].end());
//			int reslen = res.size();
//			if (i == 0)
//				continue;
//			int j;
//			for (j = 0; j < reslen; j++) {
//				int ind = resind[j][0];
//				if (strssort[i] == strssort[ind]) {
//					resind[j].push_back(i);
//					res[j].push_back(strs[i]);
//					break;
//				}
//			}
//			if (j == reslen) {
//				resind.push_back(vector<int>{i});
//				res.push_back(vector<string>{strs[i]});
//			}
//		}
//
//		//计数思路
//		//int len = strs.size();
//		//vector<vector<string>> res{ {strs[0]} };
//		//vector<vector<int>> resind{ {0} };
//		//vector<vector<int>> counts(len,vector<int>(26,0));
//		//for (int i = 0; i < len; i++) {
//		//	int lens = strs[i].length();
//		//	for (int j = 0; j < lens; j++) {
//		//		int c = strs[i][j] - 'a';
//		//		counts[i][c]++;
//		//	}
//
//		//	if (i == 0)
//		//		continue;
//		//	int reslen = res.size();
//		//	int j;
//		//	for (j = 0; j < reslen; j++) {
//		//		int ind = resind[j][0];
//		//		if (counts[i] == counts[ind]) {
//		//			resind[j].push_back(i);
//		//			res[j].push_back(strs[i]);
//		//			break;
//		//		}
//		//	}
//		//	if (j == reslen) {
//		//		resind.push_back(vector<int>{i});
//		//		res.push_back(vector<string>{strs[i]});
//		//	}
//		//}
//
//		int reslen = res.size();
//		for (int i = 0; i < reslen; i++) {
//			int reslens = res[i].size();
//			for (int j = 0; j < reslens; j++) {
//				cout << res[i][j] << " ";
//			}
//			cout << endl;
//		}
//		return res;
//	}
//};
//
//int main() {
//	Solution s;
//	string n[7] = { "eat", "tea", "tan", "ate", "nat", "bat" };
//	vector<string> nums(n, n + 6);
//	s.groupAnagrams(nums);
//	system("pause");
//	return 0;
//}



/****************************************第四十八题*********************************************/
//#include<vector>；
//class Solution {
//public:
//	void rotate(vector<vector<int>>& matrix) {
//		int len = matrix.size();
//		for (int i = 0; i < len; i++) {
//			for (int j = 0; j < len -1 - i; j++) {
//				//cout << i<<" "<<j<<" "<<matrix[len - 1 - j][len - 1 - i] << " " << matrix[i][j] << endl;
//				int tmp = matrix[i][j];
//				matrix[i][j] = matrix[len-1-j][len - 1 - i];
//				matrix[len - 1 - j][len - 1 - i] = tmp;
//			}
//		}
//		for (int i = 0; i < len / 2; i++) {
//			vector<int> tmp= matrix[i];
//			matrix[i] = matrix[len - 1 - i];
//			matrix[len - 1 - i] = tmp;
//		}
//
//		for (int i = 0; i < len; i++) {
//			for (int j = 0; j < len; j++) {
//				cout << matrix[i][j] << " ";
//			}
//			cout << endl;
//		}
//		return;
//	}
//};
//
//int main() {
//	Solution s;
//	vector<vector<int>> b{
//		{1,2,3,4},
//		{4,5,6,7},
//		{7,8,9,10},
//		{8,9,10,11}
//	};
//	s.rotate(b);
//	system("pause");
//	return 0;
//}



/****************************************第四十七题*********************************************/
//#include<vector>;
//#include<algorithm>;
//class Solution {
//public:
//	vector<vector<int>> permuteUnique(vector<int>& nums) {
//		vector<int> tmp = nums;
//		vector<vector<int>> res;
//		int len = nums.size();
//		sort(nums.begin(), nums.end());
//		getpermute( 0, len, tmp, res);
//
//		for (int i = 0; i < res.size(); i++) {
//			for (int j = 0; j < res[i].size(); j++) {
//				cout << res[i][j] << " ";
//			}
//			cout << endl;
//		}
//		return res;
//	}
//
//	void getpermute(int ind, int len, vector<int>& tmp, vector<vector<int>>& res) {
//		if (ind >= len - 1) {
//			res.push_back(tmp);
//			return;
//		}
//
//		for (int i = ind; i < len; i++) {
//			if (i>ind && i < len - 1 && tmp[i] == tmp[i + 1]) {
//				continue;
//			}
//			if (i==ind||tmp[i] != tmp[ind]) {
//				swap(tmp[ind], tmp[i]);
//				getpermute(ind + 1, len, tmp, res);
//				swap(tmp[ind], tmp[i]);
//			}
//		}
//	}
//};
//
//int main() {
//	Solution s;
//	int n[5] = { -1,2,-1,2 ,-1};
//	vector<int> nums(n, n + 3);
//	s.permuteUnique(nums);
//	system("pause");
//	return 0;
//}



/****************************************第四十六题*********************************************/
//#include<vector>;
//class Solution {
//public:
//	vector<vector<int>> permute(vector<int>& nums) {
//		vector<int> tmp = nums;
//		vector<vector<int>> res;
//		int len = nums.size();
//		getpermute( 0, len, tmp, res);
//
//		for (int i = 0; i < res.size(); i++) {
//			for (int j = 0; j < res[i].size(); j++) {
//				cout << res[i][j] << " ";
//			}
//			cout << endl;
//		}
//		return res;
//	}
//
//	void getpermute(int ind, int len, vector<int>& tmp, vector<vector<int>>& res) {
//		//改进
//		if (ind >= len - 1) {
//			res.push_back(tmp);
//			return;
//		}
//		vector<int> thistmp = tmp;
//		for (int i = ind ; i < len; i++) {
//			vector<int> now = thistmp;
//			int t = now[ind];
//			now[ind] = now[i];
//			now[i] = t;
//			getpermute(ind + 1, len, now, res);
//		}
//		
//		//我的
//		//if (ind < len-2) {
//		//	getpermute(ind + 1, len, tmp, res);
//		//}
//		//else if (ind < len)
//		//	res.push_back(tmp);
//		//vector<int> thistmp = tmp;
//		//for (int i = ind+1; i < len; i++) {
//		//	vector<int> now = thistmp;
//		//	int t = now[ind];
//		//	now[ind] = now[i];
//		//	now[i] = t;
//		//	getpermute(ind + 1, len, now, res);
//		//}
//	}
//};
//
//int main() {
//	Solution s;
//	int n[7] = { 1,2,3,4,2,1,5 };
//	vector<int> nums(n, n + 4);
//	s.permute(nums);
//	system("pause");
//	return 0;
//}



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