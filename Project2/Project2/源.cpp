#include <iostream>;
using namespace std;



/****************************************�ھ�ʮ����*********************************************/
//#include<vector>;
//#include<stack>;
//#include<algorithm>;
////Definition for a binary tree node.
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//class Solution {
//public:
//	bool isValidBST(TreeNode* root) {
//		//˼·2:������������
//		bool flag = true;
//		vector<int> res;
//		stack<TreeNode*> tree;
//		TreeNode* tmp = root;
//		while (tmp || !tree.empty()) {
//			if (tmp) {
//				tree.push(tmp);
//				tmp = tmp->left;
//			}
//			else {
//				tmp = tree.top();
//				tree.pop();
//				res.push_back(tmp->val);
//				tmp = tmp->right;
//			}
//		}
//		for (int i = 1; i < res.size(); i++) {
//			if (res[i] <= res[i - 1]) {
//				return false;
//			}
//		}
//		return flag;
//		//˼·1:�������
//		//if (!root) {
//		//	return true;
//		//}
//		//bool flag = true;
//		//int minn = NULL;
//		//int maxx = NULL;
//		////cout << min(maxx, 5)<<" "<<min(maxx, -1)<<" "<<max(maxx, 5)<<" "<<max(maxx, -5) << endl;//֤��null�ڼ���ʱ�ǵ���0�������
//		//validBST(root,maxx, minn, &flag);
//		//return flag;
//	}
//
//	//void validBST(TreeNode* root,int maxx,int minn,bool* flag) {
//	//	if (root->left) {
//	//		if (root->left->val >= root->val || (minn!=NULL && root->left->val <= minn)) {
//	//			(*flag) = false;
//	//			return;
//	//		}
//	//		else {
//	//			int nextmax;
//	//			if (maxx == NULL) {
//	//				nextmax = root->val;
//	//			}
//	//			else {
//	//				nextmax = min(maxx, root->val);
//	//			}
//	//			validBST(root->left, nextmax, minn, flag);
//	//		}
//	//	}
//	//	if (root->right) {
//	//		if (root->right->val <= root->val || (maxx!=NULL && root->right->val >= maxx)) {
//	//			(*flag) = false;
//	//			return;
//	//		}
//	//		else {
//	//			int nextmin;
//	//			if (minn == NULL) {
//	//				nextmin = root->val;
//	//			}
//	//			else nextmin = max(minn, root->val);
//	//			validBST(root->right, maxx, nextmin, flag);
//	//		}
//	//	}
//	//}
//};
//
//int main() {
//	TreeNode t0(0);
//	TreeNode t1(1);
//	TreeNode t2(2);
//	TreeNode t3(3);
//	TreeNode t4(4);
//	TreeNode t5(5);
//	TreeNode t6(6);
//	TreeNode t7(3);
//	t3.left = &t1;
//	t3.right = &t5;
//	t1.left = &t0;
//	t1.right = &t2;
//	t5.left = &t4;
//	t5.right = &t6;
//	t4.left = &t7;
//	Solution s;
//	s.isValidBST(&t3);
//	system("pause");
//	return 0;
//}



/****************************************�ھ�ʮ����*********************************************/
//#include<vector>;
//class Solution {
//public:
//	int numTrees(int n) {
//		vector<int> res;
//		if (n == 0 || n == 1) {
//			return 1;
//		}
//		if (n == 2) {
//			return 2;
//		}
//		res.push_back(1);
//		res.push_back(1);
//		res.push_back(2);
//		for (int i = 3; i <= n; i++) {
//			int tmp = 0;
//			int j = 1;
//			for (j = 1; j <= i / 2; j++) {
//				tmp += res[j-1] * res[i - j];
//			}
//			tmp *= 2;
//			if (i%2==1) {
//				tmp += res[j - 1] * res[i - j];
//			}
//			cout << tmp << " ";
//			res.push_back(tmp);
//		}
//		return res[n];
//	}
//};
//
//int main() {
//	Solution s;
//	s.numTrees(5);
//	system("pause");
//	return 0;
//}



