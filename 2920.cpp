#include <bits/stdc++.h>
using namespace std;
int arr[10];
int main(int argc, char* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 1; i <= 8; i++) {
		cin >> arr[i];
	}
	bool a = 0, b = 0;
	for (int i = 2; i <= 8; i++) {
		if (arr[i] > arr[i - 1]) {
			a = 1;
			break;
		}
	}
	for (int i = 2; i <= 8; i++) {
		if (arr[i] < arr[i - 1]) {
			b = 1;
			break;
		}
	}
	if (a && !b) cout << "ascending";
	else if (!a && b) cout << "descending";
	else cout << "mixed";
}