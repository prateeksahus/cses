#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	ll sum = 0, ans = 0;
	unordered_map<ll,int> mp;
	mp[0]++;					//this step can be done in subarraysumII as well mp[0]++ this corresponds to if a[i] == n condition
	for(int i=0;i<n;i++){		// for int i=0;i<n;i++
		sum = (sum+a[i]%n+n)%n; //	sum += a[i]
		ans += mp[sum];         //	ans += mp[sum]
		++mp[sum];				//	++mp[sum];
	}
	cout<<ans;
}
