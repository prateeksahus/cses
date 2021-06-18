#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int t;
	cin>>t;
	multimap<int,int> mp;
	for(int i=0;i<t;i++){
		int x,y;
		cin>>x>>y;
		mp.insert({y,x});
	}
	int ans=0,prev=0;
	for(auto m:mp){
		if(prev==0){
			++ans;
			prev=m.first;
			continue;
		}
		if(prev<=m.second){
			++ans;
			prev=m.first;
		}
	}
	cout<<ans;
}
