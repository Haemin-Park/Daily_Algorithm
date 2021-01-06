#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, num;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(),v.end());
	cout << v.front() * v.back();
}
