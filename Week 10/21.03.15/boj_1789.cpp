#include <iostream>
#include <algorithm>
using namespace std;

using ll=long long;

int main(){
	ll s;
	cin>>s;
	
	ll left=1,right=s;
	ll result=0;
	while(left<=right){
		ll mid=(left+right)/2;
		ll sum=0;
		for(int i=1;i<=mid;i++){
			sum+=i;
		}
		if(sum<=s){
			left=mid+1;
			result=max(result,mid);
		}else{
			right=mid-1;
		}
	}
	cout<<result;
}
