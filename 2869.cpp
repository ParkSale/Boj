#include <bits/stdc++.h>
using namespace std;
int B, A, V;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> A >> B >> V;
	int t = (A - B);
	V -= A;
	int ans = (V / t) + 1;
	if (V % t != 0) ++ans;
	cout << ans;
}