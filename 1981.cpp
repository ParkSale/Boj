#include <iostream>
using namespace std;
struct info {
	int x, y;
}q[10005], dir[] = { {1,0},{-1,0},{0,1},{0,-1} };
int N, graph[105][105], arr[10005], s, brr[10005];
bool visit[205], chk[105][105];
int min(int a, int b) {
	return a < b ? a : b;
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
	if (l >= r) return;
	int mid = (l + r) / 2;
	mergeSort(l, mid);
	mergeSort(mid + 1, r);
	merge(l, mid, r);
}
bool can(int l, int r) {
	int s = 0, e = 0;
	if (graph[1][1] > r || graph[1][1] < l) return 0;
	if (graph[N][N] > r || graph[N][N] < l) return 0;
	q[e++] = { 1,1 };
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			chk[i][j] = 0;
		}
	}
	chk[1][1] = 1;
	while (s < e) {
		info p = q[s++];
		if (p.x == N && p.y == N) return 1;
		for (int i = 0; i < 4; ++i) {
			int px = p.x + dir[i].x, py = p.y + dir[i].y;
			if (px >= 1 && px <= N && py >= 1 && py <= N && !chk[px][py] && graph[px][py] >= l && graph[px][py] <= r) {
				q[e++] = { px,py };
				chk[px][py] = 1;
			}
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> graph[i][j];
			if (!visit[graph[i][j]]) {
				arr[++s] = graph[i][j];
				visit[graph[i][j]] = 1;
			}
		}
	}
	mergeSort(1, s);
	int l = 1, r = 1, minV = 1e9;
	while (l <= s && r <= s) {
		if (can(arr[l], arr[r])) {
			minV = min(minV, arr[r] - arr[l]);
			++l;
		}
		else ++r;
	}
	cout << minV;
}