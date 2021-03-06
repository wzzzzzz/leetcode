#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<iomanip>

using namespace std;

vector<long long int> calnn(int n) {
	vector<long long int> res(n + 1, 0);
	res[0] = 1;
	res[1] = 1;
	for (int i = 2; i <= n; i++) {
		res[i] = i * res[i - 1];
		res[i] %= 1000000007;
	}
	return res;
}

long long int calres(int n, int m, vector<long long int> nn) {
	long long int res = 0;
	long long int tmp = 0;
	int t = m > n ? n : m;
	for (int i = 0; i < t; i++) {
		tmp = (nn[i + 1] * nn[n - i - 1]) % 100000007;
		if (tmp != 0) {
			tmp = nn[n] / tmp;
			tmp %= 1000000007;
		}
		else tmp = 0;

		if (i != 0 && i != m - 1) {
			tmp *= calres(m - i, i, nn);
			tmp %= 1000000007;
		}
		res += tmp;
	}
	return res;
}

int main() {
	int n, m;
	cin >> n;
	cin >> m;
	long long int res;
	if (m == 1) {
		return n;
	}

	//vector<vector<int>> res(n, vector<int>(m, 0));
	//for (int i = 0; i < m; i++) {
	//	res[i][0] = 1;
	//}


	vector<long long int> nn = calnn(n);

	res = calres(n, m, nn);
	res %= 1000000007;
	cout << res;

	system("pause");
	return 0;
}


//int main() {
//	vector<int> nums;
//	int tmp;
//	while (cin >> tmp) {
//		nums.push_back(tmp);
//	}
//	
//	int len = nums.size();
//	if (len == 0) {
//		cout << -1;
//		return 0;
//	}
//	if (len == 1) {
//		cout << 1;
//		return 0;
//	}
//
//	vector<int> path(len,-1);
//	int min = 100;
//	for (int i = len - 2; i > 0; i--) {
//		if (nums[i] + i == len - 1) {
//			path[i] = 1;
//		}
//		else if (path[i] + i < len-1 && path[path[i] + i] != -1) {
//			path[i] = 1 + path[path[i] + i];
//		}
//		if (i < len / 2 && path[i] > 0 && path[i] < min) {
//			min = path[i];
//		}
//	}
//	if (min == 100) {
//		cout << -1;
//	}
//	else cout << min + 1;
//	system("pause");
//	return 0;
//}




////////////////////////////////////////////////////////////////����
//int main() {
//	vector<string> nums;
//	string t;
//	while (cin >> t)
//	{
//		nums.push_back(t);
//	}
//
//	for (int i = 0; i < nums.size(); i++) {
//		string num = nums[i];
//		long int res = 1;
//		int len = num.length();
//		res = res << len;
//
//		if (num[0] < '2') {
//			for (int j = 1; j < len; j++)
//			{
//				if (num[j] == '0') {
//					res -= 1 << (len - j - 1);
//				}
//				else if (num[j] == '1') {
//					continue;
//				}
//				else {
//					break;
//				}
//			}
//		}
//
//		res--;
//		cout << res << endl;
//	}
//	system("pause");
//	return 0;
//}



////////////////////////////////////////////////////////////////�ܲ�
//int main() {
//	int r;
//	int l;
//	cin >> l;
//	cin >> r;
//	double len = 3.141592657 * r;
//	int flag = l / len;
//	double angle = (l / len - flag) * 3.141592657;
//	double x, y;
//	x = r * cos(angle);
//	y = r * sin(angle);
//	
//	if (flag % 2 == 1) {
//		x = -1 * x;
//		y = -1 * y;
//	}
//	cout << fixed << setprecision(3) << x << " " << -1 * y << endl;
//	cout << x << " " << y << endl;
//
//	system("pause");
//	return 0;
//}



////////////////////////////////////////////////////////////////��3����
//int main() {
//	long int l;
//	long int r;
//	while (cin >> l) {
//		cin >> r;
//
//		long int res = 0;
//		long int tmp = 0;
//		if (l > r) {
//			cout << 0 << endl;
//			return 0;
//		}
//		for (long int i = 1; i < l; i++) {
//			if (i % 3 != 0) {
//				tmp += i;
//			}
//		}
//		//cout << tmp << endl;
//		for (long int i = l; i <= r; i++) {
//			if (i % 3 != 0) {
//				tmp += i;
//			}
//
//			if (tmp % 3 == 0) {
//				res++;
//				cout << i << endl;
//			}
//		}
//		cout << res << endl;
//	}
//
//	return 0;
//}



