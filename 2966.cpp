#include <bits/stdc++.h>
using namespace std;
string A = "ABC";
string B = "BABC";
string C = "CCAABB";
int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	string S;
	cin >> N >> S;
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == A[i % A.length()]) a++;
		if (S[i] == B[i % B.length()]) b++;
		if (S[i] == C[i % C.length()]) c++;
	}
	int v = max({ a,b,c });
	vector<string> vt;
	if (v == a) {
		vt.push_back("Adrian");
	}
	if (v == b) {
		vt.push_back("Bruno");
	}
	if (v == c) {
		vt.push_back("Goran");
	}
	cout << v << "\n";
	for (string s : vt) {
		cout << s << "\n";
	}
}