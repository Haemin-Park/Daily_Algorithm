#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n;
	cin >> k;
	vector<int> sensor, dis;
	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		sensor.push_back(input);
	}
	sort(sensor.begin(), sensor.end());
	for (int i = 0; i < n - 1; i++) {
		dis.push_back(sensor[i + 1] - sensor[i]);
	}
	sort(dis.begin(), dis.end());
	int result = 0;
	for (int i = 0; i < n - k; i++) {
		result += dis[i];
	}
	cout << result;
}
