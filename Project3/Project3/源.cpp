#include<iostream>;
using namespace std;

#include<vector>;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n1 = nums1.size();
		int n2 = nums2.size();
		if (n1 == 1 && n2 == 0) {
			return nums1[0];
		}
		if (n2 == 1 && n1 == 0) {
			return nums2[0];
		}
		if (n1 == 1 && n2 == 1) {
			return (nums1[0] + nums2[0]) / 2;
		}
		int l = 0;
		int r = 0;
		int left = nums1[0];
		int right = nums2[0];
		if ((n1 + n2) % 2 == 0) {
			l = (n1 + n2) / 2;
			r = l + 1;
		}
		else {
			l = (n1 + n2) / 2 + 1;
		}
		//if (nums1[0] > nums2[n2 - 1]) {
		//	if (l > n2) {
		//		//在1里找
		//		left = nums1[l - n2 - 1];
		//		if (r != 0) {
		//			right = nums1[r - n2 - 1];
		//			return (left + right) / 2;
		//		}
		//		else return left;
		//	}
		//	if (l < n2) {
		//		//在2里找
		//		left = nums2[l-1];
		//		if (r != 0) {
		//			if (r < n2) {
		//				right = nums2[r-1];
		//				return (left + right) / 2;
		//			}
		//			else {
		//				right = nums1[r - n2 - 1];
		//				return (left + right) / 2;
		//			}
		//		}
		//		else return left;
		//	}
		//}
	}
};

int main() {
	vector<int> n1 = { 1,3 };
	vector<int> n2 = { 2 };
	Solution s;
	s.findMedianSortedArrays(n1, n2);
	system("pause");
	return 0;
}