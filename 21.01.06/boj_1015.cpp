#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 사전순, 오름차순 
bool compare1(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

bool compare2(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first < b.first;
}

int main() {
	int n, num;
	vector<pair<int, int>> v1, v2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v1.push_back(make_pair(i, num));
	}
	sort(v1.begin(), v1.end(), compare1);

	for (int j = 0; j < n; j++) {
		v2.push_back(make_pair(v1[j].first, j));
	}
	sort(v2.begin(), v2.end(), compare2);

	for (int k = 0; k < n; k++) {
		cout << v2[k].second << " ";
	}
}
