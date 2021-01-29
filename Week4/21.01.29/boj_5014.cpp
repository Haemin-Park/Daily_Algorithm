#include <iostream>
#include <queue>
using namespace std;

int f,s,g,u,d,result=-1;
bool visit[1000001]={false};
int cnt[1000001]={0};
queue<int> q;

void bfs(){
	while(!q.empty()){
		int x=q.front();
		q.pop();

		if(x==g){
			result=cnt[g];
			return;
		}
		else{
			int nx=x+u;
			if(!visit[nx]&&nx<=f){
				visit[nx]=true;
				cnt[nx]=cnt[x]+1;
				q.push(nx);
			}
			nx=x-d;
			if(!visit[nx]&&nx>=1){
				visit[nx]=true;
				cnt[nx]=cnt[x]+1;
				q.push(nx);
			}
		}
	}
}

int main(){
	cin>>f>>s>>g>>u>>d;
	q.push(s);
	visit[s]=true;
	bfs();
	if(result!=-1)
		cout<<result;
	else
		cout<<"use the stairs";
}
