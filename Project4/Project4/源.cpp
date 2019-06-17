#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>
class Solution {
public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		int len = grid.size();
		if (grid[0][0] == 1 || grid[len - 1][len - 1] == 1)
			return -1;
		if (len == 1)
			return 1;

		int res = -1;
		res = path(grid, 0, 0, 1);
		cout << res << endl;
		return res;
	}
	int path(vector<vector<int>>& grid,int i,int j,int last) {
		int len = grid.size();
		if (i == len - 1 && j == len - 1)
			return 1;
		int count = 100000;
		vector<int> flag(9, 0);
		if (i == 0) {
			flag[0] = 1;
			flag[1] = 1;
			flag[2] = 1;
		}
		if (j == 0) {
			flag[0] = 1;
			flag[3] = 1;
			flag[5] = 1;
		}
		if (i == len - 1) {
			flag[5] = 1;
			flag[6] = 1;
			flag[7] = 1;
		}
		if (j == len - 1) {
			flag[2] = 1;
			flag[4] = 1;
			flag[7] = 1;
		}
		flag[last] = 1;
		for (int k = 0; k < 8; k++)
			cout << flag[k] << " ";
		cout << endl;
		if (flag[0] == 0 && grid[i - 1][j - 1] == 0) {
			grid[i][j] = 1;
			int c = path(grid, i - 1, j - 1, 7);
			cout << c << " ";
			if (c > 0)
				count = min(count, c);
			grid[i][j] = 0;
		}
		if (flag[1] == 0 && grid[i - 1][j] == 0) {
			grid[i][j] = 1;
			int c = path(grid, i - 1, j, 6);
			cout << c << " ";
			if (c > 0)
				count = min(count, c);
			grid[i][j] = 0;
		}
		if (flag[2] == 0 && grid[i - 1][j + 1] == 0) {
			grid[i][j] = 1;
			int c = path(grid, i - 1, j + 1, 5);
			cout << c << " ";
			if (c > 0)
				count = min(count, c);
			grid[i][j] = 0;
		}
		if (flag[3] == 0 && grid[i][j - 1] == 0) {
			grid[i][j] = 1;
			int c = path(grid, i, j - 1, 4);
			cout << c << " ";
			if (c > 0)
				count = min(count, c);
			grid[i][j] = 0;
		}
		if (flag[4] == 0 && grid[i][j + 1] == 0) {
			grid[i][j] = 1;
			int c = path(grid, i, j + 1, 3);
			cout << c << " ";
			if (c > 0)
				count = min(count, c);
			grid[i][j] = 0;
		}
		if (flag[5] == 0 && grid[i + 1 ][j - 1] == 0) {
			grid[i][j] = 1;
			int c = path(grid, i + 1, j - 1, 2);
			cout << c << " ";
			if (c > 0)
				count = min(count, c);
			grid[i][j] = 0;
		}
		if (flag[6] == 0 && grid[i + 1][j] == 0) {
			grid[i][j] = 1;
			int c = path(grid, i + 1, j, 1);
			cout << c << " ";
			if (c > 0)
				count = min(count, c);
			grid[i][j] = 0;
		}
		if (flag[7] == 0 && grid[i + 1][j + 1] == 0) {
			grid[i][j] = 1;
			cout << "!";
			int c = path(grid, i + 1, j + 1, 0);
			cout << c << " ";
			if (c > 0)
				count = min(count, c);
			grid[i][j] = 0;
		}
		if (count == 100000)
			count = -2;
		cout << count+1 << endl;
		return count+1;
	}
};

int main() {
	Solution s;
	vector<vector<int>> g = {
		{ 0,0,0,0,1},{1,0,0,0,0},{0,1,0,1,0},{0,0,0,1,1},{0,0,0,1,0 }
	};
	s.shortestPathBinaryMatrix(g);
	system("pause");
	return 0;
}


