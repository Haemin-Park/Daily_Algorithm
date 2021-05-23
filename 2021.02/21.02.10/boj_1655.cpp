#include <iostream>
#include <queue>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	priority_queue<int> minq,maxq;
	int input;
	for(int i=0;i<n;i++){
		cin>>input;
		if(maxq.size()<=minq.size()){
			maxq.push(input);
		}else{
			minq.push(-1*input);
		}
		if(!maxq.empty()&&!minq.empty()){
			if(maxq.top()>-1*minq.top()){
				maxq.push(-1*minq.top());
				minq.push(-1*maxq.top());
				maxq.pop();
				minq.pop();
			}	
		}

		cout<<maxq.top()<<"\n";
	}
}
