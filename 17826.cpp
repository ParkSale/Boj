#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, arr[55];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 1; i <= 50; i++) cin >> arr[i];
	cin >> N;
	for (int i = 1; i <= 50; i++) {
		if (arr[i] == N) {
			if (i <= 5) cout << "A+";
			else if (i <= 15) cout << "A0";
			else if (i <= 30) cout << "B+";
			else if (i <= 35) cout << "B0";
			else if (i <= 45)cout << "C+";
			else if (i <= 48) cout << "C0";
			else cout << "F";
			break;
		}
	}
}