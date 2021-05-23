#include <iostream>
#include <string>
using namespace std;

int n;
bool suc=false;

bool isgood(string s){
	for(int i=0;i<s.length();i++){
		for(int j=1;j<=s.length()/2&&i+2*j<=s.length();j++){
			if(s.substr(i,j)==s.substr(i+j,j)){
				return false;
			}
		}
	}
	return true;
}

void solution(int len, string s){
	if(len==n){
		if(!suc){
			cout<<s<<endl;
			suc=true;
		}
		return;
	}
	else{
		if(!suc){
			for(int i=1;i<=3;i++){
				string tmp=s+to_string(i);
				if(isgood(tmp)){
					solution(len+1,tmp);
				}

			}
		}
		else
			return;
	}
}

int main(){
	cin>>n;
	solution(0,"");
}
