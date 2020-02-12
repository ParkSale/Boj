#include <iostream>
using namespace std;
int min(int a, int b) {
	return a >= b ? b : a;
}
int max(int a, int b) {
	return a >= b ? a : b;
}
struct info {
	int s, e, idx;
	bool operator <(const info& a) const {
		if (e == a.e) {
			return idx < a.idx;
		}
		return e < a.e;
	}
}I[100005];
struct info2 {
	int s, e;
	bool operator <(const info2& a) const {
		if (s == a.s) {
			return e < a.e;
		}
		return s < a.s;
	}
};
void swap(info& a, info& b) {
	info t = a;
	a = b;
	b = t;
}
int N, ans[100005];
struct Heap {
	info h[100005];
	int s = 0;
	void insert(info I) {
		h[++s] = I;
		int n = s;
		while (n != 1) {
			if (h[n] < h[n / 2]) {
				swap(h[n], h[n / 2]);
				n /= 2;
			}
			else break;
		}
	}
	info pop() {
		info ret = h[1];
		h[1] = h[s--];
		int n = 1;
		while (n * 2 <= s) {
			int minIdx = 0;
			if (n * 2 == s) {
				minIdx = n * 2;
			}
			else {
				if (h[n * 2] < h[n * 2 + 1]) minIdx = n * 2;
				else minIdx = n * 2 + 1;
			}
			if (h[minIdx] < h[n]) {
				swap(h[minIdx], h[n]);
				n = minIdx;
			}
			else break;
		}
		return ret;
	}
}room;
struct Heap2 {
	info2 h[100005];
	int s = 0;
	void insert(info2 I) {
		h[++s] = I;
		int n = s;
		while (n != 1) {
			if (h[n] < h[n / 2]) {
				swap(h[n], h[n / 2]);
				n /= 2;
			}
			else break;
		}
	}
	info2 pop() {
		info2 ret = h[1];
		h[1] = h[s--];
		int n = 1;
		while (n * 2 <= s) {
			int minIdx = 0;
			if (n * 2 == s) {
				minIdx = n * 2;
			}
			else {
				if (h[n * 2] < h[n * 2 + 1]) minIdx = n * 2;
				else minIdx = n * 2 + 1;
			}
			if (h[minIdx] < h[n]) {
				swap(h[minIdx], h[n]);
				n = minIdx;
			}
			else break;
		}
		return ret;
	}
}q;
struct Heap3 {
	int h[100005];
	int s = 0;
	void insert(int I) {
		h[++s] = I;
		int n = s;
		while (n != 1) {
			if (h[n] < h[n / 2]) {
				swap(h[n], h[n / 2]);
				n /= 2;
			}
			else break;
		}
	}
	int pop() {
		int ret = h[1];
		h[1] = h[s--];
		int n = 1;
		while (n * 2 <= s) {
			int minIdx = 0;
			if (n * 2 == s) {
				minIdx = n * 2;
			}
			else {
				if (h[n * 2] < h[n * 2 + 1]) minIdx = n * 2;
				else minIdx = n * 2 + 1;
			}
			if (h[minIdx] < h[n]) {
				swap(h[minIdx], h[n]);
				n = minIdx;
			}
			else break;
		}
		return ret;
	}
}num;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1, a, b; i <= N; ++i) {
		cin >> a >> b;
		I[i] = { a,b };
		q.insert({ a,b });
		num.insert(i);
	}
	int maxV = 0;
	while (q.s != 0) {
		info2 t = q.pop();
		//cout << t.s << " " << t.e << "\n";
		if (room.s == 0) {
			room.insert({ t.s,t.e,1 });
			maxV = max(maxV, 1);
			ans[1]++;
			num.pop();
		}
		else {
			while (room.s != 0 && room.h[1].e <= t.s) {
				num.insert(room.h[1].idx);
				room.pop();
			}
			int minV = 1e9;
			maxV = max(maxV, num.h[1]);
			ans[num.h[1]]++;
			room.insert({ t.s,t.e,num.pop() });
		}
	}
	cout << maxV << "\n";
	for (int i = 1; i <= maxV; ++i) cout << ans[i] << " ";
}