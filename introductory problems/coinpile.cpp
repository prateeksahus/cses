#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		if(a>b) swap(a,b);
		string ans;
		if(2*a<b) ans="NO";
		else{
			a%=3;b%=3;
			if(a>b) swap(a,b);
			if((a==0&&b==0)||(a==1&&b==2)) ans="YES";
			else ans="NO";
		}
		cout<<ans<<endl;
	}
}
