#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b;
	cin>>a>>b;
	// dp[a][b] = min no of cuts if length is a and width b
	vector<vector<int>> dp(a+1,vector<int>(b+1,1e9));
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			if(i==j)
				dp[i][j] = 0; 
			else{
				for(int k=1;k<i;k++){
					dp[i][j] = min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
				}
				for(int k=1;k<j;k++){
					dp[i][j] = min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
				}
			}
		}
	}
	cout<<dp[a][b];
}
