#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>
class Solution {
public:
	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
		vector<pair<int,int>> res;
		int s = max(R, C);
		res.push_back({ r0,c0 });
		for (int i = 1; i < s; i++) {
			if (r0 > 0)
				res.push_back({ r0 - 1,c0 });
			if (r0 < R)
				res.push_back({ r0 + 1, c0 });
			if (c0 > 0)
				res.push_back({ r0, c0 - 1 });
			if (c0 < C)
				res.push_back({ r0, c0 + 1 });
		}
	}
};

int mian() {

}
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
