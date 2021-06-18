#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll n,x;
	cin>>n>>x;
	array<ll,2> a[n];
	for(int i=0;i<n;i++) cin>>a[i][0], a[i][1] = i+1;
	sort(a,a+n);
	vector<array<ll,3>> v;
	v.reserve(n*(n-1)/2);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			v.push_back({a[i][0]+a[j][0], i, j});
		}
	}
	int ind = v.size();
	sort(v.begin(),v.end());
	for(int i=0,j=ind-1;i<j;i++){
		while(i<j&&v[i][0]+v[j][0]>x)
			--j;
		if(i<j&&v[i][0]+v[j][0]==x){
			if(v[i][1]!=v[j][1]&&v[i][1]!=v[j][2]&&v[i][2]!=v[j][1]&&v[i][2]!=v[j][2]){
				cout<<a[v[i][1]][1]<<" "<<a[v[i][2]][1]<<" "<<a[v[j][1]][1]<<" "<<a[v[j][2]][1];
				return 0;
			}
		}
	}
	cout<<"IMPOSSIBLE";
}