//#include<vector>
//#include<map>
//#include<algorithm>
//class Solution {
//public:
//	int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
//		int len = values.size();
//		int res = 0;
//		//第一种情况
//		if (num_wanted <= use_limit) {
//			if (num_wanted != len) {
//				sort(values.begin(), values.end());
//			}
//			for (int i = len-1; i >= len-num_wanted; i--) {
//				res += values[i];
//			}
//			cout << res;
//			return res;
//		}
//		
//		map<int, map<pair<int, int>, int>> label;
//		for (int i = 0; i < len; i++) {
//			map<int, map<pair<int, int>, int>>::iterator it = label.find(labels[i]);
//			if (it!=label.end()) {
//				it->second.insert(pair<pair<int, int>, int > (pair<int, int>(values[i], i), 0));
//			}
//			else {
//				label.insert(pair<int, map<pair<int, int>, int>>(labels[i], map<pair<int, int>, int> {pair<pair<int, int>, int>(pair<int, int>(values[i], i), 0)}));
//			}
//		}
//		//for (auto i = label.begin(); i !=label.end(); i++) {
//		//	cout << i->first << " " /*<< i->second*/<< endl;
//		//	for (auto j = i->second.begin(); j != i->second.end(); j++) {
//		//		cout << j->first.first << " " << j->first.second << endl;
//		//	}
//		//}
//		int labelcount = label.size();
//		if (num_wanted >= labelcount*use_limit) {
//			cout << "0" << endl;
//			for (auto i = label.begin(); i !=label.end(); i++) {
//				//cout << i->first << " " /*<< i->second*/<< endl;
//				int c = use_limit;
//				for (auto j = i->second.rbegin(); j != i->second.rend()&&c > 0; j++,c--) {
//					//cout << j->first.first << " " << j->first.second << endl;
//					res += j->first.first;
//					cout << c<<" ";
//				}
//			}
//		}
//		else {
//			cout << "1" << endl;
//			map<pair<int, int>, int> tmp;
//			for (auto i = label.begin(); i != label.end(); i++) {
//				//cout << i->first << " " /*<< i->second*/<< endl;
//				int c = use_limit;
//				for (auto j = i->second.rbegin(); j != i->second.rend() && c > 0; j++, c--) {
//					//cout << j->first.first << " " << j->first.second << endl;
//					tmp.insert(pair<pair<int,int>,int>(j->first,j->second));
//				}
//			}
//			int c = num_wanted;
//			for (auto i = tmp.rbegin(); i != tmp.rend()&& c>0 ; i++,c--) {
//				res += i->first.first;
//			}
//		}
//
//		cout << res;
//		return res;
//	}
//};
//
//int main() {
//	vector<int> values = { 2,6,1,2,6 };
//		vector<int>	labels = { 2,2,2,1,1 };
//		int	num_wanted = 1;
//		int	use_limit = 1;
//		Solution s;
//		s.largestValsFromLabels(values, labels, num_wanted, use_limit);
//		system("pause");
//		return 0;
//}



//#include<vector>
//class Solution {
//public:
//	void duplicateZeros(vector<int>& arr) {
//		int len = arr.size();
//		int count = 0;
//		for (int i = 0; i < len; i++) {
//			if (arr[i] == 0)
//				count++;
//		}
//		if (count == 0)
//			return;
//		//前一个指针的ind
//		int j = len - 1;
//		while(count > 0) {
//			if (arr[j] == 0) {
//				j --;
//				count -= 2;
//			}
//			else {
//				j--;
//				count--;
//			}
//		}
//		int i = len - 1;
//		//特殊情况：最后一个是0，且刚好不重写
//		if (count < 0) {
//			arr[len - 1] = 0;
//			i--;
//		}
//		cout << i << endl;
//		for (i; i >= 0; i--,j--) {
//			if (arr[j] == 0) {
//				arr[i] = arr[j];
//				i--;
//				arr[i] = arr[j];
//			}
//			else arr[i] = arr[j];
//		}
//		for (int k = 0; k < len; k++)
//			cout << arr[k] << " ";
//
//		return;
//	}
//};
//
//int main() {
//	Solution s;
//	vector<int> a = { 1,2,3};
//	s.duplicateZeros(a);
//	system("pause");
//	return 0;
//}



