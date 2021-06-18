#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll n;
	cin>>n;
	vector<int> a,b;
	ll tot=n*(n+1)/2;
	if(tot%2){
		cout<<"NO";
		return 0;
	}
	else{
		tot/=2;
		cout<<"YES"<<endl;
		for(int i=n;i>0;i--){
			if(i<=tot){
				a.push_back(i);
				tot-=i;
			}else b.push_back(i);
		}
	}
	cout<<a.size()<<"\n";
	for(int x:a)
		cout<<x<<" ";
	cout<<"\n";
	cout<<b.size()<<"\n";
	for(int x:b)
		cout<<x<<" ";
}
