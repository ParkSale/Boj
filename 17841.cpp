#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int mod = 1000000007;
long long N, dp[100005][6];
string str = "UNIST";
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int k = 0; k < s.length(); k++) {
			if (s[k] == str[k]) {
				dp[i][k + 1] = 1;
			}
			else break;
		}
		if (s[0] == 'U') {
			dp[i][1] += dp[i - 1][0];
			if (s[1] == 'N') {
				dp[i][2] += dp[i - 1][0];
				if (s[2] == 'I') {
					dp[i][3] += dp[i - 1][0];
					if (s[3] == 'S') {
						dp[i][4] += dp[i - 1][0];
						if (s[4] == 'T') {
							dp[i][5] += dp[i - 1][0];
						}
					}
				}
			}
		}
		else if (s[0] == 'N') {
			dp[i][2] += dp[i - 1][1];
			if (s[1] == 'I') {
				dp[i][3] += dp[i - 1][1];
				if (s[2] == 'S') {
					dp[i][4] += dp[i - 1][1];
					if (s[3] == 'T') {
						dp[i][5] += dp[i - 1][1];
					}
				}
			}
		}
		else if (s[0] == 'I') {
			dp[i][3] += dp[i - 1][2];
			if (s[1] == 'S') {
				dp[i][4] += dp[i - 1][2];
				if (s[2] == 'T') {
					dp[i][5] += dp[i - 1][2];
				}
			}
		}
		else if (s[0] == 'S') {
			dp[i][4] += dp[i - 1][3];
			dp[i][4] %= mod;
			if (s[1] == 'T') {
				dp[i][5] += dp[i - 1][3];
			}
		}
		else if (s[0] == 'T') {
			dp[i][5] += dp[i - 1][4];
			dp[i][5] %= mod;
		}
		for (int k = 0; k <= 5; k++) {
			dp[i][k] += dp[i - 1][k];
			dp[i][k] %= mod;
		}
	}
	cout << dp[N][5];
}