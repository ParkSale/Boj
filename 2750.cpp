#include <bits/stdc++.h>
using namespace std;
int N, arr[1005];
void qsort(int s, int e) {
	if (s >= e) return;
	int pivot = s;
	int ss = s + 1, ee = e;
	while (ss <= ee) {
		while (ss <= e && arr[pivot] >= arr[ss]) ss++;
		while (ee > s&& arr[pivot] <= arr[ee]) ee--;
		if (ss > ee) swap(arr[pivot], arr[ee]);
		else swap(arr[ss], arr[ee]);
	}
	qsort(s, ee - 1);
	qsort(ee + 1, e);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	qsort(1, N);
	for (int i = 1; i <= N; i++) cout << arr[i] << "\n";
}