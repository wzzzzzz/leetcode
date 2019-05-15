#include<iostream>
using namespace std;

#include<vector>
class Solution {
public:
	int maxSumAfterPartitioning(vector<int>& A, int K) {

	}
};

int main() {
	Solution s;
	vector<int> a = { 1,15,7,9,2,5,10 };
	s.maxSumAfterPartitioning(a, 3);
	system("pause");
	return 0;
}


//#include<vector>
//class Solution {
//public:
//	vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
//		vector<int> res(N);
//		if (N < 5) {
//			for (int i = 1; i <= N; i++) {
//				res[i-1]=i;
//			}
//			return res;
//		}
//		res[0] = 1;
//		res[1] = 2;
//		res[2] = 3;
//		res[3] = 4;
//
//		vector<vector<int>> p(N);
//		int len = paths.size();
//		int x, y;
//		for (int i = 0; i < len; i++) {
//			x = paths[i][0];
//			y = paths[i][1];
//			p[x-1].push_back(y);
//			p[y-1].push_back(x);
//		}
//
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < p[i].size(); j++) {
//				cout << p[i][j] << " ";
//			}
//			cout << endl;
//		}
//		
//		for (int i = 4; i < N; i++) {
//			int choose[5] = { 0,0,0,0,0 };
//			for (int j = 0; j < p[i].size(); j++) {
//				int tmp = p[i][j];
//				if (tmp < i+1) {
//					choose[res[tmp-1]] = -1;
//				}
//			}
//			for (int j = 1; j < 5; j++) {
//				cout << choose[j] << " ";
//				if (choose[j] == 0) {
//					res[i] = j;
//					break;
//				}
//			}
//			cout << endl;
//			cout << res[i] << " ";
//		}
//
//		return res;
//	}
//};
//
//int main() {
//	Solution s;
//	vector<vector<int>> p = { { 4,2},{6,2},{6,3},{2,3},{5,3},{6,5},{5,4},{4,1}};
//	s.gardenNoAdj(6, p);
//	system("pause");
//	return 0;
//}



//#include<vector>
//class Solution {
//public:
//	bool isRobotBounded(string instructions) {
//		int p[2] = { 0,0 };
//		int d = 0;
//		int len = instructions.length();
//		for (int j = 0; j < 4; j++) {
//			for (int i = 0; i < len; i++) {
//				int tmp = instructions[i];
//				switch (tmp)
//				{
//				case 'G': {
//					if (d == 0) {
//						p[1]++;
//					}
//					else if (d == 1) {
//						p[0]--;
//					}
//					else if (d == 2) {
//						p[1]--;
//					}
//					else {
//						p[0]++;
//					}
//					break;
//				}
//				case 'L': {
//					d++;
//					d %= 4;
//					break;
//				}
//				case 'R': {
//					d--;
//					d %= 4;
//					d = d < 0 ? d + 4 : d;
//					break;
//				}
//				default:
//					break;
//				}
//			}
//			if (p[0] == 0 && p[1] == 0) {
//				cout << "loop";
//				return true;
//			}
//		}
//		cout << "noloop";
//		return false;
//	}
//};
//
//int main() {
//	Solution s;
//	string ins = "GLGLLGLGRGLGL";
//	s.isRobotBounded(ins);
//	system("pause");
//	return 0;
//}



/**************************************周赛0512***************************************/
//#include<vector>
//class Solution {
//public:
//	int minScoreTriangulation(vector<int>& A) {
//		int len = A.size();
//		if (len == 3)
//			return A[0] * A[1] * A[2];
//		vector<int> min;
//		min.push_back(0);
//		for (int i = 1; i < len; i++) {
//			if (A[i] < A[min[0]]) {
//				min.clear();
//				min.push_back(i);
//			}
//			else if (A[i] == A[min[0]]) {
//				min.push_back(i);
//			}
//		}
//		//for (int i = 0; i < min.size(); i++)
//		//	cout << min[i] << " ";
//
//		//根据最小值分成几个区域
//		vector<vector<int>> tras = {};//这个里面保存的是A的这种值，而不是ind
//		vector<vector<int>> mins = {};
//		for (int i = 1; i < min.size(); i++) {
//			if (min[i] - min[i - 1] > 1) {
//				vector<int> tra;
//				for (int j = min[i - 1]; j <= min[i]; j++) {
//					tra.push_back(A[j]);
//				}
//				mins.push_back({ 0,min[i]-min[i-1] });
//				tras.push_back(tra);
//			}
//		}
//
//		int res = 0;
//		//只有一个区域直接求
//		if (tras.size()==0)
//			res = getscore(A, min);
//		//有不止一个区域，就分别求值，然后加起来
//		else {
//			vector<int> tra;
//			int ind = 0;
//			int lastmin = min[min.size() - 1];
//			for (int i = 0; i < min[0]; i++) {
//				tra.push_back(A[i]);
//				ind++;
//			}
//			for (int i = 0; i < min.size(); i++) {
//				tra.push_back(A[min[i]]);
//				min[i] = ind++;
//			}
//			for (int i = lastmin + 1; i < len; i++) {
//				tra.push_back(A[i]);
//			}
//			tras.push_back(tra);
//			mins.push_back(min);
//
//			for (int k = 0; k < tras.size(); k++) {
//				cout <<"         "<<k << endl;
//				res += getscore(tras[k], mins[k]);
//				cout << endl;
//			}
//		}
//		cout << res;
//		return res;
//	}
//
//	int getscore(vector<int>& t, vector<int> min) {
//		int len = t.size();
//		int res = 48000000;
//		for (int i = 0; i < min.size(); i++) {
//			int tmp = 0;
//			int a = min[i];
//			for (int j = 0; j < len - 2; j++) {
//				int b = a + j + 1;
//				int c = a + j + 2;
//				if (b >= len) b -= len;
//				if (c >= len) c -= len;
//				tmp += t[a] * t[b] * t[c];
//			}
//			//cout << tmp << endl;
//			if (tmp <= res)
//				res = tmp;
//		}
//		cout << res<<" ";
//		return res;
//	}
//};
//
//int main() {
//	Solution s;
//	vector<int> a = { 3,5,2,5,2,6 };
//	s.minScoreTriangulation(a);
//	system("pause");
//	return 0;
//}



//Definition for a binary tree node.
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//class Solution {
//public:
//	TreeNode * bstToGst(TreeNode* root) {
//		Gst(root,0);
//
//		return root;
//	}
//	int Gst(TreeNode* root,int v) {
//		if (!(root->left || root->right)) {
//			root->val += v;
//			return root->val;
//		}
//		if (root->right) {
//			v = Gst(root->right,v);
//		}
//		root->val += v;
//		v = root->val;
//		if (root->left) {
//			v = Gst(root->left, v);
//		}
//		return v;
//	}
//};
//
//int main() {
//	Solution s;
//	TreeNode t4(4);
//	TreeNode t0(0);
//	TreeNode t1(1);
//	TreeNode t2(2);
//	TreeNode t3(3);
//	TreeNode t5(5);
//	TreeNode t6(6);
//	TreeNode t7(7);
//	TreeNode t8(8);
//	t4.left = &t1;
//	t4.right = &t6;
//	t1.left = &t0;
//	t1.right = &t2;
//	t2.right = &t3;
//	t6.left = &t5;
//	t6.right = &t7;
//	t7.right = &t8;
//	s.bstToGst(&t4);
//	cout << t0.val << " " << t1.val << " " << t2.val << " " << t3.val << " " << t4.val << " " << t5.val << " " << t6.val << " " << t7.val << " " << t8.val << " ";
//	system("pause");
//	return 0;
//}


//#include<vector>
//class Solution {
//public:
//	bool isBoomerang(vector<vector<int>>& points) {
//		if (checksame(points[0], points[1])|| checksame(points[1], points[2])|| checksame(points[0], points[2]))
//			return false;
//
//		float m = (float)(points[0][1] - points[1][1]) / (float)(points[0][0] - points[1][0]);
//		float n = (float)(points[0][1] - points[2][1]) / (float)(points[0][0] - points[2][0]);
//		cout << m << " " << n << endl;
//		if (m == n) {
//			cout << "1";
//			return false;
//		}
//		return true;
//	}
//
//	bool checksame(vector<int>&a, vector<int>&b) {
//		if (a[0] == b[0] && a[1] == b[1])
//			return true;
//		return false;
//	}
//};
//
//int main() {
//	Solution s;
//	vector<vector<int>> p = { { 1,1 },{ 2,2 },{ -1,-2 } };
//	s.isBoomerang(p);
//	system("pause");
//	return 0;
//}


//#include<string>;
//class Solution {
//public:
//	bool isMatch(string s, string p) {
//		if (p == "*")
//			return true;
//		if (s == "") {
//			if (p == "") {
//				return true;
//			}
//			else return false;
//		}
//		else if (p == "")
//			return false;
//		bool res = match(s, 0, p, 0);
//		cout << res;
//		return res;
//	}
//
//	bool match(string s, int sind, string p, int pind) {
//		cout << sind << " " << pind << endl;
//		int slen = s.length();
//		int plen = p.length();
//		if (pind > plen || sind > slen)
//			return false;
//		if (pind == plen) {
//			if(sind == slen)
//				return true;
//			else return false;
//		}
//		if (p[pind] == '?') {
//			return match(s, sind + 1, p, pind + 1);
//		}
//		else if (p[pind] != '*') {
//			if (s[sind] == p[pind]) {
//				return match(s, sind + 1, p, pind + 1);
//			}
//			else return false;
//		}
//		else {
//			while (pind < plen - 1 && p[pind + 1] == '*') {
//				pind++;
//			}
//			if (pind == plen - 1)
//				return true;
//			if (match(s, sind, p, pind + 1))
//				return true;
//
//			pind++;
//			char tmp = p[pind];
//			size_t ind = sind;
//			while (p[pind] == '?') {
//				pind++;
//				ind++;
//				if (ind >= slen)
//					return false;
//				if (pind == plen)
//					return true;
//
//			}
//			tmp = p[pind];
//			while (ind < slen) {
//				ind = s.find(tmp, ind);
//				if (ind != s.npos) {
//					if (match(s, ind, p, pind))
//						return true;
//					ind++;
//				}
//				else return false;
//			}
//		}
//		return false;
//	}
//};
//
//int main() {
//	Solution ss;
//	string s = "babbbaabbaaaaabbababaaaabbbbbbbbbbabbaaaabbababbabaa";
//	string p = "**a****a**b***ab***a*bab";
//	ss.isMatch(s, p);
//	system("pause");
//	return 0;
//}



/**************************************第四十二题***************************************/
//#include<vector>
//#include<stack>
//class Solution {
//public:
//	int trap(vector<int>& height) {
//		int len = height.size();
//		if (len < 3)
//			return 0;
//		int res = 0;
//		int left = 0;
//		int down;
//		int right;
//		stack<int> downflag;
//		while (height[left] == 0) {
//			left++;
//		}
//		int tmp;
//		//用来标记是否更新三个索引的位置
//		int flag = 0;
//		while (left < len) {
//			if (flag == 0) {
//				tmp = 0;
//				//让左指针指向平着的最后一个
//				while (left < len - 1 && height[left] == height[left + 1]) {
//					left++;
//				}
//				downflag.push(left);
//				//找下一个低的，遇到更高的就加入栈
//				down = left + 1;
//				if (down >= len)
//					break;
//				if (height[down] < height[left]){
//					//让中间指针指向平着的最后一个，为了保证右指针和中间指针不等
//					while (down < len - 1 && height[down] == height[down + 1]) {
//						down++;
//					}
//					right = down + 1;
//					if (right >= len)
//						break;
//				}
//				else {
//					right = down;
//					down = left;
//				}
//			}
//			cout << left << " " << down << " " << right << " ";
//			if (height[right] < height[down]) {					
//				left = down;
//				continue;
//			}
//			else {
//				if (height[right] <= height[left]) {
//					tmp += (height[right] - height[down])*(right - left - 1);					
//					res += tmp;
//					if (height[right] == height[left])
//						downflag.pop();
//					left = right;
//					flag = 0;
//				}
//				else {
//					tmp += (height[left] - height[down])*(right - left - 1);
//					downflag.pop();
//					if (!downflag.empty()) {
//						down = left;
//						left = downflag.top();
//						flag = 1;
//					}
//					else {
//						left = right;
//						res += tmp;
//						flag = 0;
//					}					
//					continue;
//				}
//			}
//			cout << res << endl;
//		}
//		cout << res;
//		return res;
//	}
//};
//
//int main() {
//	Solution s;
//	vector<int> h{ 0,1,0,2,1,0,1,3,2,1,2,1 };
//	s.trap(h);
//	system("pause");
//	return 0;
//}



/**************************************第四十一题***************************************/
//#include<vector>
//#include<algorithm>
//class Solution {
//public:
//	int firstMissingPositive(vector<int>& nums) {
//		//思路1
//		//int len = nums.size();
//		//vector<int> n (len,0);
//		//for (int i = 0; i < len; i++) {
//		//	if (nums[i] > 0 && nums[i] <= len) {
//		//		n[nums[i]-1] = 1;
//		//	}
//		//}
//		//for (int i = 0; i < len; i++) {
//		//	if (n[i] == 0)
//		//		return i+1;
//		//}
//		//return len + 1;
//		
//		//思路2
//		//int len = nums.size();
//		//int res = 1;
//		//sort(nums.begin(), nums.end());
//		//for (int i = 0; i < len; i++) {
//		//	if (nums[i] > 0) {
//		//		if (nums[i] > res) {
//		//			cout << res;
//		//			return res;
//		//		}
//		//		if (nums[i] == res)
//		//			res++;
//		//	}
//		//}
//		//cout << res;
//		//return res;
//
//		//思路3
//		int len = nums.size();
//		int tmp = 0;
//		for (int i = 0; i < len; i++) {
//			tmp = nums[i];
//			while (tmp < len &&tmp != (nums[tmp]-1)) {
//				if (nums[tmp] > 0 && nums[tmp] <= len) {
//					int t = nums[tmp]-1;
//					nums[tmp] = 1;
//					tmp = t;
//				}
//				else {
//					nums[tmp] = 0;
//					break;
//				}
//			}
//			for (int i = 0; i < len; i++) {
//				cout << nums[i];
//			}
//			cout << endl;
//		}
//		for (int i = 0; i < len; i++) {
//			cout << nums[i];
//		}
//		for (int i = 0; i < len; i++) {
//			if (nums[i] == 0) {
//				cout << " " << i+1;
//				return i+1;
//			}				
//		}
//		return len + 1;
//	}
//};
//
//int main() {
//	vector<int> nums{ 1,2,3,4};
//	Solution s;
//	s.firstMissingPositive(nums);
//	system("pause");
//	return 0;
//}



/**************************************第三十七题***************************************/
//#include<vector>
//class Solution {
//public:
//	void solveSudoku(vector<vector<char>>& board) {
//		vector<vector<int>> row(9,vector<int>(9,0));
//		vector<vector<int>> col(9, vector<int>(9, 0));
//		vector<vector<int>> block(9, vector<int>(9, 0));
//		for (int i = 0; i < 9; i++) {
//			for (int j = 0; j < 9; j++) {
//				if (board[i][j] != '.') {
//					int tmp = board[i][j] - '1';
//					row[i][tmp] = 1;
//					col[j][tmp] = 1;
//					int blockind = 3 * (i / 3) + j / 3;
//					block[blockind][tmp] = 1;
//				}
//			}
//		}
//		shudu(board, row, col, block);
//		//for (int i = 0; i < 9; i++) {
//		//	for (int j = 0; j < 9; j++) {
//		//		cout << board[i][j] << " ";
//		//	}
//		//	cout << endl;
//		//}
//	}
//
//	bool shudu(vector<vector<char>>& board, vector<vector<int>>& row, vector<vector<int>>& col, vector<vector<int>>& block) {
//		int i,j;
//		int flag = 0;
//		for (i = 0; i < 9; i++) {
//			for (j = 0; j < 9; j++) {
//				if (board[i][j] == '.') {
//					flag = 1;
//					break;
//				}
//			}
//			if (flag == 1)
//				break;
//		}
//		if (flag == 0)
//			return true;
//		int x;
//		for (x = 0; x < 9; x++) {
//			if (row[i][x] == 0) {
//				if (col[j][x] == 0) {
//					if (block[3 * (i / 3) + j / 3][x] == 0) {
//						board[i][j] = x + '1';
//						row[i][x] = 1;
//						col[j][x] = 1;
//						block[3 * (i / 3) + j / 3][x] = 1;
//						if (shudu(board, row, col, block))
//							return true;
//						else {
//							board[i][j] = '.';
//							row[i][x] = 0;
//							col[j][x] = 0;
//							block[3 * (i / 3) + j / 3][x] = 0;
//							continue;
//						}
//					}
//					else continue;
//				}
//				else continue;
//			}
//			else continue;
//		}
//		return false;
//	}
//};
//
//int main() {
//	Solution s;
//	vector<vector<char>> b = {
//		{ '5','3','.','.','7','.','.','.','.' },
//		{ '6','.','.','1','9','5','.','.','.' },
//		{ '.','9','8','.','.','.','.','6','.' },
//		{ '8','.','.','.','6','.','.','.','3' },
//		{ '4','.','.','8','.','3','.','.','1' },
//		{ '7','.','.','.','2','.','.','.','6' },
//		{ '.','6','.','.','.','.','2','8','.' },
//		{ '.','.','.','4','1','9','.','.','5' },
//		{ '.','.','.','.','8','.','.','7','9' },
//	};
//	s.solveSudoku(b);
//	system("pause");
//	return 0;
//}



/**************************************第三十二题***************************************/
//#include<stack>
//#include<vector>
//class Solution {
//public:
//	int longestValidParentheses(string s) {
//		int res = 0;
//		stack<int> hhh;
//		int len = s.length();
//		if (len == 0)
//			return res;
//
//		int i;
//		for (i = 0; i < len; i++) {
//			if (s[i] == '(') {
//				hhh.push(i);
//				s[i] = '0';
//				break;
//			}
//			else s[i] = '0';
//		}
//		if (i == len)
//			return res;
//
//		int tmp = 0;
//		int thisin = 0;
//		for (int j = i+1; j < len; j++) {
//			if (s[j] == ')') {
//				if (hhh.empty()) {
//					s[j] = '0';
//					continue;
//				}		
//				thisin = hhh.top();
//				s[thisin] = '1';
//				s[j] = '1';
//				int k;
//				for (k = thisin; k > 0; k--) {
//					if (s[k-1] == '0') {
//						tmp = j - k + 1;
//						break;
//					}
//				}
//				if (k == 0)
//					tmp = j + 1;
//				if (tmp > res)
//					res = tmp;
//				hhh.pop();
//			}
//			else {
//				hhh.push(j);
//				s[j] = '0';
//			}
//		}
//		cout << res;
//		return res;
//	}
//};
//
//int main() {
//	Solution s;
//	string ss = ")()())()()(";
//	s.longestValidParentheses(ss);
//	system("pause");
//	return 0;
//}



/**************************************第二十五题***************************************/
//#include<vector>
//#include<string>
//#include<map>
//#include<algorithm>
//class Solution {
//public:
//	vector<int> findSubstring(string s, vector<string>& words) {
//		vector<int> res;
//		int len = words.size();
//		if (len == 0)
//			return res;
//		int ilen = words[0].size();
//		int slen = s.length();
//		map<int, string> w;
//		while (slen >= ilen*len) {
//			cout << s << endl;
//			//找出每个单词的最近位置并排序
//			int found = s.find(words[0]);
//			if (found == -1) {
//				return res;
//			}
//			w[found] = words[0];
//			for (int i = 1; i < len; i++) {
//				found = s.find(words[i]);
//				if (found == -1) {
//					return res;
//				}
//				map<int, string>::iterator tmpind = w.find(found);
//				while (tmpind != w.end()) {
//					int nextind = max(tmpind->first + ilen, found + 1);
//					found = s.find(words[i], nextind);
//					if (found == -1) {
//						return res;
//					}
//					tmpind = w.find(found);
//				}
//				w[found] = words[i];
//			}
//			for (map<int, string>::iterator i = w.begin(); i != w.end(); i++) {
//				cout << i->first << " " << i->second << endl;
//			}
//			//检查
//			map<int, string>::iterator it = w.begin();
//			map<int, string>::iterator next = w.begin();
//			next++;
//			int flag = 1;
//			while (next != w.end()) {
//				//cout << it->first << " " << next->first << endl;
//				if (it->first + ilen == next->first) {
//					it = next;
//					next++;
//					flag++;
//				}
//				else {
//					cout << it->first <<"xxx"<< endl;
//					map<int, string>::iterator itt = w.begin();
//					//把前面要删掉的都挪到另一个map
//					map<int, string> move;
//					for (int j = 0; j < flag; j++) {
//						move[itt->first] = itt->second;
//						w.erase(itt);
//						itt = w.begin();
//					}
//					itt = move.begin();
//					//对move里面的都删掉并重新往后找下一个索引
//					for (int j = 0; j < flag; j++) {
//						int tmp = s.find(itt->second, itt->first + 1);
//						if (tmp == -1) {
//							return res;
//						}
//						//这里关键是重复的检查位置，如果是原来要被销毁的就可以重复，新加的或者原来有但不被销毁的就不能重复也就是要做while
//						//现在w里只有新加的或者原来有但不被销毁的
//						map<int, string>::iterator tmpind=w.find(tmp);
//						while (tmpind != w.end()) {
//							int nextind = max(tmpind->first + ilen, tmp + 1);
//							tmp = s.find(itt->second, nextind);
//							if (tmp == -1) {
//								return res;
//							}
//							tmpind = w.find(tmp);
//						}
//						cout << tmp <<  " "<< itt->second << endl;
//						w.insert(pair<int, string>(tmp, itt->second));
//						itt++;
//					}
//					//从头检查
//					it = w.begin();
//					cout << it->first << endl;
//					next = it;
//					next++;
//					flag = 1;
//				}
//			}
//			res.push_back(w.begin()->first);
//			cout << "res" << w.begin()->first << endl;
//
//			int fi = w.begin()->first;
//			for (int j = 0; j < fi+1; j++) {
//				s.replace(j, 1, "0");
//			}
//			slen = s.length() - fi - 1;
//			w.clear();
//		}
//		for (int j = 0; j < res.size(); j++) {
//			cout << res[j] << " ";
//		}
//		return res;
//		//这个思路不太行
//		//string sr = s;
//		//for (int i = 0; i < len; i++) {
//		//	size_t found = sr.find(words[i]);
//		//	while (found != string::npos) {
//		//		sr.replace(found, ilen, to_string(i));
//		//		found = sr.find(words[i]);
//		//		cout << sr << endl;
//		//	}
//		//}
//		//return res;
//	}
//};
//
//int main() {
//	Solution s;
//	//这个测试用例过不了
//	string ss = "ababaab";
//	vector<string> words = { "ab","ba","ba"};
//	s.findSubstring(ss, words);
//	system("pause");
//	return 0;
//}



/**************************************第二十五题***************************************/
//Definition for singly-linked list.
//#include<stack>;
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//	ListNode * reverseKGroup(ListNode* head, int k) {
//		if (k == 1 || k == 0)
//			return head;
//		if (head == NULL)
//			return head;
//		ListNode* later = head;
//		ListNode* first = NULL;
//		ListNode* beforefirst = NULL;
//		int i;
//		for (i = 0; (i < k)&&later; i++) {
//			later = later->next;
//		}
//		if (i == k && later) {
//			first = head;
//		}
//		else if (i < k) {
//			return head;
//		}
//		else {
//			return reversek(head, k);
//		}
//		head = reversek(first, k);
//		first = head;
//		int j = 0;
//		while (later) {
//			j++;
//			later = later->next;
//			beforefirst = first;
//			first = first->next;
//			if (j == k) {
//				beforefirst->next=reversek(first, k);
//				first = beforefirst->next;
//				j = 0;
//			}
//		}
//		//while (head) {
//		//	cout << head->val << " ";
//		//	head = head->next;
//		//}
//		return head;
//	}
//	//solution
//	ListNode * reversek(ListNode* first, int k) {
//		ListNode* pre = first;
//		ListNode* p = first->next;
//		ListNode* q = p;
//		while (--k) {
//			q = p->next;
//			p->next = pre;
//			pre = p;
//			p = q;
//		}
//		first->next = p;
//		//while (pre) {
//		//	cout << pre->val << " ";
//		//	pre = pre->next;
//		//}
//		return pre;
//	}
//	//思路1
//	//ListNode * reversek(ListNode* first, int k) {
//	//	stack<ListNode* > stacks;
//	//	ListNode* nextnode = first;
//	//	ListNode* after;
//	//	while (k > 0) {
//	//		k--;
//	//		first = nextnode;
//	//		nextnode = nextnode->next;
//	//		first->next = NULL;
//	//		stacks.push(first);
//	//	}
//	//	after = nextnode;
//	//	first = stacks.top();
//	//	nextnode = NULL;	
//	//	stacks.pop();
//	//	while (!stacks.empty()) {
//	//		if (nextnode == NULL) {
//	//			first->next = stacks.top();
//	//			nextnode = first->next;
//	//		}
//	//		else {
//	//			nextnode->next = stacks.top();
//	//			nextnode = nextnode->next;
//	//		}
//	//		stacks.pop();
//	//	}
//	//	nextnode->next = after;
//	//	//while (first) {
//	//	//	cout << first->val;
//	//	//	first = first->next;
//	//	//}
//	//	return first;
//	//}
//};
//int main() {
//	Solution s;
//	ListNode l0(0);
//	ListNode l1(3);
//	ListNode l2(4);
//	ListNode l3(8);
//	ListNode l4(9);
//	ListNode l5(10);
//	ListNode l6(11);
//	ListNode l7(12);
//	l0.next = &l1;
//	l1.next = &l2;
//	l2.next = &l3;
//	l3.next = &l4;
//	l4.next = &l5;
//	//l5.next = &l6;
//	//l6.next = &l7;
//	s.reverseKGroup(&l0,3);
//	system("pause");
//	return 0;
//}



/**************************************第二十三题***************************************/
//#include<vector>;
////Definition for singly-linked list.
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//	ListNode * mergeKLists(vector<ListNode*>& lists) {
//		int len = lists.size();
//		//cout << len << endl;
//		if (len == 0)
//			return NULL;
//		if (len == 1)
//			return lists[0];
//		//思路1
//		while (len > 1) {
//			vector<ListNode*> thislists;
//			int i=0;
//			for (i = 0; i < (len/2)*2; i+=2) {
//				ListNode* tmp = mergetwo(lists[i], lists[i + 1]);
//				thislists.push_back(tmp);
//				//while (tmp) {
//				//	cout << tmp->val << " ";
//				//	tmp = tmp->next;
//				//}
//				//cout << i<<endl;
//			}
//			if (len % 2 != 0)
//				thislists.push_back(lists[i]);
//			lists = thislists;
//			len = lists.size();
//		}
//		while (lists[0]) {
//			cout << lists[0]->val << " ";
//			lists[0] = lists[0]->next;
//		}
//		return lists[0];
//		//思路2,结果太慢了
//		//ListNode* res;
//		//res = mergetwo(lists[0], lists[1]);
//		//for (int i = 2; i < len; i++) {
//		//	res = mergetwo(res, lists[i]);
//		//}
//		//while (res) {
//		//	cout << res->val << " ";
//		//	res = res->next;
//		//}
//		//return res;
//		//思路3
//		//ListNode reshead = *(lists[0]);
//		//ListNode* res = &reshead;
//		//int alllen = 1;
//		//while (res->next) {
//		//	res = res->next;
//		//	alllen++;
//		//}
//		//for (int i = 1; i < len; i++) {
//		//	res->next = lists[i];
//		//	while (lists[i]) {
//		//		lists[i] = lists[i]->next;
//		//		res = res->next;
//		//		alllen++;
//		//	}
//		//}
//		////排序？？？没想好
//		//
//		//while (reshead.next) {
//		//	cout << reshead.next->val << " ";
//		//	reshead = *(reshead.next);
//		//}
//		//cout << endl;
//		//return &reshead;
//	}
//
//	ListNode * mergetwo(ListNode* list1, ListNode* list2) {
//		ListNode* m = list1;
//		ListNode* n = list2;
//		if (m == NULL)
//			return n;
//		if (n == NULL)
//			return m;
//		ListNode* reshead;
//		ListNode res(-1);
//		reshead = &res;
//		//cout << reshead->val << " ";
//		while (m&&n) {
//			if (m->val <= n->val) {
//				ListNode* tmp = new ListNode(m->val);
//				reshead->next = tmp;
//				m = m->next;
//			}
//			else
//			{
//				ListNode* tmp = new ListNode(n->val);
//				reshead->next = tmp;
//				n = n->next;
//			}			
//			reshead = reshead->next;
//		}
//		if (m) {
//			reshead->next = m;
//		}
//		if (n) {
//			reshead->next = n;
//		}
//		//while (res.next) {
//		//	cout << res.next->val << " ";
//		//	res = *(res.next);
//		//}
//		//cout << endl;
//		return res.next;
//	}
//};
//
//int main() {
//	Solution s;
//	ListNode l00(0);
//	ListNode l01(3);
//	ListNode l02(4);
//	ListNode l03(8);
//	ListNode l04(9);
//	l00.next = &l01;
//	l01.next = &l02;
//	l02.next = &l03;
//	l03.next = &l04;
//	ListNode l10(1);
//	ListNode l11(2);
//	ListNode l12(10);
//	l10.next = &l11;
//	l11.next = &l12;
//	ListNode l20(-1);
//	ListNode l21(2);
//	ListNode l22(5);
//	l20.next = &l21;
//	l21.next = &l22;
//	ListNode l30(-2);
//	ListNode l31(3);
//	ListNode l32(6);
//	l30.next = &l31;
//	l31.next = &l32;
//	//s.mergetwo(&l00, &l20);
//	vector<ListNode*> lists{&l00,&l10,&l20,&l30};
//	s.mergeKLists(lists);
//	system("pause");
//	return 0;
//}



/**************************************第十题我觉得这题测试用例有问题***************************************/
//#include<string>;
//class Solution {
//public:
//	bool isMatch(string s, string p) {
//		if (s == ""&&p == "")
//			return true;
//		if (p == "")
//			return false;
//		int plen = p.size();
//		int slen = s.size();
//		string pp = "";
//		//简化p
//		for (int i = 0; i < plen;) {
//			if (i < plen - 1 && p[i] != '.'&&p[i + 1] == '*') {
//				char t = p[i];
//				pp += p[i];
//				pp += p[i + 1];
//				i += 2;
//				while (i < plen&&(p[i] == t || p[i] == '*'))
//					i++;
//			}
//			else {
//				pp += p[i];
//				i++;
//			}
//		}
//		cout << pp << endl;
//		int pplen = pp.size();
//		int i;
//		for (i = 0; i < pplen; i++) {
//			cout << i << endl;
//			if (s[0] == pp[i] || pp[i] == '.') {
//				cout << "ii" << endl;
//				if (match(s, 1, pp, i+1)) {
//					cout << "111";
//					return true;
//				}
//				else if ((i < pplen - 1 && pp[i + 1] == '*')) {
//					continue;
//				}
//				else break;
//			}
//			else if (pp[i] == '*')
//			{
//				continue;
//			}
//			else if (i < pplen - 1 && pp[i + 1] == '*') {
//				continue;
//			}
//			else break;
//		}
//		if (slen == 0 && i == pplen)
//			return true;
//		cout << "0";
//		return false;
//	}
//
//	bool match(string s, int sind, string p, int pind) {
//		int plen = p.size();
//		if (sind == s.size() && pind == plen)
//			return true;
//		else if (pind == plen)
//			return false;
//		else if (sind > s.size())
//			return false;
//		for (pind; pind < plen; pind++) {
//			cout << "for"<<sind<<" "<<pind<<endl;
//			if ((sind<s.size()&&s[sind] == p[pind]) || p[pind] == '.') {
//				if (match(s, sind + 1, p, pind + 1))
//					return true;
//				else if (pind < plen - 1 && p[pind + 1] == '*') {
//					continue;
//				}
//				else break;
//			}
//			else if (p[pind] == '*') {
//				if (pind > 0 && (p[pind - 1] == '.' || p[pind - 1] == s[sind])) {
//					cout << "aaa" << endl;
//					if (match(s, sind + 1, p, pind + 1) || match(s, sind + 1, p, pind) || match(s, sind, p, pind + 1))
//						return true;
//					else break;
//				}
//				else {
//					cout << "bbb" << endl;
//					continue;
//				}
//			}
//			else if (pind < plen - 1 && p[pind + 1] == '*') {
//				continue;
//			}
//			else break;
//		}
//		if (sind == s.size() && pind == plen)
//			return true;
//		return false;
//	}
//};
//
//int main() {
//	Solution s;
//	string ss = "acaabbaccbbacaabbbb";
//	string p = "a*.*b*.*a*aa*a*";
//	s.isMatch(ss, p);
//	system("pause");
//	return 0;
//}



/**************************************第五题***************************************/
//#include<vector>;
//#include<algorithm>;
//class Solution {
//public:
//	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//		int n = nums1.size();
//		int m = nums2.size();
//		if (n == 1 && m == 0) {
//			return nums1[0];
//		}
//		if (m == 1 && n == 0) {
//			return nums2[0];
//		}
//		if (n == 1 && m == 1) {
//			return (nums1[0] + nums2[0]) / 2;
//		}
//		double res;
//		if (n > m) {
//			res = findi(nums2, nums1, 0, m);
//		}
//		else {
//			res = findi(nums1, nums2, 0, n);
//		}
//		cout << res;
//		return res;
//	}
//	double findi(vector<int>& nums1, vector<int>& nums2, int l, int r) {
//		int m = nums1.size();
//		int n = nums2.size();
//		int i = (l + r) / 2;
//		int j;
//		double res;
//		j = (m + n )/2-i;
//		cout << j << " ";
//		if (j==0||i==m||(nums2[j - 1] < nums1[i])&&(i==0||j==n ||(nums1[i - 1] < nums2[j]))) {
//			if ((m + n) % 2 != 0) {
//				if (i == m) {
//					res = nums2[j];
//				}
//				else if (j == n) {
//					res = nums1[i];
//				}
//				else res= min(nums1[i],nums2[j]);
//			}
//			else {
//				if (j == 0 && i == m){
//					res = (nums2[j] + nums1[i - 1]) / 2.0;
//				} 
//				else if (j == 0) {
//					res = (min(nums1[i], nums2[j]) + nums1[i - 1]) / 2.0;
//				}
//				else if (i == m) {
//					res = (nums2[j] + max(nums1[i - 1], nums2[j - 1])) / 2.0;
//				}
//				else {
//					res = (min(nums1[i], nums2[j]) + max(nums1[i - 1], nums2[j - 1])) / 2.0;
//				}
//			}
//		}
//		else if(j>0&&nums2[j-1]>nums1[i]) {
//			cout << "a" << nums2[j - 1] << " " << nums1[i] << " ";
//			res=findi(nums1, nums2, i+1, r);
//		}
//		else {
//			cout << "b";
//			res=findi(nums1, nums2, l, i-1);
//
//		}
//		cout << res << endl;
//		return res;
//	}
//};
//
//int main() {
//	vector<int> n1 = { };
//	vector<int> n2 = { 3,4};
//	Solution s;
//	s.findMedianSortedArrays(n1, n2);
//	system("pause");
//	return 0;
//}