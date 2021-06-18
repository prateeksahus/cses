//good problem learnt a lot!
//u can also use set instead of multiset
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n;
	cin>>n;
	array<int,3> ar[n];
	multiset<array<int,2>> s;
	int ans[n];
	for(int i=0;i<n;i++){
		cin>>ar[i][1]>>ar[i][0];
		ar[i][2] = i;
	}
	sort(ar,ar+n);
	for(int i=0;i<n;i++){
		auto it = s.lower_bound({ar[i][1]});
		if(it!=s.begin()){
			--it;
			ans[ar[i][2]] = (*it)[1];
			s.erase(it);
		}
		else{
			ans[ar[i][2]] = s.size();
		}
		s.insert({ar[i][0],ans[ar[i][2]]});
	}
	cout<<s.size()<<"\n";
	for(int x:ans)
		cout<<++x<<" ";
}
