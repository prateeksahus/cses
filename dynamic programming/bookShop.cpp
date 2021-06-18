//0|1 knapsack
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,x;
	cin>>n>>x;
	int h[n], s[n];
	for(int i=0;i<n;i++) cin>>h[i];
	for(int i=0;i<n;i++) cin>>s[i];
	vector<vector<int>> dp(n+1,vector<int>(x+1,0));
	for(int i=1;i<=n;i++){
		for(int j=0;j<=x;j++){
			if(h[i-1]<=j){
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-h[i-1]]+s[i-1]); 
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout<<dp[n][x];
}
