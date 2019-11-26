#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N;
vector<int> vt[200005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1, a, b; i < N; i++) {
		cin >> a >> b;
		vt[a].push_back(b);
		vt[b].push_back(a);
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (vt[i].size() == 1) {
			cnt++;
		}
	}
	cout << (cnt + 1) / 2;
}