#include<iostream>
#include<algorithm>
#include<vector>
using namespace std; 


class Solution{
public:
	vector<int> boublesort(vector<int> nums) {
		int len = nums.size();
		for (int i = len; i > 1; i--) {
			for (int j = 1; j < i; j++) {
				if (nums[j] < nums[j - 1]) {
					swap(nums[j], nums[j - 1]);
				}
			}
		}
		for (int i = 0; i < len; i++)
			cout << nums[i] << " ";
		return nums;
	}

	vector<int> choosesort(vector<int> nums) {
		int len = nums.size();
		for (int i = len; i > 0; i--) {
			//找到这一圈中最大的值的ind
			int t = 0;
			for (int j = 0; j < i; j++) {
				if (nums[j] > nums[t]) {
					t = j;
				}
			}
			//与最后一个交换
			swap(nums[i-1], nums[t]);
		}
		for (int i = 0; i < len; i++)
			cout << nums[i] << " ";
		return nums;
	}

	vector<int> insertsort(vector<int> nums) {
		int len = nums.size();
		for (int i = 0; i <len; i++) {
			int tmp = nums[i];
			int j = 0;
			//找到插入位置
			for (j; j < i; j++) {
				if (tmp < nums[j])
					break;
			}
			//把后面的后移
			for (int k = i; k > j; k--) {
				nums[k] = nums[k - 1];
			}
			//插入
			nums[j] = tmp;
		}
		for (int i = 0; i < len; i++)
			cout << nums[i] << " ";
		return nums;
	}

	vector<int> shellsort(vector<int> nums) {
		int len = nums.size();
		for (int gap = len / 2; gap > 0; gap /= 2) {			
			int q = ceil(len / gap);
			//对每一列单独排序
			for (int i = 0; i < gap; i++) {
				//插入排序(gap*k+i)
				for (int k = 0 + i; k < q*gap + i && k < len; k += gap) {
					int tmp = nums[k];
					int j = 0 + i;
					//找到插入位置
					for (j; j < k; j+=gap) {
						if (tmp < nums[j]) {
							break;
						}
					}
					//把后面的后移
					for (int s = k; s > j; s-=gap) {
						nums[s] = nums[s - gap];
					}
					//插入
					nums[j] = tmp;
				}
			}
		}
		for (int i = 0; i < len; i++)
			cout << nums[i] << " ";
		return nums;
	}

	vector<int> mergesort(vector<int> nums) {
		int len = nums.size();
		vector<int> res = nums;
		//步长
		for (int m = 1; m < len; m*=2) {
			//对每两组进行合并
			for (int n = 0; n < len; n+=2*m) {
				int i = n;
				int j = n + m;
				int ind = i;
				while (i < len&&i < n + m && j < len&&j < n + 2 * m) {
					if (nums[i] < nums[j]) {
						res[ind++] = nums[i++];
					}
					else {
						res[ind++] = nums[j++];
					}
				}
				while (i < len&&i < n + m) {
					res[ind++] = nums[i++];
				}
				while (j < len&&j < n + 2 * m) {
					res[ind++] = nums[j++];
				}
			}
			nums = res;
		}

		for (int i = 0; i < len; i++)
			cout << nums[i] << " ";
		return nums;
	}

	vector<int> quicksort(vector<int> nums, int s, int e) {
		if (s >= e)
			return nums;
		int base = nums[s];
		int i = s;
		int j = e;
		while (i < j) {
			if (nums[j] < base) {
				nums[i++] = nums[j];
				nums[j] = nums[i];
			}
			else j--;
		}
		nums[i] = base;
		nums=quicksort(nums, s, i - 1);
		nums=quicksort(nums, i + 1, e);

		for (int i = 0; i < nums.size(); i++) {
			cout << nums[i] << " ";
		}
		cout << endl;
		return nums;
	}

	vector<int> radixsort(vector<int> nums,int max) {
		int len = nums.size();
		//有radix个桶
		int radix = max / 10+1;
		vector<vector<int>> bucket(radix);
		for (int i = 0; i < len; i++) {			
			int b = nums[i] / 10;
			bucket[b].push_back(nums[i]);
		}
		int ind = 0;
		for (int i = 0; i < radix; i++) {
			bucket[i] = boublesort(bucket[i]);//这里多输出了一遍
			for (int j = 0; j < bucket[i].size(); j++) {
				nums[ind++] = bucket[i][j];
			}
		}

		for (int i = 0; i < len; i++) {
			cout << nums[i] << " ";
		}
		return nums;
	}

	vector<int> heapsort(vector<int> nums) {
		int len = nums.size();

		return nums;
	}
};

int main() {
	Solution s;
	vector<int> n = { 31,8,4,6,25,10,15,1,9 };
	//vector<int> n = { 3,2 };
	//s.boublesort(n);
	//s.choosesort(n);
	//s.insertsort(n);
	//s.shellsort(n);
	//s.mergesort(n);
	//s.quicksort(n, 0, n.size() - 1);
	s.radixsort(n,31);
	system("pause");
	return 0;
}