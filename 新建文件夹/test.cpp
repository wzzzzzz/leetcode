#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string solve(string str1, string str2) {
    // cout << "call: str1:" << str1 << " str2:" << str2 << endl;
    if (str1.size() < str2.size()) {
        return "";
    }

    if (str2.empty()) {
        return str1;
    }
    if (str1.substr(0, str2.size()) != str2) {
        return "";
    }
    // cout <<str2.size()<<endl;
    // cout << str1.substr(str2.size())<<endl;
    return solve(str1.substr(str2.size()), str2);
}
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    // s1 = "ABABAB";
    // s2 = "ABAB";
     cout << s1.substr(4)<<endl;
    //solve(s1, s2);

    return 0;
}