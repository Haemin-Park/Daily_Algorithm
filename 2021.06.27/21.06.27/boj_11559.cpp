#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int result=0;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
queue<pair<int,int>> q;
char f[12][6];
bool visit[12][6]={false};
bool poped=false;

void bfs(char c){
	int cnt=1;
	
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(nx<0 || nx>=6 || ny<0 ||ny>=12)
				continue;
			
			if(!visit[ny][nx] && f[ny][nx]==c){
				visit[ny][nx]=true;
				cnt++;
				q.push({nx,ny});
			}
		}
	}
	
	if(cnt>=4){
		poped=true;
		for(int i=0;i<12;i++){
			for(int j=0;j<6;j++){
				if(visit[i][j]){
					f[i][j]='.';
				}
			}
		}
	}
}

int main(){
	for(int i=0;i<12;i++){
		for(int j=0;j<6;j++){
			cin>>f[i][j];
		}
	}
	
	bool isEnd=false;
	
	while(!isEnd){
	
		int i, j;
		poped=false;
		
		for(i=11;i>=0;i--){
			for(j=0;j<6;j++){
				if(f[i][j]!='.'){
					q={};
					memset(visit, false, sizeof(visit));
					q.push({j,i});
					visit[i][j]=true;
					bfs(f[i][j]);
				}
			}
		}
		
		if(poped){
			result++;
			for(int i=0;i<6;i++){
				for(int j=0;j<11;j++){
					if(f[j][i]!='.' && f[j+1][i]=='.'){
						for(int k=j+1;k>0;k--){
							f[k][i]=f[k-1][i];
						}
						f[0][i]='.';
					}
				}
			}
		}else{
			isEnd=true;
		}
	}
	
	cout<<result;
}
