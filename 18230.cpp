#include <bits/stdc++.h>
using namespace std;
int N, A, B, arr[2005], brr[2005];
struct info {
	int v, aIdx, bIdx;
}I[2005];
int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> A >> B;
	for (int i = 1; i <= A; i++) cin >> arr[i];
	for (int i = 1; i <= B; i++) cin >> brr[i];
	sort(arr + 1, arr + A + 1, greater<int>());
	sort(brr + 1, brr + B + 1, greater<int>());
	I[0] = { 0,1,1 };
	I[1] = { arr[1],2,1 };
	for (int i = 2; i <= N; i++) {
		if (I[i - 2].bIdx <= B) {
			if (I[i].v < I[i - 2].v + brr[I[i - 2].bIdx]) {
				I[i] = { I[i - 2].v + brr[I[i - 2].bIdx],I[i - 2].aIdx,I[i - 2].bIdx + 1 };
			}
		}
		if (I[i - 2].aIdx <= A - 1) {
			if (I[i].v < I[i - 2].v + arr[I[i - 2].aIdx] + arr[I[i - 2].aIdx + 1]) {
				I[i] = { I[i - 2].v + arr[I[i - 2].aIdx] + arr[I[i - 2].aIdx + 1],I[i - 2].aIdx + 2,I[i - 2].bIdx };
			}
		}
		if (I[i - 1].aIdx <= A) {
			if (I[i].v < I[i - 1].v + arr[I[i - 1].aIdx]) {
				I[i] = { I[i - 1].v + arr[I[i - 1].aIdx],I[i - 1].aIdx + 1, I[i - 1].bIdx };
			}
		}
	}
	cout << I[N].v;
}