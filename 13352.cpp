#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N;
pii arr[100005];
vector<pii> vt, tmp;
int gcd(int a, int b) {
	int c = 1;
	while (c != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
pii cal(pii a, pii b) {
	int v1 = a.first - b.first, v2 = a.second - b.second;
	if (v1 == 0) {
		return { 0,1 };
	}
	else if (v2 == 0) {
		return { 1,0 };
	}
	int g = gcd(v1, v2);
	return { v1 / g,v2 / g };
}
bool isSame(pii a, pii b, pii c) {
	if (cal(a, b) == cal(b, c)) {
		return 1;
	}
	return 0;
}
bool chk(pii a, pii b) {
	//a와 b를 가지고 직선만들어졌음
	//vt안에 있는 애들로 판별Go
	for (pii p : vt) {
		//같은 직선인지 판별
		if (isSame(a, b, p)) {
			continue;
		}
		else {
			if (tmp.size() >= 2) {
				if (isSame(tmp[0], tmp[1], p)) {
					continue;
				}
				else {
					return 0;
				}
			}
			else {
				tmp.push_back(p);
			}
		}
	}
	return 1;
}
void init(int a, int b) {
	vt.clear();
	tmp.clear();
	for (int i = 1; i <= N; ++i) {
		if (i == a || i == b) continue;
		vt.push_back(arr[i]);
	}
	if (chk(arr[a], arr[b])) {
		cout << "success";
		exit(0);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		int a, b;
		cin >> a >> b;
		arr[i] = { a,b };
	}
	if (N <= 2) {
		cout << "success";
		return 0;
	}
	init(1, 2);
	init(1, 3);
	init(2, 3);
	cout << "failure";
}