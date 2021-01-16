#include <iostream>
using namespace std;

int main() {
	int n, k, input, cnt = 0;
	cin >> n >> k;
	int p[11];
	
	for (int i = 1; i <= n; i++) {
		cin >> input;
		p[i] = input;
	}

	for (int i = n; i >= 1; i--) {
		if (k > 0) {
			if (k / p[i] > 0) {
				cnt += k / p[i];
				k = k % p[i];
			}
		}
	}
	cout << cnt;
}
