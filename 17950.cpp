#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int H, x, arr[1000005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> H >> x;
	long long now = 0;
	for (int i = 1; i <= H; i++) {
		cin >> arr[i];
	}
	long long v = x;
	for (int i = 1; i <= H; i++) {
		now += arr[i] * v;
		v *= x;
		now %= mod;
		v %= mod;
	}
	cout << now;
}