#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[200000];
ll dp[200000];

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	dp[0]=a[0];
	for(int i=1;i<n;i++)
		dp[i]=max((ll)a[i],dp[i-1]+(ll)a[i]);
	ll ans=LLONG_MIN;
	for(int i=0;i<n;i++)
		ans=max(ans,dp[i]);
	cout<<ans;
}
