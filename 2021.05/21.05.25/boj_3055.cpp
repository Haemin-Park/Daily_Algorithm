#include <iostream>
#include <queue>
using namespace std;

int r,c;
char arr[50][50];
int visit[50][50];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
queue<pair<int,int>> q;
queue<pair<int,int>> w;

void bfs(){
	while(!q.empty()){
		if(!w.empty()){
			int wcnt=w.size();
			for(int i=1;i<=wcnt;i++){
				int wx=w.front().first;
				int wy=w.front().second;
				w.pop();
				
				for(int i=0;i<4;i++){
					int wnx=wx+dx[i];
					int wny=wy+dy[i];
					
					if(wnx<0||wnx>=c||wny<0||wny>=r)
						continue;
					
					if(arr[wny][wnx]=='.'){
						arr[wny][wnx]='*';
						w.push({wnx,wny});
					}
				}
			}
		}
		
		int qcnt=q.size();
		for(int i=1;i<=qcnt;i++){
			int qx=q.front().first;
			int qy=q.front().second;
			q.pop();
			
			for(int j=0;j<4;j++){
				int qnx=qx+dx[j];
				int qny=qy+dy[j];
				
				if(arr[qny][qnx]=='D'){
					cout<<visit[qy][qx]+1;
					return;
				}
				
				if(qnx<0||qnx>=c||qny<0||qny>=r)
					continue;
				
				if(visit[qny][qnx]==-1 && arr[qny][qnx]=='.'){
					visit[qny][qnx]=visit[qy][qx]+1;
					q.push({qnx,qny});
				}
			}
		}
	}	
	
	cout<<"KAKTUS";
	return;
}

int main(){
	cin>>r>>c;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			visit[i][j]=-1;
			cin>>arr[i][j];
			if(arr[i][j]=='S'){
				q.push({j,i});
				visit[i][j]=0;
			}
			if(arr[i][j]=='*'){
				w.push({j,i});
			}
		}
	}
	bfs();
}
