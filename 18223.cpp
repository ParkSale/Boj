#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
struct info {
	int n, d;
	bool operator <(const info& a) const {
		return d > a.d;
	}
};
int V, E, P, dist[5005];
vector<pii> vt[5005];
priority_queue<info> pq;
bool visit[5005];
int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> V >> E >> P;
	for (int i = 1; i <= E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vt[a].push_back({ b,c });
		vt[b].push_back({ a,c });
	}
	for (int i = 1; i <= V; i++) dist[i] = 1e9;
	dist[1] = 0;
	pq.push({ 1,0 });
	while (!pq.empty()) {
		info p = pq.top(); pq.pop();
		if (p.d != dist[p.n]) continue;
		for (pii a : vt[p.n]) {
			if (dist[a.first] > p.d + a.second) {
				dist[a.first] = p.d + a.second;
				pq.push({ a.first,dist[a.first] });
			}
		}
	}
	pq.push({ V,dist[V] });
	visit[V] = 1;
	while (!pq.empty()) {
		info p = pq.top(); pq.pop();
		for (pii a : vt[p.n]) {
			if (dist[p.n] == dist[a.first] + a.second) {
				pq.push({ a.first,dist[a.first] });
				visit[a.first] = 1;
			}
		}
	}
	if (visit[P]) {
		cout << "SAVE HIM";
	}
	else cout << "GOOD BYE";
}