//binary search on answer
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n; ll t;
	cin>>n>>t;
	ll a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	ll low = 0, high = 1e18;
	ll ans;
	while(low<=high){
		ll mid = (low+high)/2;
		ll sum = 0;
		for(int i=0;i<n;i++){
			sum += mid/a[i];
			if(sum>=t)
				break;
		}
		if(sum>=t){
			ans = mid;
			high = mid-1;
		}else
			low = mid+1;
	}
	cout<<ans;
}
