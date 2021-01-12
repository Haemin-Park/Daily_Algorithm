#include <iostream>
using namespace std;

/*
	퀸들이 서로 공격할 수 없도록 하기위한 조건:
	퀸들끼리 가로, 세로, 대각선 일직선상 위치하지 않을때이다.
*/
int q[15];// q[row] = column 으로 저장
int n, cnt;

bool check(int row) {

	for (int i = 0; i < row; i++) {
		if (q[row] == q[i] || row - i == abs(q[row] - q[i])) // 세로, 대각선 일직선상 위치하면 false 리턴
			return false;
	}
	return true;
}

void nqueen(int row) {
	if (row == n)
		cnt++;
	else {
		for (int i = 0; i < n; i++) {
			q[row] = i;
			if (check(row))
				nqueen(row + 1); // 유효하다면 다음행의 퀸 배치
		}
	}
}

int main() {
	cin >> n;
	nqueen(0);
	cout << cnt;
}
