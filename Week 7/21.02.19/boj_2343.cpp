#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m; // 레슨의 수, 블루레이 수
	cin>>n>>m;
	int maxn=0, sumn=0;
	int arr[100001];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sumn+=arr[i];
		if(maxn<arr[i]) maxn=arr[i];
	}
	int result=sumn+1;
	int left=maxn,right=sumn;
	while(left<=right){
		int mid=(left+right)/2;
		int tmp=0,cnt=1;
		for(int i=0;i<n;i++){
			if(tmp+arr[i]<=mid){
				tmp+=arr[i];
			}else{
				tmp=arr[i];
				cnt++;
			}
		}
		
		if(cnt<=m){
			result=min(result,mid);
			right=mid-1;
		}else if(cnt>m){
			left=mid+1;
		}
	}
	cout<<result;
}
