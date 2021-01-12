#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

bool visit[MAX] = { false };
int t[MAX] = { 0 };
int n, k;

void bfs() {
	queue<int> q;
	q.push(n); // n: 수빈이 위치
	visit[n] = true;
	t[n] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == k)
			return;

		if (x - 1 >=0 && !visit[x - 1]) {
			q.push(x - 1);
			visit[x - 1] = true;
			t[x - 1] = t[x] + 1;
		}

		if (x + 1 < MAX && !visit[x + 1]) {
			q.push(x + 1);
			visit[x + 1] = true;
			t[x + 1] = t[x] + 1;
		}

		if (x * 2 < MAX && !visit[x * 2]) {
			q.push(x * 2);
			visit[x * 2] = true;
			t[x * 2] = t[x] + 1;
		}

	}
	
}

int main() {
	cin >> n >> k;
	bfs();
	cout << t[k];
}
