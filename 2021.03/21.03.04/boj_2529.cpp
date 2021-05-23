#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
char arr[10];
vector<string> v;

bool isPossible(int num, string s){
	for(int i=0;i<s.size();i++){
		if(num==(s[i]-'0')) return false;
	}
	return true;
}

void solution(int idx, string s){
	if(idx==n+1){
		v.push_back(s);
	}else{
		for(int i=0;i<=9;i++){
			if(idx==0){
				solution(idx+1,s+to_string(i));
			}else if(isPossible(i,s)){
				if(arr[idx-1]=='<'){
					if(i>(s[idx-1]-'0')){
						solution(idx+1,s+to_string(i));
					}
				}else if(arr[idx-1]=='>'){
					if(i<(s[idx-1]-'0')){
						solution(idx+1,s+to_string(i));
					}
				}
			}
		}
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	solution(0,"");
	sort(v.begin(),v.end());
	cout<<v[v.size()-1]<<endl;
	cout<<v[0];
}
