#include <bits/stdc++.h>
using namespace std;
bool visit[205];
int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	while (1) {
		for (int i = 1; i <= 100; i++) visit[i] = 0;
		while (cin >> N) {
			if (N == -1) {
				exit(0);
			}
			if (N == 0) {
				break;
			}
			visit[N] = 1;
		}
		int cnt = 0;
		for (int i = 1; i <= 100; i++) {
			if (visit[i] == 1 && visit[i * 2] == 1) {
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
}