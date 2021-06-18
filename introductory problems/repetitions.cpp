#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	string s;
	cin>>s;
	int ans=1,temp=1;
	for(int i=0;i<s.length()-1;i++){
		if(s[i]==s[i+1]) ++temp;
		else{
			ans=max(ans,temp);
			temp=1;
		}
	}
	cout<<max(ans,temp);
}
