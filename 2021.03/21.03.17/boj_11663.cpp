#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
int p[100001];

double solution(int x) {
	double result = 0;
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;

		if (x == p[mid]) {
			return mid;
			break;
		}
		else if (x < p[mid]) {
			result = mid - 0.5;
			right = mid - 1;
		}
		else if (x > p[mid]) {
			result = mid + 0.5;
			left = mid + 1;
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	sort(p, p + n);
	double a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		double left = solution(a);
		double right = solution(b);

		double start = left != floor(left) ? floor(left) + 1.0 : left;
	
		if (right - start >= 0) {
			cout << int(right - start) + 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
}
