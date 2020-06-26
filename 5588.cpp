#include <iostream>
using namespace std;
struct info {
	int x, y;
	bool operator <(const info& a) const {
		if (x == a.x) {
			return y < a.y;
		}
		return x < a.x;
	}
}arr[205], brr[1005], tmp[1005];
int N, M;
void merge(int s, int mid, int e, info* t) {
	int s1 = s, s2 = mid + 1, s3 = s;
	while (s1 <= mid && s2 <= e) {
		if (t[s1] < t[s2]) {
			tmp[s3++] = t[s1++];
		}
		else tmp[s3++] = t[s2++];
	}
	for (int i = s1; i <= mid; ++i) tmp[s3++] = t[i];
	for (int i = s2; i <= e; ++i) tmp[s3++] = t[i];
	for (int i = s; i <= e; ++i) t[i] = tmp[i];
}
void mergeSort(int s, int e, info* t) {
	if (s == e) return;
	int mid = (s + e) / 2;
	mergeSort(s, mid, t);
	mergeSort(mid + 1, e, t);
	merge(s, mid, e, t);
}
bool find(int x, int y) {
	int s = 1, e = N;
	info tt = { x,y };
	while (s <= e) {
		int mid = (s + e) / 2;
		if (brr[mid] < tt) {
			s = mid + 1;
		}
		else if (brr[mid].x == x && brr[mid].y == y) {
			return 1;
		}
		else e = mid - 1;
	}
	return 0;
}
bool chk(int diffX, int diffY) {
	for (int i = 2; i <= M; ++i) {
		if (find(arr[i].x + diffX, arr[i].y + diffY)) {
			continue;
		}
		else return 0;
	}
	return 1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> M;
	for (int i = 1; i <= M; ++i) {
		int a, b;
		cin >> a >> b;
		arr[i] = { a,b };
	}
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		int a, b;
		cin >> a >> b;
		brr[i] = { a,b };
	}
	mergeSort(1, M, arr);
	mergeSort(1, N, brr);

	for (int j = 1; j <= N; ++j) {
		//i번째의 기준이 j번째가 될 때 해보기
		int diffX = brr[j].x - arr[1].x;
		int diffY = brr[j].y - arr[1].y;
		if (chk(diffX, diffY)) {
			cout << diffX << " " << diffY;
			exit(0);
		}
	}
}