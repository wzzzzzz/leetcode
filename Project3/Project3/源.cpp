#include<iostream>;
using namespace std;

#include<vector>;
#include<algorithm>;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();
		if (n == 1 && m == 0) {
			return nums1[0];
		}
		if (m == 1 && n == 0) {
			return nums2[0];
		}
		if (n == 1 && m == 1) {
			return (nums1[0] + nums2[0]) / 2;
		}
		double res;
		if (n > m) {
			res = findi(nums2, nums1, 0, m);
		}
		else {
			res = findi(nums1, nums2, 0, n);
		}
		cout << res;
		return res;
	}
	double findi(vector<int>& nums1, vector<int>& nums2, int l, int r) {
		int m = nums1.size();
		int n = nums2.size();
		int i = (l + r) / 2;
		int j;
		double res;
		j = (m + n )/2-i;
		cout << j << " ";
		if (j==0||i==m||(nums2[j - 1] < nums1[i])&&(i==0||j==n ||(nums1[i - 1] < nums2[j]))) {
			if ((m + n) % 2 != 0) {
				if (i == m) {
					res = nums2[j];
				}
				else if (j == n) {
					res = nums1[i];
				}
				else res= min(nums1[i],nums2[j]);
			}
			else {
				if (j == 0 && i == m){
					res = (nums2[j] + nums1[i - 1]) / 2.0;
				} 
				else if (j == 0) {
					res = (min(nums1[i], nums2[j]) + nums1[i - 1]) / 2.0;
				}
				else if (i == m) {
					res = (nums2[j] + max(nums1[i - 1], nums2[j - 1])) / 2.0;
				}
				else {
					res = (min(nums1[i], nums2[j]) + max(nums1[i - 1], nums2[j - 1])) / 2.0;
				}
			}
		}
		else if(j>0&&nums2[j-1]>nums1[i]) {
			cout << "a" << nums2[j - 1] << " " << nums1[i] << " ";
			res=findi(nums1, nums2, i+1, r);
		}
		else {
			cout << "b";
			res=findi(nums1, nums2, l, i-1);

		}
		cout << res << endl;
		return res;
	}
};

int main() {
	vector<int> n1 = { };
	vector<int> n2 = { 3,4};
	Solution s;
	s.findMedianSortedArrays(n1, n2);
	system("pause");
	return 0;
}