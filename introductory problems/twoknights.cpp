#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll x;
	cin>>x;
	for(ll n=1;n<=x;n++){
		ll ans = n*n*(n*n-1)-4*2-8*3-4*(n-4)*4-4*4-4*(n-4)*6-(n-4)*(n-4)*8;
		cout<<ans/2<<endl;
	}
}
