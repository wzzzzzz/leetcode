#include<iostream>
using namespace std;

#include<vector>
#include<string>
#include<map>
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		int len = words.size();
		if (len == 0)
			return res;
		int ilen = words[0].size();
		map<int, string> w;
		while (s.length() > ilen*len) {
			cout << s << endl;
			//找出每个单词的最近位置并排序
			for (int i = 0; i < len; i++) {
				int found = s.find(words[i]);
				if (found == -1) {
					return res;
				}
				while (w.find(found) != w.end()) {
					found = s.find(words[i],found+1);
					if (found == -1) {
						return res;
					}
				}
				w[found] = words[i];
			}
			for (map<int, string>::iterator i = w.begin(); i != w.end(); i++) {
				cout << i->first << " " << i->second << endl;
			}
			//检查
			map<int, string>::iterator it = w.begin();
			map<int, string>::iterator next = w.begin();
			next++;
			int flag = 1;
			while (next != w.end()) {
				//cout << it->first << " " << next->first << endl;
				if (it->first + ilen == next->first) {
					it = next;
					next++;
					flag++;
				}
				else {
					cout << it->first <<"xxx"<< endl;
					map<int, string>::iterator itt = w.begin();
					//把it前面的都删掉并重新往后找下一个索引
					for (int j = 0; j < flag; j++) {
						int tmp = s.find(itt->second, itt->first + 1);
						if (tmp == -1) {
							return res;
						}
						//这里关键是重复的检查位置，如果是原来要被销毁的就可以重复，新加的或者原来有但不被销毁的就不能重复也就是要做while
						while (w.find(tmp) != w.end()) {
							tmp = s.find(itt->second, tmp + 1);
							if (tmp == -1) {
								return res;
							}
						}
						cout << tmp <<  " "<< itt->second << endl;
						w.insert(pair<int, string>(tmp, itt->second));
						w.erase(itt);
						itt = w.begin();					
					}
					//从头检查
					it = w.begin();
					cout << it->first << endl;
					next = it;
					next++;
					flag = 1;
				}
			}
			res.push_back(w.begin()->first);
			cout << "res" << w.begin()->first << endl;

			int fi = w.begin()->first;
			for (int j = 0; j < fi + ilen; j++) {
				s.replace(j, 1, "0");
			}
			w.clear();
		}
		for (int j = 0; j < res.size(); j++) {
			cout << res[j] << " ";
		}
		return res;
		//这个思路不太行
		//string sr = s;
		//for (int i = 0; i < len; i++) {
		//	size_t found = sr.find(words[i]);
		//	while (found != string::npos) {
		//		sr.replace(found, ilen, to_string(i));
		//		found = sr.find(words[i]);
		//		cout << sr << endl;
		//	}
		//}
		//return res;
	}
};

int main() {
	Solution s;
	string ss = "wordgoodgoodgoodbestwordssssssssswordgoodgoodgoodgoodbestword";
	vector<string> words = { "word","good","best","good" };
	s.findSubstring(ss, words);
	system("pause");
	return 0;
}


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