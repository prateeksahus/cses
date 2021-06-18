#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mxn=2e5;

int main(){
	int n;
	cin>>n;
	int a[n];
	map<int,int> mp;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int ans=0;
	for(int i=0,j=0;i<n;i++){
		while(j<n&&mp[a[j]]<1){
			++mp[a[j]];
			++j;
		}
		ans=max(ans,j-i);
		mp[a[i]]--;
	}
	cout<<ans;
}
