#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, m, input;
	vector<int> v1;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		v1.push_back(input);
	}
	sort(v1.begin(), v1.end());
	
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &input);
		if (binary_search(v1.begin(), v1.end(), input))
			printf("1\n");
		else
			printf("0\n");
	}
}
