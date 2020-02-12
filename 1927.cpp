#include <bits/stdc++.h>
using namespace std;
int N, heap[100005], s;
void insert(int n) {
	heap[++s] = n;
	int now = s;
	while (now != 1) {
		if (heap[now] < heap[now / 2]) {
			swap(heap[now], heap[now / 2]);
			now /= 2;
		}
		else break;
	}
}
int pop() {
	if (s == 0) return 0;
	int ret = heap[1];
	heap[1] = heap[s--];
	int now = 1;
	while (now * 2 <= s) {
		int minV = 1e9, minIdx = 0;
		if (now * 2 == s) {
			minIdx = now * 2;
		}
		else {
			if (heap[now * 2] > heap[now * 2 + 1]) minIdx = now * 2 + 1;
			else minIdx = now * 2;
		}
		minV = heap[minIdx];
		if (heap[now] > minV) {
			swap(heap[now], heap[minIdx]);
			now = minIdx;
		}
		else break;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	while (N--) {
		int a;
		cin >> a;
		if (a == 0) {
			cout << pop() << "\n";
		}
		else {
			insert(a);
		}
	}
}