#include <iostream>
#include <algorithm>
#include <string>
#define MAX 15
using namespace std;
int l, c;
char arr[MAX];

void pick(int index, string s, bool c1, int c2) {
	if (s.size() == l) {
		if(c1 && c2 >= 2)
			cout << s << '\n';
	}
	else {
		for (int i = index; i < c; i++) {
			if(arr[i]=='a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
				pick(i + 1, s + arr[i], true, c2);
			else
				pick(i + 1, s + arr[i], c1, c2 + 1);
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		char input;
		cin >> input;
		arr[i] = input;
	}
	sort(arr, arr + c);
	pick(0, "", false, 0);
}
