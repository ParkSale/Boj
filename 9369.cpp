#include <bits/stdc++.h>
using namespace std;
int TC;
string str[105];
int tf[26];
vector<int> vt[27], vtt[27], idx;
bool visit[27];
map<char, int> mp, mpp;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> TC;
	while (TC--) {
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> str[i];
		string X, Y;
		cin >> X >> Y;
		for (int i = 1; i < 27; i++) {
			vt[i].clear();
		}
		idx.clear();
		int v = 1;
		mp.clear();
		for (int i = 0; i < X.length(); i++) {
			if (mp[X[i]] == 0) {
				mp[X[i]] = v++;
			}
			vt[mp[X[i]]].push_back(i);
		}
		for (int i = 1; i <= N; i++) {
			mpp.clear();
			for (int j = 1; j < 27; j++) vtt[j].clear();
			int vv = 1;
			for (int j = 0; j < str[i].length(); j++) {
				if (mpp[str[i][j]] == 0) {
					mpp[str[i][j]] = vv++;
				}
				vtt[mpp[str[i][j]]].push_back(j);
			}
			bool flag = 0;
			if (v != vv) continue;
			for (int j = 1; j < 27; j++) {
				if (vt[j].size() != vtt[j].size()) {
					flag = 1;
					break;
				}
				for (int k = 0; k < vt[j].size(); k++) {
					if (vt[j][k] != vtt[j][k]) {
						flag = 1;
						j = 27;
						break;
					}
				}
			}
			if (flag == 0) {
				idx.push_back(i);
			}
		}
		if (idx.size() == 1) {
			for (int i = 0; i < 26; i++) tf[i] = -1;
			for (int i = 0; i < X.length(); i++) {
				tf[str[idx[0]][i] - 'a'] = X[i] - 'a';
			}
			int cnt = 0, t = 0;
			for (int i = 0; i < 26; i++) visit[i] = 0;
			for (int i = 0; i < 26; i++) {
				if (tf[i] == -1) {
					cnt++;
					t = i;
				}
				else visit[tf[i]] = 1;
			}
			if (cnt == 1) {
				for (int i = 0; i < 26; i++) {
					if (!visit[i]) {
						tf[t] = i;
						break;
					}
				}
			}
			string ans = "";
			for (int i = 0; i < Y.length(); i++) {
				if (tf[Y[i] - 'a'] == -1) ans.push_back('?');
				else ans.push_back(tf[Y[i] - 'a'] + 'a');
			}
			cout << ans << "\n";
		}
		else {
			if (idx.size() == 0) cout << "IMPOSSIBLE\n";
			else {
				for (int i = 0; i < 26; i++) tf[i] = -1;
				for (int i = 1; i < idx.size(); i++) {
					for (int j = 0; j < str[idx[i]].length(); j++) {
						if (str[idx[0]][j] != str[idx[i]][j]) {
							str[idx[0]][j] = ' ';
						}
					}
				}
				for (int i = 0; i < X.length(); i++) {
					if (str[idx[0]][i] != ' ') {
						tf[str[idx[0]][i] - 'a'] = X[i] - 'a';
					}
				}
				int cnt = 0, t = 0;
				for (int i = 0; i < 26; i++) visit[i] = 0;
				for (int i = 0; i < 26; i++) {
					if (tf[i] == -1) {
						cnt++;
						t = i;
					}
					else visit[tf[i]] = 1;
				}
				if (cnt == 1) {
					for (int i = 0; i < 26; i++) {
						if (!visit[i]) {
							tf[t] = i;
							break;
						}
					}
				}
				string ans = "";
				for (int i = 0; i < Y.length(); i++) {
					if (tf[Y[i] - 'a'] == -1) ans.push_back('?');
					else {
						ans.push_back(tf[Y[i] - 'a'] + 'a');
					}
				}
				cout << ans << "\n";
			}
		}
	}
}