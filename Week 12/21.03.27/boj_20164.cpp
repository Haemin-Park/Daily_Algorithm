#include <iostream>
#include <string>
#include <algorithm>
#define mn 1e9
using namespace std;

int maxn=0;
int minn=mn;

int toNum(string tmp){
	int num=0;
	for(int i=0;i<tmp.size();i++){
		num+=tmp[i]-'0';
	}
	return num;
}

int checkNum(string tmp){
	int cnt=0;
	for(int i=0;i<tmp.size();i++){
		if((tmp[i]-'0')%2!=0){
			cnt++;
		}
	}
	return cnt;
}

void solution(int cnt, string s){
	if(s.size()==1){
		maxn=max(cnt,maxn);
		minn=min(cnt,minn);
		return;
	}
	if(s.size()==2){
		s=to_string(toNum(s));
		solution(cnt+checkNum(s),s);
	}
	if(s.size()>=3){
		int nn=s.size()-2;
		for(int i=1;i<=nn;i++){
			for(int j=1;j<=s.size()-i-1;j++){
				int k=s.size()-i-j;
				int n1=stoi(s.substr(0,i));
				int n2=stoi(s.substr(i,j));
				int n3=stoi(s.substr(i+j,k));
				string tmp=to_string(n1+n2+n3);
				solution(cnt+checkNum(tmp),tmp);
			}
		}
	}
}

int main(){
	string n;
	cin>>n;
	int cnt=0;
	cnt=checkNum(n);
	solution(cnt,n);
	cout<<minn<<" "<<maxn;
}