/****************************************�ھ�ʮ����*********************************************/
//#include<vector>;
////Definition for a binary tree node.
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//class Solution {
//public:
//	vector<TreeNode*> generateTrees(int n) {
//		vector<TreeNode*> res;
//		if (n == 0) {
//			return res;
//		}
//		if (n == 1) {
//			TreeNode tmp(1);
//			res.push_back(&tmp);
//			return res;
//		}
//		if (n == 2) {
//			TreeNode tmp1(1);
//			TreeNode tmp2(2);
//			tmp1.right = &tmp2;
//			res.push_back(&tmp1);
//			TreeNode tmp21(1);
//			TreeNode tmp22(2);
//			tmp22.left = &tmp21;
//			res.push_back(&tmp22);
//			return res;
//		}
//		res = generateTree(1, n);
//
//		cout << res.size()<<endl;
//		for (int i = 0; i < res.size(); i++) {
//			while (res[i]) {
//				cout << (*res[i]).val << " ";
//				res[i] = res[i]->right;
//			}
//			cout << endl;
//		}
//		return res;
//	}
//
//	vector<TreeNode*> generateTree(int start, int end) {
//		vector<TreeNode*> res;
//		if (start == end) {
//			TreeNode* tmp = new TreeNode(start);
//			res.push_back(tmp);
//		}
//		else if (start == end-1) {
//			TreeNode* tmp11 = new TreeNode(start);
//			TreeNode* tmp12 = new TreeNode(end);
//			tmp11->right = tmp12;
//			res.push_back(tmp11);
//			TreeNode* tmp21 = new TreeNode(start);
//			TreeNode* tmp22 = new TreeNode(end);
//			tmp22->left = tmp21;
//			res.push_back(tmp22);
//		}
//		else {
//			for (int i = start; i <= end; i++) {
//				if (i == start) {
//					vector<TreeNode*> allright = generateTree(start + 1, end);
//					int rightlen = allright.size();
//					for (int j = 0; j < rightlen; j++) {
//						TreeNode* tmp = new TreeNode(i);
//						tmp->right = allright[j];
//						res.push_back(tmp);
//					}
//				}
//				else if (i == start + 1) {
//					TreeNode* tmpleft=new TreeNode(start);
//					vector<TreeNode*> allright = generateTree(start + 2, end);
//					int rightlen = allright.size();
//					for (int j = 0; j < rightlen; j++) {
//						TreeNode* tmp = new TreeNode(i);
//						tmp->left = tmpleft;
//						tmp->right = allright[j];
//						res.push_back(tmp);
//					}
//				}
//				else if (i == end - 1) {
//					TreeNode* tmpright=new TreeNode(end);
//					vector<TreeNode*> allleft = generateTree(start, end - 2);
//					int leftlen = allleft.size();
//					for (int j = 0; j < leftlen; j++) {
//						TreeNode* tmp = new TreeNode(i);
//						tmp->right = tmpright;
//						tmp->left = allleft[j];
//						res.push_back(tmp);
//					}
//				}
//				else if (i == end) {
//					vector<TreeNode*> allleft = generateTree(start, end - 1);
//					int leftlen = allleft.size();
//					for (int j = 0; j < leftlen; j++) {
//						TreeNode* tmp = new TreeNode(i);
//						tmp->left = allleft[j];
//						res.push_back(tmp);
//					}
//				}
//				else {
//					vector<TreeNode*> allleft = generateTree(start, i - 1);
//					int leftlen = allleft.size();
//					vector<TreeNode*> allright = generateTree(i + 1, end);
//					int rightlen = allright.size();
//					cout << leftlen << " " << rightlen << endl;
//					for (int j = 0; j < leftlen; j++) {
//						for (int k = 0; k < rightlen; k++) {
//							TreeNode* tmp = new TreeNode(i);
//							tmp->left = allleft[j];
//							tmp->right = allright[k];
//							res.push_back(tmp);
//						}
//					}
//				}
//			}
//		}
//		//for (int i = 0; i < res.size(); i++)
//		//{
//		//	while (res[i]) {
//		//		cout << (*res[i]).val << " ";
//		//		res[i] = (res[i])->right;
//		//	}
//		//	cout << endl;
//		//}
//		//cout << endl;
//		return res;
//	}
//};
//
//int main() {
//	Solution s;
//	s.generateTrees(5);
//	system("pause");
//	return 0;
//}



