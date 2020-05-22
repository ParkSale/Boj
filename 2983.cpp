#include <iostream>
using namespace std;
#define plus 0
#define minus 1
struct info {
	int x, y, cnt;
	bool operator <(const info& a) const {
		if (x == a.x) return y < a.y;
		return x < a.x;
	}
}I[100005][2], tt[100005];
const int mod = 10007;
int N, K;
info now;
char str[100005];
struct Node {
	info t;
	Node* prev;
	Node* next;
}nodes[100005][2];
struct List {
	Node head, tail;
	void init() {
		head.prev = nullptr; tail.next = nullptr;
		head.next = &tail; tail.prev = &head;
	}
}list[mod][2];
void merge(int left, int mid, int right, bool flag) {
	int s1 = left, s2 = mid + 1, k = left;
	while (s1 <= mid && s2 <= right) {
		if (flag) {
			if (I[s1][0].x + I[s1][0].y == I[s2][0].x + I[s2][0].y) {
				if (I[s1][0].x < I[s2][0].x) {
					tt[k++] = I[s1++][0];
				}
				else {
					tt[k++] = I[s2++][0];
				}
			}
			else if (I[s1][0].x + I[s1][0].y < I[s2][0].x + I[s2][0].y) {
				tt[k++] = I[s1++][0];
			}
			else {
				tt[k++] = I[s2++][0];
			}
		}
		else {
			if (I[s1][1].x - I[s1][1].y == I[s2][1].x - I[s2][1].y) {
				if (I[s1][1].x < I[s2][1].x) {
					tt[k++] = I[s1++][1];
				}
				else {
					tt[k++] = I[s2++][1];
				}
			}
			else if (I[s1][1].x - I[s1][1].y < I[s2][1].x - I[s2][1].y) {
				tt[k++] = I[s1++][1];
			}
			else {
				tt[k++] = I[s2++][1];
			}
		}
	}
	for (int i = s1; i <= mid; ++i) tt[k++] = I[i][!flag];
	for (int i = s2; i <= right; ++i) tt[k++] = I[i][!flag];
	for (int i = left; i <= right; ++i) I[i][!flag] = tt[i];
}
void mergeSort(int left, int right, bool flag) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(left, mid, flag);
		mergeSort(mid + 1, right, flag);
		merge(left, mid, right, flag);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < mod; ++i) {
		list[i][0].init();
		list[i][1].init();
	}
	cin >> N >> K;
	for (int i = 1; i <= K; ++i) {
		cin >> str[i];
	}
	for (int i = 1; i <= N; ++i) {
		int a, b;
		cin >> a >> b;
		if (i == 1) now = { a,b,1 };
		Node* tmp = &nodes[i][plus];
		tmp->t = { a,b,i };
		tmp = &nodes[i][minus];
		tmp->t = { a,b,i };
		I[i][0] = { a,b,i };
		I[i][1] = { a,b,i };
	}
	mergeSort(1, N, 1);
	mergeSort(1, N, 0);
	for (int i = 1; i <= N; ++i) {
		Node* tmp = &nodes[I[i][0].cnt][plus];
		int k = (I[i][0].x + I[i][0].y) % mod;
		Node* now = &list[k][plus].tail;
		tmp->next = now; tmp->prev = now->prev; tmp->next->prev = tmp; tmp->prev->next = tmp;
		tmp = &nodes[I[i][1].cnt][minus];
		k = (I[i][1].x - I[i][1].y) % mod;
		if (k < 0) k += mod;
		now = &list[k][minus].tail;
		tmp->next = now; tmp->prev = now->prev; tmp->next->prev = tmp; tmp->prev->next = tmp;
	}
	for (int i = 1; i <= K; ++i) {
		if (str[i] == 'A') {
			int k = (now.x - now.y) % mod;
			if (k < 0) k += mod;
			Node* tmp = nodes[now.cnt][minus].next;
			while (tmp != &list[k][minus].tail) {
				if (now.x - tmp->t.x == now.y - tmp->t.y) {
					nodes[now.cnt][0].prev->next = nodes[now.cnt][0].next; nodes[now.cnt][0].next->prev = nodes[now.cnt][0].prev;
					nodes[now.cnt][1].prev->next = nodes[now.cnt][1].next; nodes[now.cnt][1].next->prev = nodes[now.cnt][1].prev;
					now = tmp->t;
					break;
				}
				tmp = tmp->next;
			}
		}
		else if (str[i] == 'B') {
			int k = (now.x + now.y) % mod;
			Node* tmp = nodes[now.cnt][plus].next;
			while (tmp != &list[k][plus].tail) {
				if (now.x - tmp->t.x == tmp->t.y - now.y) {
					nodes[now.cnt][0].prev->next = nodes[now.cnt][0].next; nodes[now.cnt][0].next->prev = nodes[now.cnt][0].prev;
					nodes[now.cnt][1].prev->next = nodes[now.cnt][1].next; nodes[now.cnt][1].next->prev = nodes[now.cnt][1].prev;
					now = tmp->t;
					break;
				}
				tmp = tmp->next;
			}
		}
		else if (str[i] == 'C') {
			int k = (now.x + now.y) % mod;
			Node* tmp = nodes[now.cnt][plus].prev;
			while (tmp != &list[k][plus].head) {
				if (now.x - tmp->t.x == tmp->t.y - now.y) {
					nodes[now.cnt][0].prev->next = nodes[now.cnt][0].next; nodes[now.cnt][0].next->prev = nodes[now.cnt][0].prev;
					nodes[now.cnt][1].prev->next = nodes[now.cnt][1].next; nodes[now.cnt][1].next->prev = nodes[now.cnt][1].prev;
					now = tmp->t;
					break;
				}
				tmp = tmp->prev;
			}
		}
		else {
			int k = (now.x - now.y) % mod;
			if (k < 0) k += mod;
			Node* tmp = nodes[now.cnt][minus].prev;
			while (tmp != &list[k][minus].head) {
				if (now.x - tmp->t.x == now.y - tmp->t.y) {
					nodes[now.cnt][0].prev->next = nodes[now.cnt][0].next; nodes[now.cnt][0].next->prev = nodes[now.cnt][0].prev;
					nodes[now.cnt][1].prev->next = nodes[now.cnt][1].next; nodes[now.cnt][1].next->prev = nodes[now.cnt][1].prev;
					now = tmp->t;
					break;
				}
				tmp = tmp->prev;
			}
		}
	}
	cout << now.x << " " << now.y;
}