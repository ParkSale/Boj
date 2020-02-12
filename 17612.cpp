#include <iostream>
using namespace std;
int min(int a, int b) {
	if (a > b) return b;
	return a;
}
struct info {
	int id, time, num;
	bool operator < (const info& a)const {
		if (time == a.time) {
			return num > a.num;
		}
		return time < a.time;
	}
}I[100005];
void swap(info& a, info& b) {
	info tmp = a;
	a = b;
	b = tmp;
}
void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}
struct priorityQueue {
	info arr[100005];
	int size = 0;

	void insert(info tmp) {
		arr[++size] = tmp;
		int now = size;
		while (now != 1) {
			if (arr[now] < arr[now / 2]) {
				swap(arr[now], arr[now / 2]);
				now /= 2;
			}
			else break;
		}
	}

	info pop() {
		info ret = arr[1];
		arr[1] = arr[size--];
		int now = 1;
		while (now * 2 <= size) {
			int minIdx;
			if (now * 2 == size) {
				minIdx = now * 2;
			}
			else {
				if (arr[now * 2] < arr[now * 2 + 1]) minIdx = now * 2;
				else minIdx = now * 2 + 1;
			}
			if (arr[minIdx] < arr[now]) {
				swap(arr[minIdx], arr[now]);
				now = minIdx;
			}
			else break;
		}
		return ret;
	}
}pq;

struct priority_queue {
	int arr[100005];
	int size = 0;
	void insert(int n) {
		arr[++size] = n;
		int now = size;
		while (now != 1) {
			if (arr[now] < arr[now / 2]) {
				swap(arr[now], arr[now / 2]);
				now /= 2;
			}
			else break;
		}
	}
	int pop() {
		int ret = arr[1];
		arr[1] = arr[size--];
		int now = 1;
		while (now * 2 <= size) {
			int minIdx;
			if (now * 2 == size) minIdx = now * 2;
			else {
				if (arr[now * 2] < arr[now * 2 + 1]) minIdx = now * 2;
				else minIdx = now * 2 + 1;
			}
			if (arr[now] > arr[minIdx]) {
				swap(arr[now], arr[minIdx]);
				now = minIdx;
			}
			else break;
		}
		return ret;
	}
}pq2;

int N, K;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		I[i] = { a,b };
	}
	for (int i = 1; i <= min(N, K); i++) {
		pq.insert({ I[i].id,I[i].time,i });
	}
	int i = K + 1;
	long long ans = 0;
	int cnt = 1;
	while (i <= N) {
		ans += (long long)cnt * pq.arr[1].id;
		cnt++;
		pq2.insert(pq.arr[1].num);
		int v = pq.arr[1].time; pq.pop();
		while (pq.size != 0 && v == pq.arr[1].time) {
			pq2.insert(pq.arr[1].num);
			ans += (long long)cnt * pq.arr[1].id;
			cnt++;
			pq.pop();
		}
		while (pq2.size != 0) {
			int t = pq2.arr[1]; pq2.pop();
			pq.insert({ I[i].id,I[i].time + v,t });;
			i++;
			if (i == N + 1)break;
		}
	}
	while (pq.size != 0) {
		ans += (long long)cnt * pq.arr[1].id;
		cnt++;
		pq.pop();
	}
	cout << ans;
}