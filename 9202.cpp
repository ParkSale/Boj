#include <bits/stdc++.h>
using namespace std;
struct info {
	int x, y;
};
int W, B;
int score[] = { 0,0,0,1,1,2,3,5,11 };
char board[5][5];
string str[300005];
vector<info> vt[30];
bool visit[5][5];
bool flag;
vector<string> vtt;
void go(string s, int k, int x, int y) {
	if (k == s.length()) {
		flag = 1;
		return;
	}
	for (info t : vt[s[k] - 'A']) {
		if (flag) return;
		if (k == 0) {
			visit[t.x][t.y] = 1;
			go(s, k + 1, t.x, t.y);
			visit[t.x][t.y] = 0;
		}
		else {
			if (visit[t.x][t.y] == 0 && abs(x - t.x) <= 1 && abs(y - t.y) <= 1) {
				visit[t.x][t.y] = 1;
				go(s, k + 1, t.x, t.y);
				visit[t.x][t.y] = 0;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> W;
	for (int i = 1; i <= W; ++i) cin >> str[i];
	cin >> B;
	while (B--) {
		vtt.clear();
		for (int i = 0; i < 26; ++i) vt[i].clear();
		for (int i = 1; i <= 4; ++i) {
			for (int j = 1; j <= 4; ++j) {
				cin >> board[i][j];
				visit[i][j] = 0;
				vt[board[i][j] - 'A'].push_back({ i,j });
			}
		}
		int cnt = 0;
		int sc = 0;
		for (int i = 1; i <= W; ++i) {
			flag = 0;
			go(str[i], 0, 0, 0);
			if (flag) {
				++cnt;
				vtt.push_back(str[i]);
				sc += score[str[i].length()];
			}
		}
		int maxV = 0;
		string ans;
		for (string s : vtt) {
			if (s.length() > maxV) {
				maxV = s.length();
				ans = s;
			}
			else if (s.length() == maxV) {
				if (ans > s) {
					ans = s;
				}
			}
		}
		cout << sc << " " << ans << " " << cnt << "\n";
	}
}