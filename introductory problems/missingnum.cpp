#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[200001];

int main(){
	int n;
	cin>>n; 
	--n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		++a[x];
	}
	for(int i=1;i<=++n;i++)
		if(a[i]==0){
			cout<<i;
			break;
		}
}
