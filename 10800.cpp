#include <bits/stdc++.h>
using namespace std;
struct info {
	int c, s, idx;
	bool operator <(const info& a) const {
		return s < a.s;
	}
}I[200005];
int N, v[200005], vv[2005], ans[200005];
map<pair<int, int>, int> mp;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	int total = 0;
	for (int i = 1; i <= N; ++i) {
		int a, b;
		cin >> a >> b;
		I[i] = { a,b,i };
	}
	sort(I + 1, I + N + 1);
	int t = 0;
	for (int i = 1; i <= N; ++i) {
		//나보다 작은 애 중 같은 숫자빼고 같은 무게 빼고
		//같은 숫자면서 같은 무게인애는 더해주고
		//같은 숫자와 같은무게는 O(1)에 구함 가능
		//같은 숫자이면서 같은 무게인애는 어찌 구함?
		//t는 나보다 작은애들 의 합
		ans[I[i].idx] = t - v[I[i].c] - vv[I[i].s] + mp[{I[i].c, I[i].s}];
		t += I[i].s;
		v[I[i].c] += I[i].s;
		vv[I[i].s] += I[i].s;
		mp[{I[i].c, I[i].s}] += I[i].s;
	}
	for (int i = 1; i <= N; ++i) cout << ans[i] << "\n";
}