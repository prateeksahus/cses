#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<int> t;
	t.push_back(a[0]);
	for(int i=1;i<n;i++){
		if(a[i-1]<=a[i]){
			auto it = upper_bound(t.begin(),t.end(),a[i]);
			if(it!=t.end()){
				int temp = a[i];
				swap(temp,*it);
			}
			else
				t.push_back(a[i]);
		}
		else{
			auto it = upper_bound(t.begin(),t.end(),a[i]);
			if(it!=t.end()){
				int temp = a[i];
				swap(temp,*it);
			}
		}
	}
	cout<<t.size();
}
