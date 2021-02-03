#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string,string> m;
unordered_map<string,int> network;

string find(string s){
	if(s==m[s]) return s;
	else return find(m[s]);
}

void merge(string u, string v){
	u=find(u);
	v=find(v);
	if(u!=v){ 
		if(network[u]<network[v]){
			m[u]=v;
			network[v]+=network[u];
		}else{
			m[v]=u;
			network[u]+=network[v];
		}
		
	}
}

int n,f;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	string n1,n2;
	for(int i=0;i<n;i++){
		cin>>f;
		for(int j=0;j<f;j++){
			cin>>n1>>n2;
			if(m.find(n1)==m.end()){
				m[n1]=n1;
				network[n1]=1;
			}
			if(m.find(n2)==m.end()){
				m[n2]=n2;
				network[n2]=1;
			}
			merge(n1,n2);
			cout<<network[find(n1)]<<"\n";
		}
		m={};
		network={};
	}
}
