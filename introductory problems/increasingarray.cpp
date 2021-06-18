#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n;
	cin>>n;
	int prev,cur;
	cin>>prev;
	ll ans=0;
	for(int i=1;i<n;i++){
		cin>>cur;
		if(prev>cur) ans+=prev-cur;
		else prev=cur;
	}
	cout<<ans;
}
