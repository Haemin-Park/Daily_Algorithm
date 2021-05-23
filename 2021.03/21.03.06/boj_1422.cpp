#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp1(string s1, string s2) {
	return s1 + s2 < s2 + s1;
}

bool cmp2(string s1, string s2) {
	if (s1.size() != s2.size()) {
		return s1.size() > s2.size();
	}
	else {
		return s1 > s2;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k, n;

	vector<string> v;
	cin >> k >> n;
	string input;
	for (int i = 0; i < k; i++) {
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end(), cmp2);
	string maxs = v[0]; // 제일 긴 것중 제일 큰 문자열
	
	sort(v.begin(), v.end(), cmp1);
	string s = "";
	bool isAdd = false;
	for (int i = 0; i < k; i++) {
		if (v[i] == maxs && !isAdd) {
			for (int j = k; j < n; j++) {
				s = maxs + s;
			}
			isAdd = true;
		}
		s = v[i] + s;
	}
	cout << s;
}
