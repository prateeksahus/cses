#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll n;
	cin>>n;
	ll ans=1;
	for(int i=0;i<n;i++){
		ans=ans*2%1000000007;
	}
	cout<<ans%1000000007;
}
