#include<iostream>;
using namespace std;

#include<string>;
class Solution {
public:
	bool isMatch(string s, string p) {
		if (s == ""&&p == "")
			return true;
		if (p == "")
			return false;
		int plen = p.size();
		int slen = s.size();
		int i;
		for (i = 0; i < plen; i++) {
			cout << i << endl;
			if (s[0] == p[i] || p[i] == '.') {
				cout << "ii" << endl;
				if (match(s, 1, p, i+1)) {
					cout << "111";
					return true;
				}
				else if ((i < plen - 1 && p[i + 1] == '*')) {
					continue;
				}
				else break;
			}
			else if (p[i] == '*')
			{
				continue;
			}
			else if (i < plen - 1 && p[i + 1] == '*') {
				continue;
			}
			else break;
		}
		if (slen == 0 && i == plen)
			return true;
		cout << "0";
		return false;
	}

	bool match(string s, int sind, string p, int pind) {
		int plen = p.size();
		if (sind == s.size() && pind == plen)
			return true;
		else if (pind == plen)
			return false;
		else if (sind > s.size())
			return false;
		for (pind; pind < plen; pind++) {
			cout << "for"<<sind<<" "<<pind<<endl;
			if ((sind<s.size()&&s[sind] == p[pind]) || p[pind] == '.') {
				if (match(s, sind + 1, p, pind + 1))
					return true;
				else if (pind < plen - 1 && p[pind + 1] == '*') {
					continue;
				}
				else break;
			}
			else if (p[pind] == '*') {
				if (pind > 0 && (p[pind - 1] == '.' || p[pind - 1] == s[sind])) {
					cout << "aaa" << endl;
					if (match(s, sind + 1, p, pind) || match(s, sind + 1, p, pind + 1) || match(s, sind, p, pind + 1))
						return true;
					else break;
				}
				else {
					cout << "bbb" << endl;
					continue;
				}
			}
			else if (pind < plen - 1 && p[pind + 1] == '*') {
				continue;
			}
			else break;
		}
		if (sind == s.size() && pind == plen)
			return true;
		return false;
	}
};

int main() {
	Solution s;
	string ss = "aaaab";
	string p = "a*a*a*c";
	s.isMatch(ss, p);
	system("pause");
	return 0;
}



/**************************************µÚÎåÌâ***************************************/
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