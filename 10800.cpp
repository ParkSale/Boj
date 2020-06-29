#include <bits/stdc++.h>
using namespace std;
struct info {
	int c, s, idx;
	bool operator <(const info& a) const {
		return s < a.s;
	}
}I[200005];
int N, v[200005], vv[2005], ans[200005];
map<pair<int, int>, int> mp;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	int total = 0;
	for (int i = 1; i <= N; ++i) {
		int a, b;
		cin >> a >> b;
		I[i] = { a,b,i };
	}
	sort(I + 1, I + N + 1);
	int t = 0;
	for (int i = 1; i <= N; ++i) {
		//������ ���� �� �� ���� ���ڻ��� ���� ���� ����
		//���� ���ڸ鼭 ���� �����ξִ� �����ְ�
		//���� ���ڿ� �������Դ� O(1)�� ���� ����
		//���� �����̸鼭 ���� �����ξִ� ���� ����?
		//t�� ������ �����ֵ� �� ��
		ans[I[i].idx] = t - v[I[i].c] - vv[I[i].s] + mp[{I[i].c, I[i].s}];
		t += I[i].s;
		v[I[i].c] += I[i].s;
		vv[I[i].s] += I[i].s;
		mp[{I[i].c, I[i].s}] += I[i].s;
	}
	for (int i = 1; i <= N; ++i) cout << ans[i] << "\n";
}