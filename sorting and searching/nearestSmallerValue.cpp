#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	stack<int> st;
	for(int i=0;i<n;i++){
		while(!st.empty()&&a[st.top()]>=a[i])
				st.pop();
		if(st.empty()) cout<<0<<" ";
		else cout<<st.top()+1<<" ";
		st.push(i);
	}
}
