#include <bits/stdc++.h>
using namespace std;
bool visit[205];
int get(int n, int k) {
	int ret = 0;
	while (n != 0) {
		ret += n % k;
		n /= k;
	}
	return ret;
}
int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 1000; i <= 9999; i++) {
		int v = get(i, 10);
		if (v == get(i, 12) && v == get(i, 16)) {
			cout << i << "\n";
		}
	}
}