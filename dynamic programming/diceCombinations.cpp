#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1e9+7;
int dp[(int)1e6+1];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	dp[0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=6&&i-j>=0;j++){
			dp[i] = (dp[i] + dp[i-j])%mod;
		}
	}
	cout<<dp[n];
}
