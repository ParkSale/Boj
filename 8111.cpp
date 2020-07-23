#include <bits/stdc++.h>
using namespace std;
bool visit[20005];
struct info {
	int n;
	string s;
};
queue<info> q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	while (N--) {
		int a;
		cin >> a;
		for (int i = 0; i <= 20000; ++i) visit[i] = 0;
		while (!q.empty()) q.pop();
		q.push({ 1,"1" });
		visit[1] = 1;
		bool flag = 0;
		while (!q.empty()) {
			info p = q.front(); q.pop();
			if (p.n % a == 0) {
				flag = 1;
				cout << p.s << "\n";
				break;
			}
			string tmp = p.s;
			int n = (p.n * 10) % a;
			tmp.push_back('0');
			if (!visit[n]) {
				visit[n] = 1;
				q.push({ n,tmp });
			}
			n = ((p.n * 10) + 1) % a;
			tmp = p.s;
			tmp.push_back('1');
			if (!visit[n]) {
				visit[n] = 1;
				q.push({ n,tmp });
			}
		}
		if (!flag) cout << "BANK\n";
	}
}