/****************************************�ھ�ʮ����*********************************************/
//#include<vector>;
//#include<stack>;
////Definition for a binary tree node.
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//class Solution {
//public:
//	vector<int> inorderTraversal(TreeNode* root) {		
//		//�ݹ�
//		//vector<int> res;
//		//if (root) {
//		//	travel(root, &res);
//		//}
//
//		//��������ջ
//		vector<int> res;
//		stack<TreeNode*> tree;
//		TreeNode* tmp = root;
//		tree.push(root);
//		//ǰ��
//		//while (!tree.empty()) {
//		//	tmp = tree.top();
//		//	tree.pop();
//		//	if (tmp->right) {
//		//		tree.push(tmp->right);
//		//	}
//		//	if (tmp->left) {
//		//		tree.push(tmp->left);
//		//	}
//		//	res.push_back(tmp->val);
//		//}
//
//		//����
//		while (tmp || !tree.empty()) {
//			if (tmp) {
//				tree.push(tmp);
//				tmp = tmp->left;
//			}
//			else {
//				tmp = tree.top();
//				tree.pop();
//				res.push_back(tmp->val);
//				tmp = tmp->right;
//			}
//		}
//
//		//����
//		//TreeNode* pre = nullptr;
//		//while (!tree.empty()) {
//		//	tmp = tree.top();
//		//	if ((!tmp->left && !tmp->right) || (pre && (pre == tmp->right || pre == tmp->left))) {
//		//		res.push_back(tmp->val);
//		//		tree.pop();
//		//		pre = tmp;
//		//	}			
//		//	else {
//		//		if (tmp->right) {
//		//			tree.push(tmp->right);
//		//		}
//		//		if (tmp->left) {
//		//			tree.push(tmp->left);
//		//		}
//		//	}
//		//}
//
//		for (int i = 0; i < res.size(); i++) {
//			cout << res[i] << " ";
//		}
//		return res;
//	}
//
//	//�ݹ�
//	//void travel(TreeNode* root, vector<int>* res) {
//	//	if (root->left) {
//	//		travel(root->left, res);
//	//	}
//	//	res->push_back(root->val);
//	//	if (root->right) {
//	//		travel(root->right, res);
//	//	}
//	//}
//};
//
//int main() {
//	TreeNode root(1);
//	TreeNode r(3);
//	TreeNode rr(6);
//	TreeNode l(2);
//	TreeNode lr(5);
//	TreeNode ll(4);
//	root.right = &r;
//	root.left = &l;
//	r.left = &rr;
//	l.left = &ll;
//	l.right = &lr;
//	Solution s;
//	s.inorderTraversal(&root);
//	system("pause");
//	return 0;
//}



/****************************************�ھ�ʮ����*********************************************/
//#include<vector>;
//#include<string>;
//class Solution {
//public:
//	vector<string> restoreIpAddresses(string s) {
//		int len = s.length();
//		vector<string> res;
//		if (len < 4) {
//			return res;
//		}
//		if (len == 4) {
//			string tmp;
//			tmp = tmp + s[0] + '.' + s[1] + '.' + s[2] + '.' + s[3];
//			res.push_back(tmp);
//			return res;
//		}
//		if (len == 12) {
//			string tmp;
//			for (int i = 0; i < 12; i+=3) {
//				int t = (s[i] - '0') * 100 + (s[i + 1] - '0') * 10 + s[i + 2] - '0';
//				if (t > 255 || t < 1) {
//					return res;
//				}
//				else {
//					tmp = tmp + s[i] + s[i + 1] + s[i + 2];
//					if (i < 9) {
//						tmp += ".";
//					}
//				}
//			}
//			res.push_back(tmp);
//		}
//		else {
//			string tmp = "";
//			getip(&res,s, tmp, 0, 0, len);
//		}
//		for(int i = 0; i < res.size(); i++) {
//			for (int j = 0; j < res[i].size(); j++) {
//				cout << res[i][j];
//			}
//			cout << endl;
//		}
//		return res;
//	}
//	void getip(vector<string>* res,string s,string tmp,int ind,int index, int len) {
//		if (index == len && ind == 4) {
//			tmp = tmp.substr(0, tmp.size() - 1);
//			(*res).push_back(tmp);
//			return;
//		}
//		if (ind > 3) {
//			return;
//		}
//		int left = len - index;
//		if (left > 3 * (4 - ind) || left < 1 * (4 - ind)) {
//			return;
//		}
//		string t = tmp;
//		tmp = tmp + s[index] + ".";
//		getip(res, s, tmp, ind + 1, index + 1, len);
//		tmp = t;
//
//		if (index < len - 1 && s[index] - '0'>0) {
//			tmp = tmp + s[index] + s[index + 1] + ".";
//			getip(res, s, tmp, ind + 1, index + 2, len);
//			tmp = t;
//		}
//		if (index < len - 2 && s[index] - '0'>0 && ((s[index] - '0') * 100 + (s[index + 1] - '0') * 10 + s[index + 2] - '0') < 256) {
//			tmp = tmp + s[index] + s[index + 1] + s[index + 2] + ".";
//			getip(res, s, tmp, ind + 1, index + 3, len);
//			tmp = t;
//		}
//	}
//};
//
//int main() {
//	string ss = "0100";
//	Solution s;
//	s.restoreIpAddresses(ss);
//	system("pause");
//	return 0;
//}



/****************************************�ھ�ʮ����*********************************************/
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
//		ListNode* reverse = NULL;
//		ListNode* reversefirst = head;
//		ListNode* before = NULL;
//		ListNode* later = NULL;
//		int ind = 1;
//		while (head&&ind <= n+1) {
//			if (ind == m - 1) {
//				before = head;
//				ind++;
//				head = head->next;
//			}
//			else if (ind >= m && ind <= n) {
//				ListNode* tmp = new ListNode(head->val);
//				if (ind == m) {
//					reversefirst = tmp;
//				}
//				head = head->next;
//				tmp->next = reverse;
//				reverse = tmp;
//				ind++;
//			}
//			else if (ind == n + 1) {
//				later = head;
//
//				break;
//			}
//			else {
//				head = head->next;
//				ind++;
//			}
//		}
//		reversefirst->next = later;
//		if (m==1) {
//			return reverse;
//		}
//		before->next = reverse;
//
//		while (reverse) {
//			cout << reverse->val << " ";
//			reverse = reverse->next;
//		}
//		cout << endl;
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
//	s.reverseBetween(&l1,1,6);
//	system("pause");
//	return 0;
//}