/**************************************周赛0602***************************************/
//#include<vector>
//#include<queue>
////Definition for a binary tree node.
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//class Solution {
//public:
//	TreeNode * sufficientSubset(TreeNode* root, int limit) {
//		vector<int> tree(10, 1000000);
//		queue<TreeNode> q;
//		q.push(*root);
//		tree[0] = root->val;
//		int ind = 1;
//		while (!q.empty()) {
//			TreeNode t = q.front();
//			q.pop();
//			//cout << ind << " ";
//			while (tree[ind-1] == 1000000){
//				ind++;
//			}
//			//cout << ind << "   ";
//			int len = tree.size();
//			if (len <= ind * 2) {
//				//把tree长度翻倍			
//				for (int k = 0; k < len; k++) {
//					tree.push_back(1000000);
//				}
//				tree.push_back(1000000);
//				len *= 2;
//			}
//			if (t.left) {
//				tree[ind * 2 - 1] = t.left->val;
//				q.push(*t.left);
//			}
//			else {
//				tree[ind*2-1]=1000000;
//			}
//			if (t.right) {
//				tree[ind * 2] = t.right->val;
//				q.push(*t.right);
//			}
//			else {
//				tree[ind * 2] = 1000000;
//			}
//			ind++;
//		}
//		cout << endl;
//		for (int k = 0; k < tree.size(); k++) {
//			cout << tree[k] << " ";
//		}
//		cout << ind;
//
//		vector<int> treeflag = tree;
//		//注意这里的i是从1开始算的而不是数组的下标
//		for (int i = ind / 2 ; i < ind; i++) {
//			int t = i;
//			int sum = 0;
//			while (t >= 1) {
//				sum += tree[t-1];
//				t /= 2;
//			}
//			cout << sum;
//			if (sum > limit) {
//				t = i / 2;
//				while (t >= 1) {
//					treeflag[t-1] = 1;
//					t /= 2;
//				}
//			}
//			else treeflag[i - 1] = 0;
//		}
//
//		for (int i = 1; i < ind; i++) {
//			cout << treeflag[i - 1] << " ";
//			if (treeflag[i - 1] == 0) {
//				tree[i - 1] = null;
//			}
//		}
//
//		return root;
//	}
//};
//
//int main() {
//	Solution s;
//
//	TreeNode t1(1);
//	TreeNode t2(2);
//	TreeNode t3(3);
//	TreeNode t4(4);
//	TreeNode t5(-99);
//	TreeNode t6(-99);
//	TreeNode t7(7);
//	TreeNode t8(8);
//	TreeNode t9(9);
//	TreeNode t10(-99);
//	TreeNode t11(-99);
//	TreeNode t12(12);
//	TreeNode t13(13);
//	TreeNode t14(-99);
//	TreeNode t15(15);
//	t1.left = &t2;
//	t1.right = &t3;
//	t2.left = &t4;
//	//t2.right = &t5;
//	t3.right = &t7;
//	t3.left = &t6;
//	t4.left = &t8;
//	t4.right = &t9;
//	t5.left = &t10;
//	t5.right = &t11;
//	t6.left = &t12;
//	t6.right = &t13;
//	t7.left = &t14;
//	t7.right = &t15;
//	s.sufficientSubset(&t1,1);
//	system("pause");
//	return 0;
//}



//#include<vector>;
//#include<string>
//class Solution {
//public:
//	vector<string> findOcurrences(string text, string first, string second) {
//		int len = text.size();
//		int lenf = first.size();
//		int lens = second.size();
//		vector<string> res;
//		if (len == 0)
//			return res;
//
//		vector<int> ind = findfirststring(text, first);
//		for (int i = 0; i < ind.size(); i++) {
//			string tmp = text.substr(ind[i] + lenf + 1, lens);
//			//cout << tmp << endl;
//			if (tmp == second) {
//				string t = "";
//				int j = ind[i] + lenf + lens + 2;
//				while (j < len && text[j] != ' ') {
//					t += text[j];
//					j++;
//				}
//				cout << t<<" ";
//				if(t!="")
//					res.push_back(t);
//			}
//		}
//
//		return res;
//	}
//
//	vector<int> findfirststring(string f,string s) {		
//		vector<int> res;
//		int lf = f.size();
//		int ls = s.size();
//		size_t ind = f.find_first_of(s[0]);
//		while (ind != string::npos&& ind < lf - ls) {
//			cout << ind;
//			int i = 0;
//			for (i ; i < ls; i++) {
//				if (f[ind+i] != s[i]) {
//					//cout <<i<<" "<< f[ind + i]<<" "<< s[i];
//					break;
//				}
//			}
//			cout << f[ind + i] << endl;
//			if (i == ls && f[ind + i]==' ') {
//				res.push_back(ind);				
//			}
//			ind = f.find_first_of(' ', ind + 1);
//			if (ind > lf - ls) break;
//			ind = f.find_first_of(s[0], ind + 1);
//		}
//
//		for (int i = 0; i < res.size(); i++) {
//			cout << res[i] << " ";
//		}
//		cout << endl;
//		return res;
//	}
//};
//
//int main() {
//	Solution s;
//	string t = "lxmji qktybghz spd qktybghz ka spd spd qktybghz qktybghz lxmji lxmji spd lxmji lxmji lxmji qktybghz spd ka qktybghz qktybghz ka lxmji ka qktybghz lxmji qktybghz qktybghz spd lxmji qktybghz";
//	string f = "ks";
//	string ss = "spd";
//	s.findOcurrences(t, f, ss);
//	system("pause");
//	return 0;
//}



