#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_NODE 1000
using namespace std;

vector<int> g[MAX_NODE + 1];
bool visit[MAX_NODE + 1];

void dfs(int start) {
	visit[start] = true;
	cout << start << " ";
	for (int i = 0; i < g[start].size(); i++) {
		int next = g[start][i];
		if (!visit[next])
			dfs(next);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = true;
	cout << start << " ";
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < g[x].size(); i++) {
			int next = g[x][i];
			if (!visit[next]) {
				q.push(next);
				visit[next] = true;
				cout << next << " ";
			}
		}
	}
}

int main() {
	int n, m, v;
	int input1, input2;

	cin >> n >> m >> v;
	
	for (int i = 0; i < m; i++) {
		cin >> input1 >> input2;
		g[input1].push_back(input2);
		g[input2].push_back(input1);
	}

	for (int i = 0; i < n; i++) {
		sort(g[i].begin(), g[i].end());
	}
	
	fill(visit, visit + n + 1, false);
	dfs(v);
	cout << endl;
	fill(visit, visit + n + 1, false);
	bfs(v);

}
