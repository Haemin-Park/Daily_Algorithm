#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#define result 123456789
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
queue<int> q;
map<string, int> m;

void bfs(){
	while(!q.empty()){
		int num=q.front();
		q.pop();
		
		if(num==result){
			return;
		}
		
		string s=to_string(num);
		int index=s.find('9');
		int x=index%3;
		int y=index/3;
		
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(nx<0||nx>=3||ny<0||ny>=3)
				continue;
			
			string tmp=s;
			swap(tmp[index],tmp[3*ny+nx]);
			
			if(m.find(tmp)==m.end()){
				q.push(stoi(tmp));
				m[tmp]=m[s]+1;
			}
		}
	}
}

int main(){
	int num=0,n;
	for(int i=0;i<9;i++){
		cin>>n;
		if(n==0) n=9;
		num=num*10+n; // 입력을 하나의 숫자로 만듦 ex 193425786
	}
	q.push(num);
	m[to_string(num)]=0;
	bfs();
	if(m.find(to_string(result))!=m.end())
		cout<<m[to_string(result)];
	else
		cout<<-1;
		
}
