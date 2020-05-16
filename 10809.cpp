#include <bits/stdc++.h>
using namespace std;
int A[26];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string S;
	cin >> S;
	for (int i = 0; i < 26; i++) A[i] = -1;
	for (int i = 0; i < S.length(); i++) {
		if (A[S[i] - 'a'] == -1) A[S[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++) {
		cout << A[i] << " ";
	}
}