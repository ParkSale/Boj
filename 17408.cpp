#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, arr[100005];
pii seg[100005 * 4];
pii getMax(pii a, pii b) {
	pii ret = { 0,0 };
	if (a.first > b.first) {
		ret.first = a.first;
		ret.second = max(b.first, a.second);
	}
	else {
		ret.first = b.first;
		ret.second = max(a.first, b.second);
	}
	return ret;
}
void update(int n) {
	while (n != 0) {
		seg[n] = getMax(seg[n * 2], seg[n * 2 + 1]);
		n /= 2;
	}
}
pii get(int s, int e) {
	pii ret = { 0,0 };
	while (s <= e) {
		if (s % 2 == 1) ret = getMax(ret, seg[s++]);
		if (e % 2 == 0) ret = getMax(ret, seg[e--]);
		s /= 2; e /= 2;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)cin >> arr[i];
	int s = 1;
	while (s < N)s *= 2;
	s--;
	for (int i = 1; i <= N; i++) seg[s + i] = { arr[i],0 };
	for (int i = s; i >= 1; i--) seg[i] = getMax(seg[i * 2], seg[i * 2 + 1]);
	cin >> M;
	while (M--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			seg[s + b] = { c,0 };
			update((s + b) / 2);
		}
		else {
			pii v = get(s + b, s + c);
			cout << v.first + v.second << "\n";
		}
	}
}