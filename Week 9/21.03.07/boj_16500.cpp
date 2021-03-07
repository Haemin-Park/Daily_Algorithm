#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
string s, tmp;
vector<string> a;
int found[101] = { 0 };

void find(int pos) {
	if (pos == s.size()) {
		return ;
	}
	bool isSuc;
	for (int i = 0; i < a.size(); i++) {
		isSuc = true;
		for (int j = 0; j < a[i].size(); j++) {
			if (s[pos + j] != a[i][j]) {
				isSuc = false;
				break;
			}
		}
		if (isSuc && !found[pos + a[i].size() - 1]) {
			found[pos + a[i].size() - 1] = 1;
			find(pos + a[i].size());
		}
	}
}

int main() {
	cin >> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		a.push_back(tmp);
	}
	find(0);
	cout << found[s.size() - 1];
}
