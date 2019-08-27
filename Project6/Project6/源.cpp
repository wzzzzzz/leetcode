

/**************************************0825øÏ ÷***************************************/
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//int main() {
//	int n = 0;
//	cin >> n;
//
//	vector<string> a;
//	vector<string> b;
//	for (int i = 0; i < n; i++) {
//		string t;
//		cin >> t;
//		a.push_back(t);
//		string tt;
//		cin >> tt;
//		b.push_back(tt);
//	}
//
//	for (int i = 0; i < n; i++) {
//		int inda = a[i].find('.');
//		int indb = b[i].find('.');
//		string suba;
//		string subb;
//		if (inda == -1) {
//			suba = a[i];
//		}
//		else suba = a[i].substr(0, inda);
//		if (indb == -1) {
//			subb = b[i];
//		}
//		else subb = b[i].substr(0, indb);
//		int flag = false;
//		while (suba != ""&&subb != "")
//		{
//			if (atoi(suba.c_str()) < atoi(subb.c_str())) {
//				flag = true;
//				cout << "true" << endl;
//				break;
//			}
//			else if (atoi(suba.c_str()) > atoi(subb.c_str())) {
//				break;
//			}
//			else {
//				if (inda > 0) {
//					a[i] = a[i].substr(inda + 1);
//				}
//				else a[i] = "";
//				if (indb > 0) {
//					b[i] = b[i].substr(indb + 1);
//				}
//				else b[i] = "";
//				//cout <<a[i] << " " << b[i] << endl;
//				if (a[i] == "") {
//					if (b[i] == "") {
//						break;
//					}
//					else {
//						suba = "0";
//					}
//				}
//				else {
//					inda = a[i].find('.');
//					if (inda == -1) {
//						suba = a[i];
//					}
//					else suba = a[i].substr(0, inda);
//				}
//				if (b[i] == "") {
//					subb = "0";
//				}
//				else {
//					indb = b[i].find('.');
//					if (indb == -1) {
//						subb = b[i];
//					}
//					else subb = b[i].substr(0, indb);
//				}
//
//			}
//		}
//		if (flag == false) {
//			cout << "false" << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}

/**************************************2***************************************/
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	cout << n;
//	vector<int> nums(n, 0);
//	for (int i = 0; i<n; i++) {
//		cin >> nums[i];
//	}
//	for (int i = 0; i<n; i++) {
//		int tmp = 0;
//		while (tmp>3)
//		{
//			int t;
//			while (nums[i]>9)
//			{
//				t = nums[i] % 10;
//				nums[i] /= 10;
//				tmp += t * t;
//			}
//			tmp += t * t;
//			nums[i] = tmp;
//		}
//		if (tmp == 1) {
//			cout << "true" << endl;
//		}
//		else {
//			cout << "false" << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}



/**************************************0824‘≥∏®µº***************************************/
/**************************************1***************************************/
//#include <iostream>
//#include <cstdio>
//#include<map>
//#include<vector>
//
//using namespace std;
//
//int main(int argc, char **argv) {
//	int a, b, tmp;
//	vector<int> ori;
//	map<int, int> counts;
//
//	cin >> a >> b;
//	while (cin >> tmp && ori.size() <= a) {
//		ori.push_back(tmp);
//		counts[tmp]++;
//	}
//
//	for (auto i : ori) {
//		if (counts[i]<b) {
//			cout << i << " ";
//		}
//	}
//	cout << endl;
//	return 0;
//}

/**************************************2***************************************/
//#include <iostream>
//#include <cstdio>
//#include<map>
//#include<vector>
//
//using namespace std;
//
//int main() {
//	//freopen("1.in","r",stdin);
//	int n = 0;
//	cin >> n;
//	vector<vector<int>> l;
//	for (int i = 0; i < n; i++) {
//		int x;
//		cin >> x;
//		vector<int> t;
//		for (int j = 0; j < x; j++) {
//			int k;
//			scanf("%d", &k);
//			t.push_back(k);
//		}
//		l.push_back(t);
//	}
//
//	for (int i = 0; i < n; i++) {
//		int a = l[i][0], b = l[i][1], c = l[i][2];
//
//		for (int j = 3; j < l[i].size(); j++) {
//			if ()
//		}
//	}
//
//	return 0;
//}