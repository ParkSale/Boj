#include <bits/stdc++.h>
using namespace std;
long long N;
long long getV(long long a) {
	long long v = 1;
	while (v * 2 < a) v *= 2;
	return a - v;
}
int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	int cnt = 0;
	while (N != 0) {
		cnt++;
		N = getV(N);
	}
	if (cnt % 2 == 1) {
		cout << 0;
	}
	else {
		cout << 1;
	}
}