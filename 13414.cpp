#include <bits/stdc++.h>
using namespace std;
struct info {
	string s;
	int  v;
	bool operator <(const info& a) const {
		return v < a.v;
	}
};
int K, L;
map<string, int> mp;
vector<info> vt;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> K >> L;
	for (int i = 1; i <= L; ++i) {
		string s;
		cin >> s;
		mp[s] = i;
	}
	for (auto iter : mp) {
		vt.push_back({ iter.first,iter.second });
	}
	sort(vt.begin(), vt.end());
	for (int i = 0; i < min({ K, L,(int)vt.size() }); ++i) cout << vt[i].s << "\n";
}