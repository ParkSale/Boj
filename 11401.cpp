using namespace std;
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <deque>
#define Mod 1000000007
#define MAX 2100000000
typedef long long ll;
typedef pair<int, int> pii;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll a = 1;
	ll b = 1;
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= K; i++) {
		b *= i;
		b %= Mod;
	}
	for (int i = N - K + 1; i <= N; i++) {
		a *= i;
		a %= Mod;
	}
	ll arr[30];
	ll brr[30];
	arr[0] = b;
	arr[1] = (b * b) % Mod;
	brr[0] = 1;
	brr[1] = 2;
	for (int i = 2; i < 30; i++) {
		arr[i] = arr[i - 1] * arr[i - 1];
		arr[i] %= Mod;
		brr[i] = brr[i - 1] * 2;
	}
	int temp = 0;
	ll ans = 1;
	for (int i = 29; i >= 0; i--) {
		if (temp + brr[i] <= Mod - 2) {
			temp += brr[i];
			ans *= arr[i];
			ans %= Mod;
		}
		if (temp == Mod - 2) {
			break;
		}
	}
	cout << (a * ans) % Mod;
}