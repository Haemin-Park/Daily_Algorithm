#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using ll = long long;

vector<pair<ll,ll>> p;

bool cmp(pair<ll,ll> a, pair<ll,ll> b){
	return a.first > b.first;
}

int main(){
	int n,m;
	cin>>n>>m;
	ll x,y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		if(x>y)
			p.push_back({x,y});
	}
	ll dis=1LL*m;
	if(!p.empty()){
		sort(p.begin(),p.end(),cmp);
		ll rright=p[0].first;
		ll rleft=p[0].second;	
	
		for(int i=1;i<p.size();i++){

			if(p[i].first>=rleft){	
				rleft=min(rleft,p[i].second);
			}
			else
			{
				dis+=2LL*(rright-rleft);
				rright=p[i].first;
				rleft=p[i].second;
			}
			
		}
		
		dis+=2LL*(rright-rleft);
	}
	
	cout<<dis;
}
