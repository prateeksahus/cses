#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n,x;
	cin>>n>>x;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	ll sum = 0, ans = 0;
	for(int i=0,j=-1;i<n&&j<n;i++){
		while(j<n&&sum<x){
			++j;
			sum += a[j];
		}
		if(sum == x){
			++ans;
			sum -= abs(a[i]);
		}
		else if(sum>x){
			sum-=abs(a[i]);
		}
	}
	cout<<ans;
}
