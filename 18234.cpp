#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, T;
pii arr[200005];
int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> T;
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		arr[i] = { b,a };
	}
	long long ans = 0;
	sort(arr + 1, arr + N + 1);
	int v = T - N;
	for (int i = 1; i <= N; i++) {
		ans += (long long)arr[i].first * v + arr[i].second;
		v++;
	}
	cout << ans;
}