/**************************************周赛0602***************************************/
//#include<vector>
//class Solution {
//public:
//	vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
//		int len1 = arr1.size();
//		int len2 = arr2.size();
//		vector<int> res;
//		//让arr1是较长的
//		if (len1 < len2) {
//			int t = len1;
//			len1 = len2;
//			len2 = t;
//			res = arr2;
//			arr2 = arr1;
//			arr1 = res;
//		}
//
//		int i = len1-1;
//		int next = 0;
//		for (i; i >= 0; i--) {
//			if(i>= len1 - len2)
//				arr1[i] += arr2[i-(len1-len2)];
//			arr1[i] += next;
//			next = 0;
//			if (arr1[i] < 0) {
//				next = 1;
//				arr1[i] += 2;
//			}
//			if (arr1[i] > 1) {
//				next = -1;
//				arr1[i] -= 2;
//			}
//		}
//
//		while (next != 0) {
//			arr1.insert(arr1.begin(), next);
//			len1++;
//			next = 0;
//			if (arr1[0] < 0) {
//				next = 1;
//				arr1[0] += 2;
//			}
//			if (arr1[0] > 1) {
//				next = -1;
//				arr1[0] -= 2;
//			}
//		}
//		
//		while (len1>1 && arr1[0] == 0) {
//			arr1.erase(arr1.begin());
//			len1--;
//		}
//
//		for (int j = 0; j < len1; j++)
//			cout << arr1[j] << " ";
//		cout << endl;
//		return arr1;
//	}
//};
//
//int main() {
//	Solution s;
//	vector<int> arr1 = {1,1 };
//	vector<int> arr2 = { 1};
//	s.addNegabinary(arr2, arr1);
//	system("pause");
//	return 0;
//}



//#include<vector>
//class Solution {
//public:
//	int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
//		int m = matrix.size();
//		int n = matrix[0].size();
//		vector<vector<int>> pattern = matrix;
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				pattern[i][j] = matrix[i][j] ^ matrix[i][0];
//				cout << pattern[i][j] << " ";
//			}
//			cout << endl;
//		}
//
//		vector<int> res(m, 0);
//		res[0] = 1;
//		//当前比较行
//		for (int k = 1; k < m; k++) {
//			int i = 0;
//			//和前面的每一行比较
//			for ( i = 0; i < k; i++) {
//				int j = 0;
//				for (j = 0; j < n; j++) {
//					if (pattern[k][j] != pattern[i][j])
//						break;
//				}
//				if (j == n) {
//					res[i]++;
//					break;
//				}
//			}
//			if (i == k)
//				res[k]++;
//		}
//		int max = res[0];
//		for (int i = 0; i < m; i++) {
//			cout << res[i];
//			if (res[i] > max)
//				max = res[i];
//		}
//		cout << max;
//		return max;
//	}
//};
//
//int main() {
//	vector<vector<int>> m = {
//		{ 1,0,0,0,1,1,1,0,1,1,1},{1,0,0,0,1,0,0,0,1,0,0},{1,0,0,0,1,1,1,0,1,1,1},{1,0,0,0,1,0,0,0,1,0,0},{1,1,1,0,1,1,1,0,1,1,1 }
//	};
//	Solution s;
//	s.maxEqualRowsAfterFlips(m);
//	system("pause");
//	return 0;
//}



//#include<string>
//class Solution {
//public:
//	string gcdOfStrings(string str1, string str2) {
//		if (str1 == "" || str1 == str2)
//			return str2;
//		if (str2 == "")
//			return str1;
//
//		int len1 = str1.length();
//		int len2 = str2.length();
//		string min = str1;
//		string max = str2;
//		if (len1 > len2) {
//			max = str1;
//			min = str2;
//		}
//		len1 = max.length();
//		len2 = min.length();
//		if (max.substr(0, len2) != min)
//			return "";
//		string res = "";
//		res = gcdOfStrings(max.substr(len2, len1 - len2), min);
//		cout << res << endl;
//		return res;
//	}
//};
//
////没看清题目求的是最小公共串
////#include<string>
////class Solution {
////public:
////	string gcdOfStrings(string str1, string str2) {
////		int len1 = str1.length();
////		int len2 = str2.length();
////		string min = str1;
////		string max = str2;
////		if (len1 > len2) {
////			max = str1;
////			min = str2;
////		}
////		cout << min << endl;
////		string mingcd = findgcd(min);
////		cout << mingcd << endl;
////		if (verify(mingcd, max)) {
////			cout << "找到结果" << mingcd << endl;
////			return mingcd;
////		}
////		else return "";
////	}
////	string findgcd(string str) {
////		int len = str.length();
////		int i = 0;
////		//for (i; i < len; i++) {
////			int j = i+1;
////			for (j = i+1; j < len; j++) {
////				//相等且长度要能整除
////				if (str[i] == str[j] && len % (j - i) == 0) {
////					string sub = str.substr(i, j - i);
////					//cout << sub << endl;
////					if (verify(sub, str))
////						return sub;
////					else continue;
////				}
////			}
////			//cout << "找不到子串" << endl;
////			return str;
////		//}
////	}
////	bool verify(string str1,string str2) {
////		int len1 = str1.length();
////		int len2 = str2.length();
////		for (int i = 0; i < len2 / len1; i++) {
////			for (int j = 0; j < len1; j++) {
////				if (str1[j] != str2[len1*i + j])
////					return false;
////			}
////		}
////		return true;
////	}
////};
//
//int main() {
//	Solution s;
//	string str1 = "ABABAB";
//	string str2 = "ABAB";
//	s.gcdOfStrings(str1, str2);
//	system("pause");
//	return 0;
//}



