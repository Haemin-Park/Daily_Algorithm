#include <iostream>
using namespace std;

using ll=long long;

int main(){
	ll n,k;
	cin>>n>>k;
	
	ll left=0, right=n;
	while(left<=right){
		ll mid=(left+right)/2;
		ll v=mid;
		ll h=n-v;
		ll tmp=(v+1)*(h+1);
		
		if(tmp==k){
			cout<<"YES";
			return 0;
		}else if(tmp>k){
			left=mid+1;
		}else if(tmp<k){
			right=mid-1;
		}
	}
	cout<<"NO";
}
