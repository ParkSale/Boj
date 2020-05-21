using namespace std;
#include <string>
#include <iostream>
#include <algorithm>
#include <deque>
int k;
deque<int> dq;
deque<int>::iterator iter;
int num;
int arr[9];
bool visit[9] = { false };
void permutation(int n, int m) {
	if (n == k) {
		for (iter = dq.begin(); iter != dq.end(); iter++) {
			cout << *iter << " ";
		}
		cout << "\n";
		return;
	}
	else {
		for (int i = m; i <= num; i++) {
			if (visit[i] == false) {
				dq.push_back(arr[i]);
				visit[i] = true;
				permutation(n + 1, i);
				dq.pop_back();
				visit[i] = false;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> num >> k;
	for (int i = 1; i <= num; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + num + 1);
	permutation(0, 1);

}