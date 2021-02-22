#include <iostream>
#include <algorithm>
using namespace std;

pair<int,int> arr[1000001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	int x,y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		arr[i]={x,y};
	}
	sort(arr,arr+n);
	
	int left=arr[0].first,right=arr[0].second;
	int len=0;
	for(int i=1;i<n;i++){
		if(right<arr[i].first){
			len+=abs(right-left);
			left=arr[i].first;
			right=arr[i].second;
		}else if(right<arr[i].second){
			right=arr[i].second;
		}
	}
	
	cout<<len+abs(right-left);
}
