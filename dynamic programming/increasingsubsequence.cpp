#include<bits/stdc++.h>
#define ll long long
using namespace std;

// O(n^2) solution

//int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	int n;
//	cin>>n;
//	int a[n];
//	for(int i=0;i<n;i++) cin>>a[i];
//	vector<int> dp(n);
//	for(int k=0;k<n;k++){
//		dp[k] = 1;
//		for(int i=0;i<k;i++){
//			if(a[i]<a[k])
//				dp[k] = max(dp[k],dp[i]+1);
//		}
//	}
//	cout<<*max_element(dp.begin(),dp.end());
//}

//O(n) solution

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> dp;
	for(int i=0;i<n;i++){
		auto it = lower_bound(dp.begin(),dp.end(),a[i]);
		if(it==dp.end())
			dp.push_back(a[i]);
		else
			*it = a[i];
	}
	cout<<dp.size();
}
