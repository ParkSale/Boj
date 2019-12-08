#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
struct info {
	int x, y;
	bool operator < (const info& a) const {
		return y > a.y;
	}
};
priority_queue<info> pq;
int N;
pii arr[200005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1, a, b; i <= N; i++) {
		cin >> a >> b;
		arr[i] = { a,b };
	}
	sort(arr + 1, arr + N + 1);
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (pq.empty()) {
			pq.push({ arr[i].first, arr[i].second });
		}
		else {
			int n = pq.top().y;
			if (arr[i].first >= n) {
				while (!pq.empty()) {
					info p = pq.top();
					if (p.y <= arr[i].first) {
						pq.pop();
					}
					else break;
				}
				pq.push({ arr[i].first,arr[i].second });
			}
			else {
				pq.push({ arr[i].first,arr[i].second });
			}
		}
		ans = max(ans, (int)pq.size());
	}
	cout << ans;
}