/****************************************�ھ�ʮһ��*********************************************/
//#include<vector>;
//class Solution {
//public:
//	int numDecodings(string s) {
//		int len = s.length();
//		vector<int> res(len+1, 0);
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
//				if (s[i - 1]-'0' > 2||s[i-1]=='0') {
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
//				if ((s[i-1]-'0')*10+s[i]-'0'>26||s[i-1]=='0') {
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
//		for (int i = 0; i < len; i++) {
//			cout << res[i] << " ";
//		}
//		cout << res[len-1];
//		return res[len-1];
//	}
//};
//
//int main() {
//	Solution s;
//	string ss = "1000";
//	s.numDecodings(ss);
//	system("pause");
//	return 0;
//}



/****************************************�ھ�ʮ��*********************************************/
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
//		//i�ǽ���ĳ���
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
//	//res�ǽ����tmp���ݴ�ĵ�ǰ���飬nums��ʣ�µĿ��õ����飬k�ǻ�ʣ��������
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



/****************************************�ڰ�ʮ����*********************************************/
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



/****************************************�ڰ�ʮ����*********************************************/
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
//				//�ƶ�
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



/****************************************�ڰ�ʮ����*********************************************/
//Definition for singly-linked list.
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//	ListNode * deleteDuplicates(ListNode* head) {
//		if (head == NULL || head->next == NULL)
//			return head;
//		ListNode* dif = head;
//		ListNode* last = head;
//		ListNode* nextnode = head->next;
//		while (nextnode) {
//			if (nextnode->val != last->val) {
//				dif = last;
//				last = nextnode;
//				nextnode = nextnode->next;
//			}
//			else {
//				while (nextnode && nextnode->val == last->val) {
//					nextnode = nextnode->next;
//				}
//				if (last == head) {
//					head = nextnode;
//					dif = head;
//					last = head;
//				}
//				else {
//					dif->next = nextnode;
//					last = nextnode;
//				}
//
//				if (nextnode)
//					nextnode = nextnode->next;
//			}
//		}
//		while (head) {
//			cout << head->val << " ";
//			head = head->next;
//		}
//		return head;
//	}
//};
//
//int main() {
//	ListNode l1(3);
//	ListNode l2(3);
//	ListNode l3(3);
//	ListNode l4(4);
//	ListNode l5(4);
//	ListNode l6(5);
//	ListNode l7(5);
//	l1.next = &l2;
//	l2.next = &l3;
//	l3.next = &l4;
//	l4.next = &l5;
//	l5.next = &l6;
//	l6.next = &l7;
//
//	Solution s;
//	s.deleteDuplicates(&l1);
//	system("pause");
//	return 0;	
//}



/****************************************�ڰ�ʮһ��*********************************************/
//#include<vector>;
//class Solution {
//public:
//	bool search(vector<int>& nums, int target) {
//		int len = nums.size();
//		if (len == 0)
//			return false;
//		if (nums[0] == target)
//			return true;
//		if (nums[0] < target) {
//			for (int i = 1; i < len; i++) {
//				if (nums[i] == target) {
//					cout << "1";
//					return true;
//				}
//				else if (nums[i] < nums[0]) {
//					return false;
//				}
//			}
//		}
//		else{
//			for (int i = len - 1; i > 0; i--) {
//				if (nums[i] == target) {
//					cout << "1";
//					return true;
//				}
//				else if (nums[i] > nums[0]) {
//					return false;
//				}
//			}
//		}
//		return false;
//	}
//};
//
//int main() {
//	vector<int> nums = { 2 };
//	Solution s;
//	s.search(nums, 5);
//	system("pause");
//	return 0;
//}



/****************************************�ڰ�ʮ��*********************************************/
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
//		//i���ظ��ģ�j�Ǳ�������
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



