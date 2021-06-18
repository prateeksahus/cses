#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int a[n];
	int x = 1000*n;
	for(int i=0;i<n;i++) cin>>a[i];
	vector<vector<bool>> dp(n+1,vector<bool>(x+1,false));
	dp[0][0] = true;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=x;j++){
			if(j-a[i-1]>=0){
				dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
			}
			else 
				dp[i][j] = dp[i-1][j];
		}
	}
	vector<int> ans;
	for(int j=1;j<=x;j++){
		if(dp[n][j])
			ans.push_back(j);
	}
	cout<<ans.size()<<endl;
	for(int v : ans)
		cout<<v<<" ";
}
