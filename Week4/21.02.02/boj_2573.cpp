#include <iostream>
#include <queue>
#include <map>
#include <cstring>
#define maxn 301
using namespace std;
int n,m;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool visit[maxn][maxn]={false};
int arr[maxn][maxn]={0};
queue<pair<int,int>> q;
map<pair<int,int>,int> ice;
int cnt=0, result=0;
bool findResult=false;

void bfs(){
	int ic=0;
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		ic++;
		int water=0;
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<0||nx>=m||ny<0||ny>=n)
				continue;
			
			if(arr[ny][nx]==0)
				water++;
			if(!visit[ny][nx]&&arr[ny][nx]!=0){
				q.push(make_pair(nx,ny));
				visit[ny][nx]=true;
			}
		}
		ice[{x,y}]-=water;
	}
	map<pair<int,int>,int>::iterator iter=ice.begin();
	while(iter!=ice.end()){
		
		if((*iter).second<=0){
			arr[(*iter).first.second][(*iter).first.first]=0;	
			ice.erase(iter++);
			ic--;
		}
		else{
			iter++;
		}
	}
	cnt++;
	if(ice.size()!=ic){
		result=cnt;
		findResult=true;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			if(arr[i][j]!=0){
				ice[{j,i}]=arr[i][j];
			}
		}
	}
	
	map<pair<int,int>,int>::iterator iter;
	pair<int,int> f;
	
	while(!ice.empty()){
		iter=ice.begin();
		f=(*iter).first;
		q.push(make_pair(f.first,f.second));
		visit[f.second][f.first]=true;
		bfs();
		if(findResult)
			break;
		memset(visit,false,sizeof(visit));
	}
	if(findResult)
		cout<<result-1;
	else
		cout<<0;
}
