#include <bits/stdc++.h>
using namespace std;
int N, arr[4000005];
bool visit[4000005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 2; i <= sqrt(N); ++i) {
		if (visit[i] == 0) {
			int k = 2;
			while (i * k <= N) {
				visit[i * k] = 1;
				++k;
			}
		}
	}
	int idx = 0;
	for (int i = 2; i <= N; ++i) {
		if (visit[i] == 0) {
			arr[++idx] = i;
		}
	}
	int s = 1, e = 1, v = arr[1];
	int cnt = 0;
	while (e <= idx) {
		if (v < N) {
			++e;
			v += arr[e];
		}
		else if (v > N) {
			v -= arr[s];
			++s;
		}
		else {
			v -= arr[s]
				++cnt;
			++s;
		}
	}
	cout << cnt;
}