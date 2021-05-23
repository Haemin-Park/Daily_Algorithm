#include <iostream>
#include <vector>
using namespace std;

int arr[9][9];
vector<pair<int,int>> v;

bool isPossible(int idx, int num){
	int x=v[idx].first;
	int y=v[idx].second;

	for(int i=0;i<9;i++){
		if(arr[y][i]==num) return false; // 가로줄 검사
		if(arr[i][x]==num) return false; // 세로줄 검사
	}
	
	int tx=(x/3)*3;
	int ty=(y/3)*3;
	for(int i=0;i<=2;i++){
		for(int j=0;j<=2;j++){
			if(arr[ty+i][tx+j]==num) return false; // 3x3 검사
		}
	}

	return true;
}

void solution(int idx){
	if(idx==v.size()){
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++)
				cout<<arr[i][j]<<" ";
			cout<<endl;
		}
		exit(0);
	}
	else{
		for(int i=1;i<=9;i++){
			if(isPossible(idx,i)){
				int x=v[idx].first;
				int y=v[idx].second;
				arr[y][x]=i;
				solution(idx+1);
				arr[y][x]=0;
			}
		}
	}
}

int main(){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin>>arr[i][j];
			if(arr[i][j]==0){
				v.push_back({j,i});
			}
		}
	}
	solution(0);
}