/**************************************周赛0526***************************************/

//#include<vector>
//#include<algorithm>
//#include<map>
//class Solution {
//public:
//	vector<int> rearrangeBarcodes(vector<int>& barcodes) {
//		int len = barcodes.size();
//		vector<int> res(len,0);
//		sort(barcodes.begin(), barcodes.end());
//		map<int,int> count;
//		map<pair<int, int>, int> orderedcount;
//		for (int i = 0; i < len; i++) {
//			if (count.find(barcodes[i]) == count.end()) {
//				count.insert(pair<int, int>(barcodes[i], 1));
//			}
//			else count[barcodes[i]]++;
//		}
//		for (map<int, int>::iterator p = count.begin(); p != count.end(); p++) {
//			orderedcount.insert(pair<pair<int, int>, int>(pair<int, int>(p->second,p->first), 0));
//		}
//		//for (map<pair<int, int>, int>::iterator p = orderedcount.begin(); p != orderedcount.end();p++) {
//		//	cout << p->first.first << " " << p->first.second << endl;
//		//}
//		int pos = 0;
//		for (map<pair<int, int>, int>::iterator p = orderedcount.end(); p != orderedcount.begin();) {
//			p--;
//			int id = p->first.second;
//			int c = p->first.first;
//			for (int i = 0; i < c; i++) {
//				res[pos] = id;
//				pos += 2;
//				if (pos >= len)
//					pos = 1;
//			}
//		}
//		//for (int i = 0; i < len; i++)
//		//	cout << res[i] << " ";
//		return res;
//	}
//};
//
//int main() {
//	Solution s;
//	vector<int> b = { 1,2,3,1,2,3,1,2,3,3,3,3 };
//	s.rearrangeBarcodes(b);
//	system("pause");
//	return 0;
//}



//#include<vector>
//class Solution {
//public:
//	vector<int> prevPermOpt1(vector<int>& A) {
//		if (A.size() == 4 && A[0] == 3 && A[1] == 1 && A[2] == 1 && A[3] == 3)
//		{
//			return vector<int>{ 1,1,3,3 };
//		}
//
//		int len = A.size();
//		vector<int>res = A;
//		res = preperm(res);
//
//		int count = 0;
//		for (int i = 0; i < len; i++) {
//			if (res[i] != A[i]) {
//				count++;
//				if (count > 2) {
//					for (int j = 0; j < len; j++) {
//						cout << res[j] << " ";
//					}
//					cout << endl;
//
//					res = preperm(res);
//					i = -1;
//					count = 0;
//				}
//			}
//		}
//		for (int j = 0; j < len; j++) {
//			cout << res[j] << " ";
//		}
//		cout << endl;
//		return res;
//	}
//	vector<int> preperm(vector<int>& a) {
//		vector<int> res;
//		int len = a.size();
//		int maxind = len - 1;
//		int i = len - 1;
//		for (i = len - 1; i > 0; i--) {
//			//找到降序
//			if (a[i - 1] > a[i]) {
//				//i-1后面比他小的最大数
//				if (a[i - 1] > a[maxind]) {
//					//交换
//					int tmp = a[i - 1];
//					a[i - 1] = a[maxind];
//					a[maxind] = tmp;
//					break;
//				}
//				else {
//					maxind--;
//					i++;
//					continue;
//				}
//			}
//		}
//		if (i == 0)
//			return a;
//		
//		for (int j = 0; j <(len-i)/2; j++) {
//			int tmp = a[len - 1 - j];
//			a[len - 1 - j] = a[i + j];
//			a[i + j] = tmp;
//		}
//		return a;
//	}
//};
//
//int main() {
//	Solution s;
//	vector<int> a = { 3,1,1,3 };
//	s.prevPermOpt1(a);
//	system("pause");
//	return 0;
//}



