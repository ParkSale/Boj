#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, graph[105][105];
pii S, E, arr[105];
bool visit[105], flag;
vector<int> vt[105];
void init() {
	for (int i = 1; i <= N + 2; i++) {
		visit[i] = 0;
		vt[i].clear();
	}
	flag = 0;
}
void go(int n) {
	if (n == N + 2) {
		flag = 1;
		return;
	}
	for (int nn : vt[n]) {
		if (flag) return;
		if (!visit[nn]) {
			visit[nn] = 1;
			go(nn);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int TC;
	cin >> TC;
	while (TC--) {
		cin >> N;

		init();

		cin >> arr[1].first >> arr[1].second;

		for (int i = 2; i <= N + 1; i++) {
			int a, b;
			cin >> a >> b;
			arr[i] = { a,b };
		}

		cin >> arr[N + 2].first >> arr[N + 2].second;

		for (int i = 1; i <= N + 2; i++) {
			for (int j = 1; j <= N + 2; j++) {
				graph[i][j] = abs(arr[i].first - arr[j].first) + abs(arr[i].second - arr[j].second);
				if (graph[i][j] <= 1000) vt[i].push_back(j);
			}
		}
		visit[1] = 1;
		go(1);
		if (flag) {
			cout << "happy\n";
		}
		else cout << "sad\n";
	}
}