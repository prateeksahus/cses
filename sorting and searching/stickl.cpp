#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	ll l=0,r=0;
	if(n%2){
		for(int i=0;i<n/2;i++)
			l+=a[i];
		for(int i=n/2+1;i<n;i++)
			r+=a[i];
		cout<<abs(l-r);
	}else{
		for(int i=0;i<n/2;i++)
			l+=a[i];
		for(int i=n/2;i<n;i++)
			r+=a[i];
		cout<<abs(l-r);
	}
}
