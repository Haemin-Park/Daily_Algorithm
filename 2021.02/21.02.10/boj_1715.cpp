#include <iostream>
#include <queue>
using namespace std;
int arr[100001];
int main(){
	int n;
	priority_queue<int> pq;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		pq.push(-1*arr[i]);
	}
	int sum=0,p1,p2;
	while(!pq.empty()){
		p1=pq.top();
		pq.pop();
		if(!pq.empty()){
			p2=pq.top();
			pq.pop();
			sum+=p1+p2;
			pq.push(p1+p2);
		}
	}

	cout<<-1*sum;
}
