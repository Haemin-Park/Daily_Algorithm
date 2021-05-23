#include <iostream>
#include <vector>
#define MAX_NODE 100
using namespace std;

vector<int> g[MAX_NODE + 1];
bool visit[MAX_NODE + 1] = {false,};
int cnt;

void dfs(int start) {
	
	cnt++;
	
	visit[start] = true;
	
	for (int i = 0; i < g[start].size(); i++) {
		int next = g[start][i];
		if (!visit[next]) {
			dfs(next);
		}
	}
}

int main() {
	int n, connect;
	int input1, input2;
	
	cin >> n >> connect;
	
	for (int i = 0; i < connect; i++) {
		cin >> input1 >> input2;
		g[input1].push_back(input2);
		g[input2].push_back(input1);
	}

	dfs(1);
	
	cout << cnt - 1;
}
