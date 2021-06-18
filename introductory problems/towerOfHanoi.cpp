#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(int n, int s, int d, int h, vector<array<int, 2>>& ans){
	if(n==1){
		ans.push_back({s, d});
		return;
	}
	solve(n-1, s, h, d, ans);
	ans.push_back({s, d});
	solve(n-1, h, d, s, ans);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<array<int, 2>> ans;
	solve(n, 1, 3, 2, ans);
	cout<<ans.size()<<endl;
	for(array<int, 2> a : ans){
		cout<<a[0]<<" "<<a[1]<<endl;
	}
}
