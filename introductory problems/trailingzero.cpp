#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n;
	cin>>n;
	ll ans=0,d=5;
	while(d<=n){
		ans+=n/d;
		d*=5;
	}
	cout<<ans;
}
