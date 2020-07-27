#include <bits/stdc++.h>
using namespace std;
int N, M, state[100005], ans[100005], ans2[100005], visitP[100005];
vector<int> group[100005], person[100005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= M; ++i) {
		int k;
		cin >> k;
		while (k--) {
			int n;
			cin >> n;
			group[i].push_back(n);
			person[n].push_back(i);
		}
	}
	for (int i = 1; i <= N; ++i) {
		ans[i] = 1;
		ans2[i] = 1;
		cin >> state[i];
	}
	//visitP�� n���׷���� 0���� ����Ǵ� ��ȣ
	for (int i = 1; i <= N; ++i) {
		//i������� ������ ������ �׷� ��ȣ�� person[i][person[i].size()-1]
		if (state[i] == 0) {
			if (person[i].size() == 0) {
				ans[i] = state[i];
				ans2[i] = state[i];
				continue;
			}
			visitP[i] = person[i][person[i].size() - 1];
			for (int n : person[i]) {
				for (int nn : group[n]) {
					visitP[nn] = max(visitP[nn], visitP[i]);
				}
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (visitP[i] != 0) {
			//i�� ����� ���ʰ����ڰ� �ƴϾ���ϴ� ���
			for (int n : person[i]) {
				//i�� ����� �����ִ� �׷�� ��
				if (visitP[i] >= n) {
					for (int nn : group[n]) {
						ans[nn] = 0;
						ans2[nn] = 0;
					}
				}
			}
		}
	}
	//ans�� ������ ����
	for (int i = 1; i <= M; ++i) {
		bool flag = 0;
		for (int n : group[i]) {
			if (ans[n]) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			for (int n : group[i]) {
				ans[n] = 1;
			}
		}
	}
	bool flag = 0;
	for (int i = 1; i <= N; ++i) {
		if (ans[i] != state[i]) flag = 1;
	}
	if (flag) {
		cout << "NO";
	}
	else {
		cout << "YES\n";
		for (int i = 1; i <= N; ++i) cout << ans2[i] << " ";
	}
}
