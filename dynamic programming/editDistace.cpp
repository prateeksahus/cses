#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b;
	cin>>a;
	cin>>b;
	//dp[i][j] = min edits required when the size of a is i and size of b is j to make them equal
	vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,0));
	for(int i=1;i<=b.length();i++){
		dp[0][i] = i; 
	}
	for(int i=1;i<=a.length();i++){
		dp[i][0] = i;
	}
	for(int i=1;i<=a.length();i++){
		for(int j=1;j<=b.length();j++){
			if(a[i-1]==b[j-1]){
				dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j]+1,dp[i][j-1]+1));
			}
			else{
				dp[i][j] = min(dp[i-1][j-1]+1,min(dp[i-1][j]+1,dp[i][j-1]+1));
			}
		}
	}
	cout<<dp[a.size()][b.size()];
}
