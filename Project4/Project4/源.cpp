#include<iostream>
using namespace std;

#include<vector>
class Solution {
public:
	bool isBoomerang(vector<vector<int>>& points) {

	}
};

int main() {
	Solution s;
	vector<vector<int>> p = { { 1,1 },{ 2,3 },{ 3,2 } };
	s.isBoomerang(p);
	system("pause");
	return 0;
}



/**********************************************周赛02******************************************************/
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



/**********************************************周赛01******************************************************/
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
