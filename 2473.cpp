#include <iostream>
using namespace std;
long long N, arr[5005], brr[5005];
bool visit[5005];
long long _abs(long long a) {
	if (a > 0) return a;
	return -a;
}
void merge(int l, int mid, int r) {
	int s1 = l, s2 = mid + 1, s = l;
	while (s1 <= mid && s2 <= r) {
		if (arr[s1] <= arr[s2]) {
			brr[s++] = arr[s1++];
		}
		else {
			brr[s++] = arr[s2++];
		}
	}
	for (int i = s1; i <= mid; ++i) brr[s++] = arr[i];
	for (int i = s2; i <= r; ++i) brr[s++] = arr[i];
	for (int i = l; i <= r; ++i) arr[i] = brr[i];
}
void mergeSort(int l, int r) {
	if (l == r) return;
	int mid = (l + r) / 2;
	mergeSort(l, mid);
	mergeSort(mid + 1, r);
	merge(l, mid, r);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}
	long long a, b, c, minV = 1e18;
	mergeSort(1, N);
	for (int i = 1; i <= N; ++i) {
		visit[i] = 1;
		int s = 1, e = N;
		while (s < e) {
			if (visit[s]) ++s;
			if (visit[e]) --e;
			if (s >= e) break;
			if (minV > _abs(arr[i] + arr[s] + arr[e])) {
				minV = _abs(arr[i] + arr[s] + arr[e]);
				a = arr[i], b = arr[s], c = arr[e];
			}
			if (arr[i] + arr[s] + arr[e] > 0) --e;
			else ++s;
		}
		visit[i] = 0;
	}
	arr[1] = a;
	arr[2] = b;
	arr[3] = c;
	mergeSort(1, 3);
	cout << arr[1] << " " << arr[2] << " " << arr[3];
}