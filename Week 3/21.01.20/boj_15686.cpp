#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, min_dis = 100000;
int arr[50][50] = { 0 };
vector<pair<int, int>> p(3000);
vector<pair<int, int>> house;
vector<pair<int, int>> c;

void pick(int cnt, int index) {
	if (cnt == m) {
		int ms = 1000;
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			for (int j = 0; j < m; j++) {
				int dis = abs(house[i].first - p[j].first) + abs(house[i].second - p[j].second);
				ms = min(dis, ms);
			}
			sum += ms;
			ms = 1000;
		}
		min_dis = min(sum, min_dis);
	}
	else {
		for (int i = index; i < c.size(); i++) {
			p[cnt] = make_pair(c[i].first, c[i].second);
			pick(cnt + 1, i + 1);
		}
	}
}

int main() {
	int input;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input;
			arr[i][j] = input;
			if (input == 1)
				house.push_back(make_pair(j, i));
			if (input == 2)
				c.push_back(make_pair(j, i));
		}
	}
	
	pick(0, 0);

	cout << min_dis;
}