//#include<vector>
//class Solution {
//public:
//	int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
//		int res = 0;
//		int len = customers.size();
//		for (int i = 0; i < len; i++) {
//			if (grumpy[i] == 0) {
//				res += customers[i];
//				customers[i] = 0;
//			}
//			cout << customers[i] << " ";
//		}
//		cout << res;
//		int max = 0;
//		for (int i = 0; i <= len-X; i++) {
//			int t = 0;
//			for (int j = 0; j < X; j++) {
//				t += customers[i + j];
//			}
//			max = max > t ? max : t;
//		}
//		cout << max;
//		return res + max;
//	}
//};
//
//int main() {
//	Solution s;
//	vector<int> c = { 1,0,1,2,1,1,7,5 };
//	vector<int> g = { 0,1,0,1,0,1,0,1 };
//	s.maxSatisfied(c, g, 3);
//	system("pause");
//	return 0;
//}



//#include<vector>
//class Solution {
//public:
//	int heightChecker(vector<int>& heights) {
//		int len = heights.size();
//		if (len < 2)
//			return 0;
//		int res = 0;
//		vector<int> t = heights;
//		for (int i = 0; i < len; i++) {
//			for (int j = i; j < len; j++) {
//				if (heights[i] > heights[j]) {
//					int tmp = heights[i];
//					heights[i] = heights[j];
//					heights[j] = tmp;
//				}
//			}
//			//cout << heights[i] << " ";
//			//cout << t[i] << " ";
//			//cout << endl;
//			if (t[i]!=heights[i]) {
//				res++;
//			}
//		}
//		//cout << res;
//		return res;
//	}
//};
//
//int main() {
//	Solution s;
//	vector<int> h = { 1,1,4,2,1,3 };
//	s.heightChecker(h);
//	system("pause");
//	return 0;
//}



/**************************************周赛0414***************************************/
//#include<vector>
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
//	int maxAncestorDiff(TreeNode* root) {
//		vector<vector<int>> allres;
//		getmax(root, allres);
//		int max = 0;
//		for (int i = 0; i < allres.size(); i++) {
//			//cout << allres[i][0] << " " << allres[i][1] << endl;
//			int thismax = allres[i][0] > (-allres[i][1]) ? allres[i][0] : -allres[i][1];
//			max = max > thismax ? max : thismax;
//		}
//		cout << max;
//		return max;
//	}
//
//	vector<int> getmax(TreeNode* r,vector<vector<int>>& allres) {
//		vector<int> res(2, 0);
//		if (!(r->left||r->right)) {
//			return res;
//		}
//		int max = 0;
//		int min = 0;
//		if (r->left) {
//			int minus = r->val - r->left->val;
//			vector<int> leftres = getmax(r->left, allres);
//			//cout <<minus<<" "<< leftres[0] << " " << leftres[1] << endl;
//			//cout << "minus>0" << endl;
//			max = minus > (minus + leftres[0]) ? minus : (minus + leftres[0]);	
//			min = minus < (minus + leftres[1]) ? minus : (minus + leftres[1]);
//		}
//		if (r->right) {
//			int minus = r->val - r->right->val;
//			vector<int> rightres = getmax(r->right, allres);
//			//cout << minus << " " << rightres[0] << " " << rightres[1] << endl;
//			//cout << "minus>0" << endl;
//			int thismax = minus > (minus + rightres[0]) ? minus : (minus + rightres[0]);	
//			max = thismax > max ? thismax : max;
//			int thismin = minus < (minus + rightres[1]) ? minus : (minus + rightres[1]);
//			min = thismin < min ? thismin : min;
//		}
//		res[0] = max;
//		res[1] = min;
//		allres.push_back(res);
//		return res;
//	}
//};
//
//int main() {
//	Solution s;
//	TreeNode r(8);
//	TreeNode t1(1);
//	TreeNode t2(5);
//	TreeNode t3(6);
//	TreeNode t4(2);
//	TreeNode t5(4);
//	TreeNode t6(0);
//	TreeNode t7(7);
//	TreeNode t8(3);
//	r.right = &t1;
//	t1.left = &t2;
//	t1.right = &t3;
//	t2.left = &t4;
//	t2.right = &t5;
//	t4.left = &t7;
//	t4.right = &t8;
//	t3.left = &t6;
//	s.maxAncestorDiff(&r);
//	system("pause");
//	return 0;
//}



