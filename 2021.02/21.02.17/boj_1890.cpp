#include <iostream>
using namespace std;

long n;
long arr[101][101];
long long dis[101][101]={0};

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	}
	
	dis[0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(dis[i][j]==0 || i==n-1&&j==n-1) continue;
			
			long nx=j+arr[i][j]; // 오른쪽
			if(nx<n)
				dis[i][nx]+=dis[i][j];
			
			long ny=i+arr[i][j]; // 아래
			if(ny<n)
				dis[ny][j]+=dis[i][j];
		}
	}

	cout<<dis[n-1][n-1];
}
