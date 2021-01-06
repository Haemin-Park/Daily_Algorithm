#include <iostream>
using namespace std;

long long c[30][30] = { 0, };

long long combination(int n, int k) {
	if (c[n][k] > 0)
		return c[n][k];
	else if (n == k || k == 0)
		return c[n][k] = 1;
	else
		return c[n][k] = combination(n - 1, k - 1) + combination(n - 1, k);

}

int main() {
	int t, m, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		cout<< combination(m, n) << "\n";
	}

}
