#include <iostream>
using namespace std;

int city[201];

int find(int x){
	if(x==city[x]) return x;
	else
		return find(city[x]);
}

void merge(int u, int v){
	u=find(u);
	v=find(v);
	
	if(u!=v) city[u]=v;
}

int main(){
	int n,m; // n: 도시의 수, m: 여행 계획에 속한 도시의 수
	cin>>n;
	cin>>m;
	
	for(int i=1;i<=n;i++) city[i]=i;
	
	int input;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>input;
			if(input==1)
				merge(i,j);
		}
	}
	
	int start;
	cin>>start;
	for(int i=1;i<m;i++){
		cin>>input;
		if(find(start)!=find(input)){
			cout<<"NO";
			return 0;
		}
		start=input;
	}
	cout<<"YES";
}
