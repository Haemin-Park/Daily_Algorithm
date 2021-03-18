#include <iostream>
#include <vector>
#include <algorithm>
#define maxn 1e9
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, input;
	vector<int> v;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>input;
		v.push_back(input);
	}
	sort(v.begin(),v.end());
	
	int result=2*maxn+1;
	int result_left, result_right;
	
	int left=0, right=n-1;
	while(left<right){
		
		int sum=v[left]+v[right];
		if(abs(sum)<abs(result)){
			result=sum;
			result_left=v[left];
			result_right=v[right];
		}
		
		if(sum==0){
			break;
		}else if(sum<0){
			left++;
		}else if(sum>0){
			right--;
		}
	}
	
	cout<<result_left<<" "<<result_right;
}
