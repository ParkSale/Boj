#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, V, arr[200005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> V;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	while (M--) {
		int a;
		cin >> a;
		a++;
		if (a <= N) {
			cout << arr[a];
		}
		else {
			a -= (V - 1);
			a %= (N - V + 1);
			if (a == 0) cout << arr[N];
			else cout << arr[a + V - 1];
		}
		cout << "\n";
	}
}