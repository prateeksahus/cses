#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int t;
	cin>>t;
	set<array<int,2>> s;
	for(int i=0;i<t;i++){
		int x,y;
		cin>>x>>y;
		s.insert({ x,1 });
		s.insert({ y,-1 });
	}
	int ans=1,c=0;
	for(array<int,2> a:s){
		c+=a[1];
		ans=max(c,ans);
	}
	cout<<ans;
}
