using namespace std;
#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <list>
int arr[9];
bool used[9] = { false };
int a, b;
list<int> lt;
list<int>::iterator iter;
void combi(int k) {
	if (k == b) {
		for (iter = lt.begin(); iter != lt.end(); iter++) {
			cout << *iter << " ";
		}
		cout << "\n";
		return;
	}
	bool check[10001] = { false };
	for (int i = 1; i <= a; i++) {
		if (used[i] == false && check[arr[i]] == false) {
			used[i] = true;
			check[arr[i]] = true;
			lt.push_back(arr[i]);
			combi(k + 1);
			used[i] = false;
			lt.pop_back();
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + a + 1);
	combi(0);
}