#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		ull r,c;
		cin>>r>>c;
		ull ans;
		if(r>=c){
			--c;
			if(r%2==0)
				ans=r*r-c;
			else
				ans=(r-1)*(r-1)+1+c;
		}
		else{
			--r;
			if(c%2==0)
				ans=(c-1)*(c-1)+1+r;
			else 
				ans=c*c-r;
		}
		cout<<ans<<endl;
	}
}
