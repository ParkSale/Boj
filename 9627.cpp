#include <bits/stdc++.h>
using namespace std;
int a[] = { 0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8 };
int N;
vector<int> vt;
string s[] = { "","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifthteen","sixteen","seventeen","eighteen","nineteen" };
string ss[] = { "","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety" };
string sss[] = { "","onehundred","twohundred","threehundred","fourhundred","fivehundred","sixhundred","sevenhundred","eighthundred","ninehundred" };
string str[250];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	int v = 0;
	for (int i = 1; i <= N; i++) {
		cin >> str[i];
		if (str[i] != "$") {
			v += str[i].length();
		}
	}
	vt.push_back(0);
	for (int i = 1; i <= 999; i++) {
		if ((i % 100) >= 20) {
			vt.push_back(sss[i / 100].length() + ss[(i % 100) / 10].length() + s[i % 10].length());
			//cout << sss[i / 100] + ss[(i % 100) / 10] + s[i % 10];
		}
		else {
			vt.push_back(sss[i / 100].length() + s[i % 100].length());
			//cout << sss[i / 100] + s[i % 100];
		}
		//cout << " " << vt[i] << "\n";
	}
	for (int i = 1; i <= 999; i++) {
		if (v + vt[i] == i) {
			for (int k = 1; k <= N; k++) {
				if (str[k] != "$") {
					cout << str[k] << " ";
				}
				else {
					cout << sss[i / 100];
					if ((i % 100) >= 20) {
						cout << ss[(i % 100) / 10];
						cout << s[i % 10] << " ";
					}
					else {
						cout << s[(i % 100)] << " ";
					}
				}
			}
			break;
		}
	}
}