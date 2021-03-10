#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check[1001] = { false };

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second != p2.second) {
		return p1.second > p2.second;
	}
	else {
		p1.first < p1.first;
	}
}

int main() {
	int n;
	cin >> n;
	vector <pair<int, int>> h;
	int i1, i2;
	for (int i = 0; i < n; i++) {
		cin >> i1 >> i2;
		h.push_back({ i1,i2 });
	}
	sort(h.begin(), h.end(), cmp);
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = h[i].first; j >= 1; j--) {
			if (!check[j]) {
				check[j] = true;
				result += h[i].second;
				break;
			}
		}
	}
	cout << result;
}
