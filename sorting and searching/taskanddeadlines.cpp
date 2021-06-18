#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n;
	cin>>n;
	pair<int,int> p[n];
	for(int i=0;i<n;i++){
		cin>>p[i].first>>p[i].second;
	}
	sort(p,p+n);
	ll tim = 0, ans = 0;
	for(auto x : p){
		tim += x.first;
		ans += x.second-tim;
	}
	cout<<ans;
}
