#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	ll sum = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum += a[i];
	}
	sort(a,a+n);
	ll ans = 0;
	if(sum-a[n-1]<a[n-1]) ans = 2*a[n-1];
	else ans = sum;
	cout<<ans;
}
