#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int t;
	cin>>t;
	ll a[t];
	ll s=0;
	for(int i=0;i<t;i++){
		cin>>a[i];
		s+=a[i];
	}
	ll mn=INT_MAX;
	ll sum = 0;
	for(int i=0;i<(1<<t);i++){
		sum = 0;
		for(int j=0;j<t;j++){
			if((1<<j)&i) sum+=a[j]; 
		}
		mn=min(mn,abs(sum-(s-sum)));
	}
	cout<<mn;
}
