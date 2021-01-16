#include <iostream>
#include <deque>
using namespace std;

int num, pick_cnt;
deque<int> d;
int a[50];

int header = 0, p = 0, cnt = 0;
int n;

int r(int c){
	d.push_front(d.back());
	d.pop_back();
	c++;
	if (d[header] == a[p]) {
		d.pop_front();
		return c;
	}
	else {
		return r(c);
	}
}

int main() {

	int rc;
	cin >> num >> pick_cnt;

	for (int i = 1; i <= num; i++) {
		d.push_back(i);
	}

	for (int i = 0; i < pick_cnt; i++) {
		cin >> n;
		a[i] = n;
	}

	while (p != pick_cnt) {
		if (d[header] == a[p]) {
			d.pop_front();
			p++;
		}
		else {
			rc = r(0);
			if (rc <= (d.size() + 1) / 2)
				cnt += rc;
			else {
				cnt += (d.size()+1) - rc; // lc
			}
			p++;
		}
	}

	cout << cnt;
	
	return 0;
}