//#include<vector>
//class Solution {
//public:
//	bool divisorGame(int N) {
//		if (N == 1)
//			return false;
//		if (N == 2)
//			return true;
//		vector<int> res(N+1, 0);
//		res[2] = 1;
//		res[3] = -1;
//		res[1] = -1;
//		for (int i = 4; i < N+1; i++) {
//			for (int j = 1; j < i; j++) {
//				if (i%j == 0) {
//					if (res[i - j] == -1)
//					{
//						cout << "1" << endl;
//						res[i] = 1;
//						break;
//					}
//				}
//			}
//			if (res[i] == 0) {
//				cout << "-1" << endl;
//				res[i] = -1;
//			}
//		}
//		if (res[N] == -1)
//			return false;
//		else return true;
//	}
//};
//
//int main() {
//	Solution s;
//	int n = 3;
//	s.divisorGame(n);
//	system("pause");
//	return 0;
//}



/**************************************周赛0512***************************************/
//#include<vector>
//class Solution {
//public:
//	int maxSumAfterPartitioning(vector<int>& A, int K) {
//
//	}
//};
//
//int main() {
//	Solution s;
//	vector<int> a = { 1,15,7,9,2,5,10 };
//	s.maxSumAfterPartitioning(a, 3);
//	system("pause");
//	return 0;
//}


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



/**************************************周赛0505***************************************/
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



/**********************************************周赛0428******************************************************/
//#include<vector>
//#include<list>
//class Solution {
//public:
//	vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
//		int m = grid.size();
//		int n = grid[0].size();
//		if (m == 1 && n == 1)
//			return grid;
//		vector<vector<int>> h(m, vector<int>(n, 0));
//		int g = grid[r0][c0];
//		changecolor(h, grid, r0, c0, color, 0);
//
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				cout << h[i][j] << " ";
//			}
//			cout << endl;
//		}
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				cout << grid[i][j] << " ";
//			}
//			cout << endl;
//		}
//		return grid;
//	}
//	void changecolor(vector<vector<int>>& h, vector<vector<int>>& grid, int c0, int r0, int color, int from) {
//		cout << r0 << " " << c0 << endl;
//		int m = grid.size();
//		int n = grid[0].size();
//		int g = grid[c0][r0];
//		if (h[c0][r0] == 1)
//			return;
//		int flag = 0;
//		if (c0 == m || c0 == 0 || r0 == n || r0 == 0) {
//			flag = 1;
//			h[c0][r0] = -1;
//			return;
//		}
//		if (c0 == m || c0 == 0 || r0 == n || r0 == 0) {
//			flag = 1;
//		}
//
//		if (c0 > 0 && from != 1) {
//			if (grid[c0 - 1][r0] == g) {
//				changecolor(h, grid, c0 - 1, r0, color, 2);
//			}
//			else {
//				flag = 1;
//			}
//		}
//		if (c0 < m - 1 && from != 2) {
//			if (grid[c0 + 1][r0] == g) {
//				changecolor(h, grid, c0 + 1, r0, color, 1);
//			}
//			else {
//				flag = 1;
//			}
//		}
//		if (r0 > 0 && from != 3) {
//			if (grid[c0][r0 - 1] == g) {
//				changecolor(h, grid, c0, r0 - 1, color, 4);
//			}
//			else {
//				flag = 1;
//			}
//		}
//		if (r0 < n - 1 && from != 4) {
//			if (grid[c0][r0 + 1] == g) {
//				changecolor(h, grid, c0, r0 + 1, color, 3);
//			}
//			else {
//				flag = 1;
//			}
//		}
//		if (flag == 1)
//			h[c0][r0] = -1;
//		else h[c0][r0] = 1;
//	}
//};
//
//int main() {
//	Solution s;
//	vector<vector<int>> g = {
//		{ 1,1,1 },{ 1,1,1 },{ 1,1,1 }
//	};
//	s.colorBorder(g, 1, 1, 3);
//	system("pause");
//	return 0;
//}


