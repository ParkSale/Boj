#include <bits/stdc++.h>
using namespace std;
int N, M, K, graph[2005][2005];
bool chk[2005], visit[2005];
int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	cin >> K;
	while (K--) {
		int a;
		cin >> a;
		chk[a] = 1;
	}
	vector<int> ans;
	for (int i = 1; i <= N; i++) {
		bool flag = 0;
		if (chk[i] == 1) {
			for (int j = 1; j <= N; j++) {
				if (graph[i][j] == 1 && chk[j] == 0) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				ans.push_back(i);
				visit[i] = 1;
				for (int j = 1; j <= N; j++) {
					if (graph[i][j] == 1) {
						visit[j] = 1;
					}
				}
			}
		}
	}
	bool flag = 0;
	for (int i = 1; i <= N; i++) {
		if (chk[i] == 1 && visit[i] == 0) {
			flag = 1;
			break;
		}
	}
	if (flag) {
		cout << -1;
		exit(0);
	}
	cout << ans.size() << "\n";
	for (int n : ans) cout << n << " ";
}