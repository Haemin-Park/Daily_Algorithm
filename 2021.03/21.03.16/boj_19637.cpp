#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

vector<int> v;
unordered_map<int, string> um;

void solution(int x){
	int resultIdx=0;
	int leftIdx=0, rightIdx=v.size()-1;
	
	while(leftIdx<=rightIdx){
		int midIdx=(leftIdx+rightIdx)/2; 

		if(x==v[midIdx]){
			resultIdx=midIdx;
			break;
		}else if(x<v[midIdx]){
			resultIdx=midIdx;
			rightIdx=midIdx-1;
		}else if(x>v[midIdx]){
			leftIdx=midIdx+1;
		}
	}
	cout<<um[v[resultIdx]]<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	string name;
	int val;
	for(int i=0;i<n;i++){
		cin>>name>>val;
		if(um.find(val)==um.end()){
			v.push_back(val);
			um[val]=name;
		}
	}
	
	int input;
	for(int i=0;i<m;i++){
		cin>>input;
		solution(input);
	}
}
