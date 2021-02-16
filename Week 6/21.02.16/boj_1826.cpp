#include <iostream>
#include <algorithm>
#include <queue>
#define maxn 1000001
using namespace std;

int n,L,P,gas,pos;
int arr[maxn]={0};
bool visit[maxn]={false};
int cnt=0;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	int a,b;
	priority_queue<pair<int,int>> q1,q2;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		arr[a]=b;
		q1.push({-a,b});
	}
	cin>>L>>P;
	
	pos=0;
	gas=P;
	while(1){
		if(pos+gas>=L){
			cout<<cnt;
			break;
		}
		
		while(1){
			if(!q1.empty()&&-1*q1.top().first<=pos+gas){
				q2.push({q1.top().second,-1*q1.top().first});
					q1.pop();
			}else{
				break;
			}
		}

		if(q2.empty()){
			cout<<-1;
			return 0;
		}else{
			gas=gas+q2.top().first-(q2.top().second-pos);
			pos=q2.top().second;
			q2.pop();
			cnt++;
		}
	}
}
