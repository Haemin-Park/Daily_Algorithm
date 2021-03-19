#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	double n,m,l;
	cin>>n>>m>>l;
	
	double input;
	vector<double> v;
	for(int i=0;i<n;i++){
		cin>>input;
		v.push_back(input);
	}
	sort(v.begin(),v.end());
	
	priority_queue<pair<double,double>> dis;
	dis.push({v[0],0});
	for(int i=1;i<n;i++){
		dis.push({v[i]-v[i-1],0});
	}
	dis.push({l-v[n-1],0});
	
	while(m){
		pair<double,double> mdis=dis.top();
		dis.pop();
		dis.push({(mdis.first*(mdis.second+1))/(mdis.second+2),mdis.second+1});
		m--;
	}
	
	double result = dis.top().first!=floor(dis.top().first)?floor(dis.top().first)+1.0:dis.top().first;
	cout<<result;
	
}
