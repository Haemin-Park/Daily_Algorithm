#include <iostream>
using namespace std;

using ll=long long;

int n;
int arr[101];
ll dp[101][21];

ll solution(int idx, int sum){
	if(sum<0 || sum>20)
		return 0;
	
	if(idx==n-1){
		if(sum==arr[n-1])
			return 1;
		else
			return 0;
	}
	
	if(dp[idx][sum]!=0)
		return dp[idx][sum];
	
	return dp[idx][sum]+=(solution(idx+1,sum-arr[idx])+solution(idx+1,sum+arr[idx]));
}


int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<solution(1,arr[0]);
}
