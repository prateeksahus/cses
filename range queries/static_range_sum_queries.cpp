#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin>>n>>q;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	vector<ll> s(n, 0);
	s[0] = a[0];
	for(int i=1;i<n;i++){
		s[i] = s[i-1]+a[i];
	}
	while(q--){
		int l, r;
		cin>>l>>r;
		if(l==r) cout<<a[l-1]<<endl;
		else cout<<s[r-1]-s[l-1]+a[l-1]<<endl;
	}
}

