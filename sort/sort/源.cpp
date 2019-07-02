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
			//�ҵ���һȦ������ֵ��ind
			int t = 0;
			for (int j = 0; j < i; j++) {
				if (nums[j] > nums[t]) {
					t = j;
				}
			}
			//�����һ������
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
			//�ҵ�����λ��
			for (j; j < i; j++) {
				if (tmp < nums[j])
					break;
			}
			//�Ѻ���ĺ���
			for (int k = i; k > j; k--) {
				nums[k] = nums[k - 1];
			}
			//����
			nums[j] = tmp;
		}
		for (int i = 0; i < len; i++)
			cout << nums[i] << " ";
		return nums;
	}

	vector<int> shellsort(vector<int> nums) {
		int len = nums.size();
		for (int gap = len / 2; gap > 0; gap /= 2) {
			cout << gap << "   ";
			int q = ceil(len / gap);
			//��ÿһ�е�������
			for (int i = 0; i < gap; i++) {
				//��������(gap*k+i)
				for (int k = 0+i; k < q*gap+i; k++) {
					int tmp = nums[k*gap + i];
					int j = 0;
					//�ҵ�����λ��
					for (j; j < k; j++) {
						if (tmp < nums[j*gap + i]);
							break;
					}
					//�Ѻ���ĺ���
					for (int s = k; s > j; s--) {
						nums[s*gap + i] = nums[(s - 1)*gap + i];
					}
					//����
					nums[j*gap + i] = tmp;
				}
				for (int k = 0; k < q; k++) {
					cout << nums[k*gap + i] << " ";
				}
				cout<<"  ";
			}
			for (int i = 0; i < len; i++)
				cout << nums[i] << " ";
			cout << endl;
		}

		for (int i = 0; i < len; i++)
			cout << nums[i] << " ";
		return nums;
	}
};

int main() {
	Solution s;
	vector<int> n = { 3,8,4,6,5,10,15,1,9,2 };
	//s.boublesort(n);
	//s.choosesort(n);
	//s.insertsort(n);
	s.shellsort(n);
	system("pause");
	return 0;
}