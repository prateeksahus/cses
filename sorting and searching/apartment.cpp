#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[200001],b[200001];

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];
	sort(a,a+n);
	sort(b,b+m);
	int ans=0;
	for(int i=0,j=0;i<n&&j<m;){
		if(a[i]-b[j]>k){
			++j;
		}
		if(abs(a[i]-b[j])<=k){
			++i;
			++j;
			++ans;
		}
		if(b[j]-a[i]>k){
			++i;
		}
	}
	cout<<ans;
}
