#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int a[n];
	ll sum = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum += a[i];
	}
	ll start = *max_element(a,a+n);
	ll end = sum;
	sum = 0;
	ll ans = 0;
	int cnt = 1;
	while(start<=end){
		cnt = 1, sum = 0;
		ll mid = start + (end-start)/2;
		for(int i=0;i<n;i++){
			if(sum+a[i]<=mid){
				sum += a[i];
			}
			else{
				sum = a[i];
				cnt++;
			}
		}
		if(cnt<=k){
			ans = mid;
			end = mid - 1;
		}
		else{
			start = mid+1;
		}
	}
	cout<<ans;
}
