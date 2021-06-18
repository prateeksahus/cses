#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int st[4*200000+1], a[200001];

void build_tree(int si, int ss, int se){
	if(ss == se){
		st[si] = a[ss];
		return;
	}
	
	int mid = (ss+se)/2;
	
	build_tree(2*si, ss, mid);
	build_tree(2*si+1, mid+1, se);
	
	st[si] = min(st[2*si], st[2*si+1]);
}

int query(int si, int ss, int se, int qs, int qe){
	if(qe<ss || qs>se) return INT_MAX;
	
	if(ss>=qs && se<=qe) return st[si];
	
	int mid = (ss+se)/2;
	
	int l = query(2*si, ss, mid, qs, qe);
	int r = query(2*si+1, mid+1, se, qs, qe);
	
	return min(l, r);
}

void update(int si, int ss, int se, int qi, int qv){
	if(qi==ss && qi==se){
		st[si] = qv;
		return;
	}
	
	int mid = (ss+se)/2;
	
	if(qi<=mid) update(2*si, ss, mid, qi, qv);
	else update(2*si+1, mid+1, se, qi, qv);
	
	st[si] = min(st[2*si], st[2*si+1]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin>>n>>q;
	
	for(int i=1;i<=n;i++)
		cin>>a[i];
		
	build_tree(1, 1, n);
	
	while(q--){
		int t, l, r;
		cin>>t>>l>>r;
		if(t==1){	
			update(1, 1, n, l, r);
		}
		if(t==2){
			cout<<query(1, 1, n, l, r)<<endl;
		}
	}
}
