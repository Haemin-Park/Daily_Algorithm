#include <iostream>
#include <algorithm>
using namespace std;

int n,m,r; // 행,열,라운드횟수
int arr[101][101];
bool isAttacked[101][101]={false};

int attack(int x, int y, char d){
	int cnt=0, tmp=0;
	
	while(1){
		if(!isAttacked[y][x]){
			isAttacked[y][x]=true;
			cnt++;
			tmp=max(tmp-1,arr[y][x]-1);
		}else{
			tmp--;
		}

		if(tmp<=0)
			break;
		
		if(d=='E'){
			x++;
		}else if(d=='W'){
			x--;
		}else if(d=='S'){
			y++;
		}else if(d=='N'){
			y--;	
		}
		
		if(x<1||x>m||y<1||y>n)
			break;
	}
	return cnt;
}

int main(){
	
	cin>>n>>m>>r;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>arr[i][j];
		}
	}
	
	int cnt=0;
	while(r--){
		int x,y;
		char d;
		cin>>y>>x>>d;
		cnt+=attack(x,y,d);
		cin>>y>>x;
		isAttacked[y][x]=false;
	}
	cout<<cnt<<"\n";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(isAttacked[i][j])
				cout<<"F ";
			else
				cout<<"S ";
		}
		cout<<"\n";
	}
}
