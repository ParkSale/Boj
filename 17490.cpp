#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M, arr[1000005], pa[1000005];
ll K;
struct info {
	int x, y, d;
	bool operator< (const info& a) const {
		return d < a.d;
	}
};
vector<info> vt;
bool chk[1000005];
int find(int n) {
	if (pa[n] == n) return n;
	return pa[n] = find(pa[n]);
}
void hap(int a, int b) {
	pa[find(a)] = find(b);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		pa[i] = i;
	}
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		if (min(a, b) + 1 == max(a, b)) chk[min(a, b)] = 1;
		else chk[max(a, b)] = 1;
	}
	if (M <= 1) {
		cout << "YES";
		exit(0);
	}
	for (int i = 1; i < N; i++) {
		if (chk[i] == 0) vt.push_back({ i,i + 1,0 });
	}
	if (chk[N] == 0) vt.push_back({ N,1,0 });
	for (int i = 1; i <= N; i++) {
		vt.push_back({ N + 1,i,arr[i] });
	}
	sort(vt.begin(), vt.end());
	int cnt = 0;
	for (int i = 0; i < vt.size(); i++) {
		if (find(vt[i].x) != find(vt[i].y)) {
			hap(vt[i].x, vt[i].y);
			K -= vt[i].d;
			cnt++;
		}
		if (cnt == N) break;
	}
	if (K >= 0) cout << "YES";
	else cout << "NO";
}