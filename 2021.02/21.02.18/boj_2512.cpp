#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long sum=0;
	int n;
	cin>>n;
	long long arr[10001];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	sort(arr,arr+n);
	int minn=arr[0];
	int maxn=arr[n-1];
	int m;
	cin>>m;
	if(sum<=m){
		cout<<arr[n-1];
		return 0;
	}
	long long result=0;
	long long left=1,right=maxn;
	while(left<=right){
		long long mid=(left+right)/2;
		sum=0;
		for(int i=0;i<n;i++){
			if(arr[i]<mid) sum+=arr[i];
			else
				sum+=mid;
		}
		if(sum==m){
			result=max(mid,result);
			cout<<result;
			return 0;
		}
		else if(sum>m){
			right=mid-1;
		}else if(sum<m){
			result=max(mid,result);
			left=mid+1;
		}
	}
	
	cout<<result;
}
