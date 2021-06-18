#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<int> ans[(int)pow(2,n)];
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(i&(1<<j)) ans[i].push_back(1);
			else ans[i].push_back(0);
		}
	}
	for(vector<int> v : ans){
		cout<<v[v.size()-1];
		for(int i=v.size()-1;i>0;i--){
			cout<<(v[i]^v[i-1]);
		}
		cout<<endl;
	}
}
