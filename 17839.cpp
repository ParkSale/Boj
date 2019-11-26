#include <bits/stdc++.h>
using namespace std;
string str[200005];
map<string, int> mp;
vector<int> vt[200005];
vector<string> ans;
bool visit[200005];
void go(int n) {
	for (int nn : vt[n]) {
		if (!visit[nn]) {
			visit[nn] = 1;
			ans.push_back(str[nn]);
			go(nn);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	int cnt = 0;
	while (N--) {
		string a, b, c;
		cin >> a >> b >> c;
		if (mp[a] == 0) {
			mp[a] = ++cnt;
			str[cnt] = a;
		}
		if (mp[c] == 0) {
			mp[c] = ++cnt;
			str[cnt] = c;
		}
		vt[mp[a]].push_back(mp[c]);
	}
	if (mp["Baba"] != 0) {
		go(mp["Baba"]);
		sort(ans.begin(), ans.end());
		for (string s : ans) cout << s << "\n";
	}
}