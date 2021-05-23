#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	double x, y, c;
	cin >> x >> y >> c;

	double left = 0.0, right = min(x, y);
	double result = 0.0;
	while (right - left > 0.000001) {
		double mid = (left + right) / 2.0;

		double h1 = sqrt(x * x - mid * mid);
		double h2 = sqrt(y * y - mid * mid);
		double nc = (h1 * h2) / (h1 + h2);

		if (nc >= c) {
			result = mid;
			left = mid;
		}
		else {
			right = mid;
		}
	}
	printf("%.3f", result);
}