/****************************************����ʮ����*********************************************/
//#include<vector>;
//class Solution {
//public:
//	bool exist(vector<vector<char>>& board, string word) {
//		int m = board.size();
//		int n = board[0].size();
//		int len = word.length();
//		bool res = false;
//		if (len > m*n)
//			return false;
//		vector<vector<int>> flag(m, vector<int>(n, 0));
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				if (board[i][j] == word[0]) {
//					board[i][j] = ' ';
//					if (findcharactor(board, word, 1, i, j, res) == true) {
//						cout << " ";
//						return true;
//					}
//					board[i][j] = word[0];
//				}
//			}
//		}
//		return false;
//	}
//
//	bool findcharactor(vector<vector<char>>& board, string word, int ind, int xind, int yind, bool &res) {
//		int m = board.size();
//		int n = board[0].size();
//		char target = word[ind];
//		if (ind > word.size() - 1) {
//			return true;
//		}
//		int flag = 0;
//		if (xind>0 && board[xind - 1][yind] == target) {
//			board[xind - 1][yind] = ' ';
//			if (findcharactor(board, word, ind + 1, xind - 1, yind, res) == true)
//				return true;
//			board[xind - 1][yind] = target;
//		}
//		if (xind<m - 1 && board[xind + 1][yind] == target) {
//			board[xind + 1][yind] = ' ';
//			if (findcharactor(board, word, ind + 1, xind + 1, yind, res) == true)
//				return true;
//			board[xind + 1][yind] = target;
//			flag = 1;
//		}
//		if (yind>0 && board[xind][yind - 1] == target) {
//			board[xind][yind - 1] = ' ';
//			if (findcharactor(board, word, ind + 1, xind, yind - 1, res) == true)
//				return true;
//			board[xind][yind - 1] = target;
//			flag = 1;
//		}
//		if (yind<n - 1 && board[xind][yind + 1] == target) {
//			board[xind][yind + 1] = ' ';
//			if (findcharactor(board, word, ind + 1, xind, yind + 1, res) == true)
//				return true;
//			board[xind][yind + 1] = target;
//			flag = 1;
//		}
//		return false;
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



/****************************************����ʮ����*********************************************/
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



/****************************************����ʮ����*********************************************/
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



/****************************************����ʮ����*********************************************/
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



/****************************************����ʮ����*********************************************/
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



/****************************************����ʮ����*********************************************/
//#include<vector>;
//class Solution {
//public:
//	void setZeroes(vector<vector<int>>& matrix) {
//		//������
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
//		//����ռ�m+n������
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



/****************************************����ʮһ��*********************************************/
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



/****************************************����ʮ����*********************************************/
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



/****************************************����ʮ����*********************************************/
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



/****************************************����ʮ����*********************************************/
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



/****************************************����ʮһ��*********************************************/
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



/****************************************����ʮ��*********************************************/
//#include<string>;
//class Solution {
//public:
//	string getPermutation(int n, int k) {
//		k--;
//		//�׳���
//		int factorial[8] = { 1,2,6,24,120,720,5040,40320};
//		//�н���
//		int num[9] = { 0,-1,-1,-1,-1,-1,-1,-1,-1 };
//		string res;
//		//�����н���
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



/****************************************����ʮ����*********************************************/
//#include<vector>;
//class Solution {
//public:
//	vector<vector<int>> generateMatrix(int n) {
//		vector<vector<int>> res(n, vector<int>(n, 0));
//		int nn = (int)ceil((float)n / (float)2);
//		int num = 1;
//		for (int i = 0; i < nn; i++) {
//			//��һ��
//			for (int j = i; j < n - i - 1; j++) {
//				res[i][j] = num;
//				num++;
//			}
//			//���һ��
//			for (int j = i; j < n - i; j++) {
//				res[j][n - 1 - i]=num;
//				num++;
//			}
//			//�������һѭ�����м�ֻ��һ�������
//			if (!(i == nn - 1 && n % 2 == 1)) {
//				num--;
//				//���һ��
//				for (int j = i; j < n - i - 1; j++) {
//					res[n - 1 - i][n - 1 - j] = num;
//					num++;
//				}
//				//��һ��
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



/****************************************����ʮ����*********************************************/
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
//			//�ϲ�
//			if (intervals[i].start <= res.back().end) {
//				res.back().end = max(res.back().end, intervals[i].end);
//			}
//			else {
//				res.push_back(intervals[i]);
//			}
//		}
//
//		//˼·2
//		//int len = intervals.size();
//		//std::sort(intervals.begin(), intervals.end(), mysort);
//		//for (int i = 0; i < len - 1; i++) {
//		//	for (int j = i + 1; j < len; j++) {
//		//		//�ϲ�
//		//		if (intervals[j].start <= intervals[i].end) {
//		//			intervals[i].end = max(intervals[i].end, intervals[j].end);
//		//			intervals.erase(intervals.begin() + j);
//		//			len--;
//		//			j--;
//		//		}
//		//	}
//		//}
//
//		//˼·1
//		//int len = intervals.size();
//		//for (int i = 0; i < len-1; i++) {
//		//	for (int j = i+1; j < len; j++) {
//		//		//�ϲ�
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



/****************************************����ʮ����*********************************************/
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



/****************************************����ʮ����*********************************************/
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
//			//��һ��
//			for (int j = i; j < l - i; j++) {
//				if (j < n - i) {
//					res.push_back(matrix[i][j]);
//				}
//			}
//			res.pop_back();
//			//���һ��
//			for (int j = i; j < l - i; j++) {
//				if (j < m - i) {
//					res.push_back(matrix[j][n - 1 - i]);
//				}
//			}
//			//���һѭ���м�ֻ��һ�л���һ��ʱ�����������һ�к͵�һ��
//			bool hang = !(i == ll - 1 && m % 2 == 1 && mm == ll);
//			bool lie = !(i == ll - 1 && n % 2 == 1 && ll == nn);
//			if (hang &&lie) {
//				res.pop_back();
//				//���һ��
//				for (int j = i; j < l - i; j++) {
//					if (j < n - i) {
//						res.push_back(matrix[m - 1 - i][n - 1 - j]);
//					}
//				}
//				res.pop_back();
//				//��һ��
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
//		//˼·1
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
//		//		//��һ��
//		//		if (j < n - i) {
//		//			res1.push_back(matrix[i][j]);
//		//		}
//		//		//���һ��
//		//		if (j < m - i) {
//		//			res2.push_back(matrix[j][n - 1 - i]);
//		//		}
//		//		//���һѭ���м�ֻ��һ�л���һ��ʱ�����������һ�к͵�һ��
//		//		bool hang = !(i == ll - 1 && m % 2 == 1 && mm == ll);
//		//		bool lie = !(i == ll - 1 && n % 2 == 1 && ll == nn );
//		//		cout << "00000"<<hang << " " << lie << endl;
//		//		if (hang &&lie) {
//		//			//���һ��
//		//			if (j < n - i) {
//		//				res3.push_back(matrix[m - 1 - i][n - 1 - j]);
//		//			}
//		//			//��һ��
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



/****************************************����ʮ��*********************************************/
//class Solution {
//public:
//	double myPow(double x, int n) {
//		if (n == 0)
//			return 1;
//		if (n == 1)
//			return x;
//		if (n == -1)
//			return 1/x;
//		long double res = 1;
//		long double tmp = myPow(x, n / 2);
//		if (n % 2==0) {
//			res = tmp * tmp;
//		}
//		else {
//			x = n > 0 ? x : 1 / x;
//			res = tmp * tmp*x;
//		}
//
//		cout << res<<" ";
//		return res;
//	}
//};
//
//int main() {
//	double x = 2;
//	int n = 3;
//	Solution s;
//	s.myPow(x, n);
//	system("pause");
//	return 0;
//}



/****************************************����ʮ����*********************************************/
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
//		//����˼·
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
//		//����˼·
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



/****************************************����ʮ����*********************************************/
//#include<vector>��
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



/****************************************����ʮ����*********************************************/
//#include<vector>;
//#include<algorithm>;
//class Solution {
//public:
//	vector<vector<int>> permuteUnique(vector<int>& nums) {
//		vector<vector<int>> res;
//		int len = nums.size();
//		sort(nums.begin(), nums.end());
//		res.push_back(nums);
//		//˼·2
//		int i = len - 1;
//		int j = 0;
//		while (1) {
//			for (i = len - 1; i > 0; i--) {
//				if (nums[i] > nums[i - 1])
//					break;
//			}
//			if (i == 0)
//				break;
//			for (j = len - 1; j >= i; j--) {
//				if (nums[j] > nums[i - 1])
//					break;
//			}
//			swap(nums[i - 1], nums[j]);
//			reverse(nums, i, len - 1);
//			res.push_back(nums);
//		}
//
//		//˼·1
//		//getpermute( 0, len, nums, res);
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
//	//˼·2
//	void reverse(vector<int>& t, int s, int e) {
//		while (s < e) {
//			swap(t[s], t[e]);
//			s++;
//			e--;
//		}
//	}
//
//	//˼·1
//	//�������ڿ��ܻ���ֽ������ٽ�������ͬ�����
//	//void getpermute(int ind, int len, vector<int> tmp, vector<vector<int>>& res) {
//	//	if (ind == len - 1) {
//	//		res.push_back(tmp);
//	//		return;
//	//	}
//	//	for (int i = ind; i < len; i++) {
//	//		//cout << ind<<" "<<i << " " << endl;
//	//		if (i!=ind&&tmp[i] == tmp[ind]) {
//	//			//cout << i << " " << endl;
//	//			continue;
//	//		}				
//	//		swap(tmp[ind], tmp[i]);
//	//		getpermute(ind + 1, len, tmp, res);
//	//		//swap(tmp[ind], tmp[i]);//����һ��ע�͵��Ͷ��ˣ���������Ϊɶ������
//	//	}
//	//}
//};
//
//int main() {
//	Solution s;
//	int n[5] = { -1,2,-1,2 ,-1};
//	vector<int> nums(n, n + 5);
//	s.permuteUnique(nums);
//	system("pause");
//	return 0;
//}



/****************************************����ʮ����*********************************************/
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
//		//�Ľ�
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
//		//�ҵ�
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



/****************************************����ʮ����*********************************************/
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



/****************************************����ʮ��*********************************************/
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



/****************************************����ʮ����*********************************************/
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
//				//��tmp��ÿ������ǰ����϶�Ӧ��count��thisnum,Ȼ��Ӹ�res
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



/****************************************����ʮ����*********************************************/
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
//		//������
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
//		//	//���С��
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



/****************************************����ʮ����*********************************************/
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



/****************************************����ʮ����*********************************************/
//#include<vector>;
//class Solution {
//public:
//	int search(vector<int>& nums, int target) {
//		//solution ����
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
//		//˼·
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



/****************************************����ʮһ��*********************************************/
//#include <vector>;
//class Solution {
//public:
//	void nextPermutation(vector<int>& nums) {
//		int len = nums.size();
//		if (len == 1 || len == 0) {
//			return;
//		}
//		int i = 0;
//		//�ж��ǲ���ȫ������
//		for (i; i < len-1; i++) {
//			if (nums[i] < nums[i + 1])
//				break;
//		}
//		//ȫ������û�и��������
//		if (i == len-1) {
//			for (i = 0; i < len / 2; i++) {
//				int tmp = nums[i];
//				nums[i] = nums[len - i - 1];
//				nums[len - i - 1] = tmp;
//			}
//		}
//		//�ų���һ�����������
//		else {
//			int left = len - 2;
//			int right = len - 1;
//			//���ұ��ҵ���һ�����ұ�����С������
//			while (left >= 0) {
//				if (nums[left] < nums[left+1]) {
//					break;
//				}
//				else left--;
//			}
//			//�ҵ�left�ұ߱��������С��
//			int tmp = right;
//			//���ҵ���һ���������
//			while (right > left) {
//				if (nums[right] > nums[left]) {
//					tmp = right;
//					break;
//				}
//				right--;
//			}
//			//Ȼ��������С��
//			while (right > left) {
//				if (nums[right] > nums[left] && nums[right] < nums[tmp]) {
//					tmp = right;
//				}
//				right--;
//			}
//			right = tmp;
//			cout << left << " " << right;
//			//����������
//			tmp = nums[right];
//			nums[right] = nums[left];
//			nums[left] = tmp;
//
//			//�Ѻ����ȫ������
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



/****************************************�ڶ�ʮ����*********************************************/
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
//		//˼·
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



/****************************************�ڶ�ʮ����*********************************************/
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



/****************************************�ڶ�ʮ����*********************************************/
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



/****************************************��ʮ����*********************************************/
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



/****************************************��ʮ����*********************************************/
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
//		//������
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



/****************************************��ʮ����*********************************************/
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



/****************************************��ʮ����*********************************************/
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
//		//����˼·
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



/****************************************��ʮ����*********************************************/
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
//		//������
//		sort(nums.begin(), nums.end());
//
//		//����
//		//��߸��ģ��ұ�����
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
//		////˼·��̫����		
//		//vector<vector<int>> res;
//		//int len = nums.size();
//		//if (len == 0)
//		//	return res;
//		//if (len < 3)
//		//	return res;
//		////������
//		//sort(nums.begin(), nums.end());
//
//		////����
//		//int left = 0;
//		//int right = len - 1;
//		//int third = 0;
//		//int target = 0;
//		////��߸��ģ��ұ�����
//		//while (left < len&&nums[left] <= 0) {
//		//	while (right > (left+1) && nums[right] >= 0) {
//		//		target = 0 - nums[left] - nums[right];
//		//		//cout << target << " ";
//		//		//������ָ����ұ߼������
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
//		//				//����Ҳ������
//		//				else if (nums[third] < target) {
//		//					break;
//		//				}
//		//				else third--;
//		//			}
//		//		}
//		//		//������ָ�����߼�鸺��
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
//		//				//��С�Ļ�����С
//		//				else if (nums[third] > target) {
//		//					break;
//		//				}
//		//				else third++;
//		//			}
//		//		}
//		//		//�����ƣ�Ȼ��Ե�ǰ����Ƿ����һλ��ͬ
//		//		right--;
//		//		while (right>=0&&nums[right] == nums[right+1]) {
//		//			right--;
//		//		}
//		//	}
//		//	//�����ƣ�Ȼ�����Ƿ����һλ��ͬ
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



/****************************************��ʮ����*********************************************/
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
//		//����˼·
//		//string res = "";
//		//int nums[7] = { 1000,500,100,50,10,5,1 };
//		//char roman[7] = { 'M','D','C','L','X','V','I' };
//		//int pointer = 0;
//		//while (num > 0) {
//		//	//��ǰλ
//		//	int t = num / nums[pointer];
//		//	//��һλ
//		//	int t0 = 0;
//		//	//���û����β
//		//	if (pointer <= 6)
//		//		t0 = num / nums[pointer+1];
//
//		//	//�����ǰλ��4Ҫ����
//		//	if (t == 4) {
//		//		res += roman[pointer];
//		//		res += roman[pointer - 1];
//		//	}
//		//	//�����һλ��9
//		//	else if (t0 == 9) {
//		//		res += roman[pointer + 1];
//		//		res += roman[pointer - 1];
//		//		pointer++;
//		//	}
//		//	//�������ͨ���
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



/****************************************��ʮһ��*********************************************/
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
//		//����˼·
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



/****************************************�ڰ���*********************************************/
//#include<string>;
//class Solution {
//public:
//	int getint(string str) {
//		int res=0;
//		int i = 0;
//		//�������
//		int flag = 1;
//		//������
//		int flagout = 0;
//		//����ո�
//		while (str[i] == ' ') {
//			i++;
//		}
//		//�������
//		if (str[i] == '-') {
//			flag = 0;
//			i++;
//		}
//		else if (str[i] == '+') {
//			i++;
//		}
//
//		//�������֣���������������
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
//		//������
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



/****************************************������*********************************************/
//#include <string>;
//#include <vector>;
//class Solution {
//public:
//	string getz(string s,int numRows) {
//		//solution1�ؼ��������ո�Ͳ���¼��
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
//		//i:string�ĵ�������j:������������k:������tmp:����
//		int i = 0; int j = 0; int k = 0; int tmp = 0;
//		//ÿ��ѭ������һ��
//		while (i < len)
//		{
//			//�����������
//			if (tmp == 0) {
//				z[j]+= s[i];
//				i++;
//			}
//			//����ǲ������У���ȫ���ÿ�Ȼ���޸ĶԵ�һ��
//			else {
//				if (j == (rows - tmp)) {
//					z[rows - tmp]+=s[i];
//					i++;
//				}
//			}
//
//			j++;
//			//����
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
		////��΢��һ��
		////if (numRows == 1) {
		////	return s;
		////}
		////string res;
		////float len = s.length();
		////int rows = numRows - 1;
		////char **z;
		//////����ռ�
		////z = new char *[numRows];
		////int t = (numRows - 1) * ceil(len / (2 * numRows - 2));
		////for (int i = 0; i < numRows; i++) {
		////	z[i] = new char[t]();
		////}

		//////i:string�ĵ�������j:������������k:������tmp:����
		////int i = 0; int j = 0; int k = 0; int tmp = 0;
		//////ÿ��ѭ������һ��
		////while (i < len)
		////{
		////	//�����������
		////	if (tmp == 0) {
		////		z[j][k] = s[i];
		////		i++;
		////	}
		////	//����ǲ������У���ȫ���ÿ�Ȼ���޸ĶԵ�һ��
		////	else {
		////		z[j][k] = 0;
		////		if (j == (rows - tmp)) {
		////			z[j][k] = s[i];
		////			i++;
		////		}
		////	}

		////	j++;
		////	//����
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
		//////�ͷſռ�
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



/****************************************������*********************************************/
//#include <string.h>;
//#include <vector>;
//class Solution {
//public:
//	string longestPalindrome(string s) {
//		string res = "";
//      //
//		//�����ַ���
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
//		//����˼·
//		//for (int i = 0; i < s.length() - res.length(); i++) {
//		//	for (int j = s.length(); j > (i+res.size()); j--) {
//		//		//�ж�s(i,j)�Ƿ����
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



/****************************************������*********************************************/
//#include <string.h>;
//#include <map>;
//#include <algorithm>;
//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) {
//		//���ֳ�˼·
//		int length = 0;
//		map<char,int> pos;
//		//��ʼ��pos
//		char tmp;
//		for (int i = 0; i < s.length(); i++) {
//			tmp = s[i];
//			pos[tmp] = 0;
//		}
//		//�����������һ���ظ�λ(������ָ�룩
//		int lasti = 0;
//		for (int i = 0; i < s.length(); i++) {
//			//�������ظ�
//			if (pos[s[i]] != 0) {
//				length = max(length , (i-lasti));
//				lasti = max(lasti , (pos[s[i]]));
//				//cout <<length<<" "<< lennew <<" "<< lasti << " " << pos[s[i]] << endl;
//			}
//			//�����������һ��
//			if (i == (s.length() - 1)) {
//				length = (length > (s.length() - lasti)) ? length : (s.length() - lasti);
//			}
//			pos[s[i]] = i + 1;
//		    //cout << pos[s[i]] << " " << s[i] << endl;
//		}
//
//		////����˼·
//		//int length = 0;
//		//for (int i = 0; i < s.length(); i++) {
//		//	int pos = i;
//		//	length = pos;
//		//	int position = s.find(s[i], pos+1);
//		//	//û�к����ظ��ģ��Ͱ�position��Ϊ���
//		//	if (position == -1) {
//		//		length = s.length() - i;
//		//	}
//		//	//�ҳ��͵�ǰλ���ظ�����Ӵ�
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
//		//˼·1
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



/****************************************�ڶ���*********************************************/
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