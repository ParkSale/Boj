#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
ll N, M, Y1, Y2, arr[100005], brr[100005];
typedef pair<ll, ll> pll;
pll crr[100005], drr[100005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> Y1 >> Y2;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	for (int i = 1; i <= M; i++) cin >> brr[i];
	sort(arr + 1, arr + N + 1);
	sort(brr + 1, brr + M + 1);
	int s = 1, e = 1;
	for (int i = 1; i <= N; i++) {
		if (arr[i] < brr[s]) {
			crr[i].first = s - 1;
			crr[i].second = M - (s - 1);
		}
		else {
			while (s <= M && arr[i] > brr[s]) {
				s++;
			}
			crr[i].first = s - 1;
			if (arr[i] == brr[s]) crr[i].second = M - s;
			else crr[i].second = M - (s - 1);
		}
	}
	s = 1;
	for (int i = 1; i <= M; i++) {
		if (brr[i] < arr[s]) {
			drr[i].first = s - 1;
			drr[i].second = N - (s - 1);
		}
		else {
			while (s <= N && brr[i] > arr[s]) {
				s++;
			}
			drr[i].first = s - 1;
			if (brr[i] == arr[s]) drr[i].second = N - s;
			else drr[i].second = N - (s - 1);
		}
	}
	ll cnt = 0;
	for (int i = N - 1; i >= 1; i--) {
		crr[i].second += crr[i + 1].second;
		crr[i].second %= mod;
	}
	for (int i = M - 1; i >= 1; i--) {
		drr[i].second += drr[i + 1].second;
		drr[i].second %= mod;
	}
	ll ans = 0;
	for (int i = 1; i < N; i++) {
		ans += (crr[i].first * crr[i + 1].second) % mod;
		ans %= mod;
	}
	for (int i = 1; i < M; i++) {
		ans += (drr[i].first * drr[i + 1].second) % mod;
		ans %= mod;
	}
	cout << ans;
}