////////////////////////////////////////////////////////////////�ַ�����һ��
//int main() {
//	string str;
//	cin >> str;
//	int len = str.length();
//	map<char, int> count;
//	for (int i = 0; i < len; i++) {
//		count[str[i]]++;
//	}
//	
//	map<char, int>::iterator i;
//	for(i=count.begin();i!=count.end();i++)
//	{
//		cout << i->first << i->second;
//	}
//	system("pause");
//	return 0;
//}



////////////////////////////////////////////////////////////////�ַ�������
//int main() {
//	string a;
//	string b;
//	while (cin>>a)
//	{
//		cin >> b;
//		int ind = a.find(b[0]);
//		int flag = 0;
//		while (ind != -1)
//		{
//			if (a.substr(ind, b.length()) == b) {
//				flag = 1;
//				break;
//			}
//			else {
//				ind = a.find(b[0], ind + 1);
//			}
//		}
//		if (flag == 1) {
//			cout << flag << endl;
//			continue;
//		}
//		
//		ind = b.find(a[0]);
//		while (ind != -1)
//		{
//			if (b.substr(ind, a.length()) == a) {
//				flag = 1;
//				break;
//			}
//			else {
//				ind = b.find(a[0], ind + 1);
//			}
//		}
//		cout << flag << endl;
//	}
//	system("pause");
//	return 0;
//}



////////////////////////////////////////////////////////////////����
//int main() {
//	int n;
//	cin >> n;
//	int res = 0;
//	res = (n * n + n) / 2 + 1;
//	cout << res;
//	system("pause");
//	return 0;
//}



////////////////////////////////////////////////////////////////����
//int main() {
//	long int n;
//	cin >> n;
//	int res = 0;
//	while (n>0)
//	{
//		if (n % 2 == 1) {
//			res++;
//		}
//		n /= 2;
//	}
//	cout << res;
//	system("pause");
//	return 0;
//}



////////////////////////////////////////////////////////////////����
//int main() {
//	int n;
//	cin >> n;
//	n = 1024 - n;
//
//	int res = 0;
//	res += n / 64;
//	n %= 64;
//	res += n / 16;
//	n %= 16;
//	res += n / 4;
//	n %= 4;
//	res += n;
//	cout << res;
//	system("pause");
//	return 0;
//}



////////////////////////////////////////////////////////////////�ַ����ָ��
vector<int> strsplit(string s,char c) {
	int ind = s.find(c);
	vector<int> res;
	while (ind>-1)
	{
		int tmp = atoi(s.substr(0, ind).c_str());
		res.push_back(tmp);
		s = s.substr(ind + 1);
		ind = s.find(c);
	}
	res.push_back(atoi(s.c_str()));
	return res;
}



////////////////////////////////////////////////////////////////��Ϸ����
//int main() {
//	string n1;
//	string n2;
//	cin >> n1;
//	cin >> n2;
//	//cin.get();
//	//if (getline(cin,n2)) {
//	//	cout << n2 << endl;
//	//}
//	//else n2="";
//	//cout << n1 << endl << n2 << endl;
//
//	vector<int> nums1;
//	vector<int> nums2;
//	nums1 = strsplit(n1, ',');
//	if(n2!="")
//		nums2 = strsplit(n2, ',');
//	
//	int i = 0, j = 0;
//	int l1 = nums1.size(), l2 = nums2.size();
//	vector<int> res(l1 + l2, 0);
//
//	while (i < l1&&j < l2)
//	{
//		if (nums1[i] < nums2[j]) {
//			res[i + j] = nums1[i];
//			i++;
//		}
//		else {
//			res[i + j] = nums2[j];
//			j++;
//		}
//		cout << res[i + j - 1] << ",";
//	}
//	while (i < l1)
//	{
//		res[i + j] = nums1[i];
//		i++;
//		cout << res[i + j - 1] ;
//		if (i < l1) {
//			cout << ",";
//		}
//	}
//	while (j < l2)
//	{
//		res[i + j] = nums2[j];
//		j++;
//		cout << res[i + j - 1];
//		if (j < l2) {
//			cout << ",";
//		}
//	}
//	system("pause");
//	return 0;
//}



//////////////////////////////////////////////////////////////////��Ϸ���� 
//int main() {
//	string n;
//	cin >> n;
//	int len = n.length();
//	cout << 26 + 25 * len;
//	system("pause");
//	return 0;
//}