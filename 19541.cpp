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
	//visitP는 n번그룹까지 0임이 보장되는 번호
	for (int i = 1; i <= N; ++i) {
		//i번사람이 참여한 마지막 그룹 번호는 person[i][person[i].size()-1]
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
			//i번 사람이 최초감염자가 아니어야하는 경우
			for (int n : person[i]) {
				//i번 사람이 속해있는 그룹들 중
				if (visitP[i] >= n) {
					for (int nn : group[n]) {
						ans[nn] = 0;
						ans2[nn] = 0;
					}
				}
			}
		}
	}
	//ans를 가지고 진행
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
