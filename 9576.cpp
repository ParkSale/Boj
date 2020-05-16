#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, TC;
struct info {
	int x, y;
	bool operator < (const info& a) const {
		if (y == a.y) {
			return x > a.x;
		}
		return y < a.y;
	}
};
info arr[1005];
bool visit[1005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> TC;
	while (TC--) {
		cin >> N >> M;
		for (int i = 1; i <= M; ++i) {
			int a, b;
			cin >> a >> b;
			arr[i] = { a,b };
		}
		sort(arr + 1, arr + M + 1);
		for (int i = 1; i <= N; ++i) visit[i] = 0;
		for (int i = 1; i <= M; ++i) {
			for (int j = arr[i].x; j <= arr[i].y; ++j) {
				if (visit[j] == 0) {
					visit[j] = 1;
					break;
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= N; ++i) if (visit[i]) ++cnt;
		cout << cnt << "\n";
	}
}