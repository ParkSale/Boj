#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, X;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> X;
	if (X > N * 26 || X < N) {
		cout << "!";
	}
	else {
		int back = 0, front = 0;
		int t = X;
		bool flag = 0;
		while (X > (N - back)) {
			back++;
			X -= 26;
			flag = 1;
		}
		if (flag) {
			X += 26;
			back--;
		}
		front = (N - back - 1);
		int middle = t - front - back * 26;
		for (int i = 1; i <= front; i++) cout << "A";
		cout << char('A' + middle - 1);
		for (int i = 1; i <= back; i++) cout << "Z";
	}
}