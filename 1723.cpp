#include <iostream>
using namespace std;
int N, K;
double arr[20005], brr[20005];
int max(int a, int b) {
	return a > b ? a : b;
}
int min(int a, int b) {
	return a > b ? b : a;
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
int search(double v) {
	int s = 1, e = 2 * N, maxV = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (arr[mid] > v) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
			maxV = max(maxV, mid);
		}
	}
	return maxV;
}
int get(int n) {
	//arr[n]부터 K등분 해서 값 계산
	double t = arr[n] - 0.0001;
	double k = (double)360 / K;
	int v = n;
	t += k;
	int maxV = 0, minV = 1e9;
	//t보다 작은 것 중 가장 큰 수의 인덱스를 찾기
	for (int i = 1; i <= K; ++i) {
		int nn = search(t);
		maxV = max(maxV, nn - v + 1);
		minV = min(minV, nn - v + 1);
		v = nn + 1;
		t += k;
	}
	return maxV - minV;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}
	mergeSort(1, N);
	for (int i = 1; i <= N; ++i) {
		arr[N + i] = arr[i] + 360;
	}
	int ans = 1e9;
	for (int i = 1; i <= N; ++i) {
		//arr[i]를 포함하는 선이 기준이 될 때
		ans = min(ans, get(i));
	}
	cout << ans;
}