//
// Created by LWZ on 2019/9/21.
//
#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<map>
#include<iomanip>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<long long int>> nums(n, vector<long long int>(4, 0));
	long long int a, b, p, q;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> p >> q;
		nums[i][0] = a;
		nums[i][1] = b;
		nums[i][2] = p;
		nums[i][3] = q;
	}

	int res = 0;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		res = 0;
		while (nums[i][0]+nums[i][2]<nums[i][1])
		{
			nums[i][2] *= nums[i][3];
			res++;
		}
		res++;
		cout << res << endl;
	}

	system("pause");
	return 0;
}

