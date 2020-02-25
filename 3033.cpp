#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N;
string S;
const int mod = 100007;
vector<int> vt[mod];
int val;
int getHash(string s) {
	int v = 1;
	int ret = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		ret += s[i] * v;
		ret %= mod; v *= 31;
		v %= mod;
	}
	return ret;
}
bool can(int x) {
	for (int i = 0; i < mod; ++i) vt[i].clear();
	val = 1;
	for (int i = 0; i < x - 1; i++) {
		val *= 31;
		val %= mod;
	}
	int hashV = getHash(S.substr(0, x));
	vt[hashV].push_back(0);
	for (int i = 1; i <= S.length() - x; i++) {
		hashV = (((hashV - (S[i - 1] * val) % mod) % mod) * 31) + S[i + x - 1];
		hashV %= mod;
		if (hashV < 0) hashV += mod;
		if (!vt[hashV].empty()) {
			for (int n : vt[hashV]) {
				int cnt = 0;
				while (cnt != x) {
					if (S[i + cnt] != S[n + cnt]) {
						break;
					}
					++cnt;
				}
				if (cnt == x) return 1;
			}
		}
		vt[hashV].push_back(i);
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> S;
	int s = 1, e = N, maxV = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (can(mid)) {
			s = mid + 1;
			maxV = max(maxV, mid);
		}
		else e = mid - 1;
	}
	cout << maxV;
}