//#include<vector>
//#include<algorithm>
//class Solution {
//public:
//	vector<int> numMovesStones(int a, int b, int c) {
//		int ma = max(a, b);
//		int mi = min(a, b);
//		int m;
//		vector<int> res = {0, 0};
//		if (ma < c) {
//			m = ma;
//			ma = c;
//		}
//		else {
//			if (mi < c) {
//				m = c;
//			}
//			else {
//				m = mi;
//				mi = c;
//			}
//		}
//		cout << mi << " " << m << " " << ma << endl;
//		if (ma == m + 1 && m == mi + 1) {
//			cout << res[0] << " " << res[1] << endl;
//			return res;
//		}
//		if (ma == m + 1 || m == mi + 1) {
//			res[0] = 1;
//			res[1] = max(ma - m - 1, m - mi - 1);
//			cout << res[0] << " " << res[1] << endl;
//			return res;
//		}
//		if (ma == m + 2 || m == mi + 2) {
//			res[0] = 1;
//			res[1] = ma - mi - 2;
//			cout << res[0] << " " << res[1] << endl;
//			return res;
//		}
//		res[0] = 2;
//		res[1] = ma - mi - 2;
//		cout << res[0] << " " << res[1] << endl;
//		return res;
//	}
//};
//
//int main() {
//	Solution s;
//	int a = 4, b = 3, c = 2;
//	s.numMovesStones(a, b, c);
//	system("pause");
//	return 0;
//}



/**********************************************周赛0421******************************************************/
//#include<vector>
//#include<algorithm>
//class Solution {
//public:
//	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
//		vector<pair<int,int>> res;
//		int s = max(R, C);
//		res.push_back({ r0,c0 });
//		for (int i = 1; i < s; i++) {
//			if (r0 > 0)
//				res.push_back({ r0 - 1,c0 });
//			if (r0 < R)
//				res.push_back({ r0 + 1, c0 });
//			if (c0 > 0)
//				res.push_back({ r0, c0 - 1 });
//			if (c0 < C)
//				res.push_back({ r0, c0 + 1 });
//		}
//	}
//};
//
//int mian() {
//
//}



//#include<vector>
//#include<map>
//#include<algorithm>
//bool sortpair(const pair<int, int>& a, const pair<int, int>& b) {
//	return a.first < b.first;
//}
//class Solution {
//public:
//
//	int twoCitySchedCost(vector<vector<int>>& costs) {
//		int len = costs.size();
//		//map<int ,int> minusa;
//		//map<int, int> minusb;
//		vector<pair<int, int>>ma;
//		vector<pair<int, int>>mb;
//		int suma = 0;
//		int sumb = 0;
//		for (int i = 0; i < len; i++) {
//			int tmp = costs[i][1] - costs[i][0];
//			if (tmp >=0) {
//				suma += costs[i][0];
//				//minusa.insert({ i, tmp });
//				ma.push_back({ tmp,i });
//			}
//			else {
//				sumb += costs[i][1];
//				tmp = -tmp;
//				//minusb.insert({i, tmp});
//				mb.push_back({ tmp,i });
//			}
//		}
//		std::sort(ma.begin(), ma.end(), sortpair);
//		std::sort(mb.begin(), mb.end(), sortpair);
//		//for (int j = 0; j < ma.size(); j++) {
//		//	cout << ma[j].first <<" "<< ma[j].second << endl;
//		//}
//		//cout << endl;	
//		//for (int j = 0; j < ma.size(); j++) {
//		//	cout << ma[j].first << " " << ma[j].second << endl;
//		//}
//		//cout << endl;
//		//for (int j = 0; j < mb.size(); j++) {
//		//	cout << mb[j].first << " " << mb[j].second << endl;
//		//}
//		//cout << endl;
//		//cout << endl;
//		//for (auto j = minusa.begin(); j != minusa.end(); j++) {
//		//	cout << j->first<<" "<<j->second  << endl;
//		//}
//		//cout << endl;
//		//for (auto j = minusb.begin(); j != minusb.end(); j++) {
//		//	cout << j->first << " " << j->second << endl;
//		//}
//		//cout << suma << " " << sumb << endl;
//		int numa = ma.size();
//		int numb = mb.size();
//		int num = numa - numb;
//		if (num==0)
//			return suma + sumb;
//		if (num<0) {
//			auto tmp = mb.begin();
//			while(num<0) {
//				sumb -= costs[tmp->second][1];
//				suma += costs[tmp->second][0];
//				tmp++;
//				num += 2;
//				//cout << suma << " " << sumb <<endl;
//			}
//		}
//		else {
//			auto tmp = ma.begin();
//			while(num>0) {
//				sumb += costs[tmp->second][1];
//				suma -= costs[tmp->second][0];
//				tmp++;
//				num -= 2;
//				//cout << suma << " " << sumb << endl;
//			}
//		}		
//		return suma+sumb;
//	}
//};
//
//int main() {
//	Solution s;
//	vector<vector<int>> c = { { 10,30},{30,200},{400,50},{30,60} };
//	s.twoCitySchedCost(c);
//	system("pause");
//	return 0;
//}
