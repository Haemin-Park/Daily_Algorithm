#include <stdio.h>
#include <unordered_map>
using namespace std;

int main() {
	int n, m, input;
	unordered_map<int, int> um;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		um[input] += 1;
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &input);
		printf("%d ", um[input]);
	}
}
