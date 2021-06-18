#include<bits/stdc++.h>
#define ll long long
using namespace std;

int bs(int a[], int start, int end, int num){
	while(start<=end){
		int mid = start + (end - start)/2;
		if(a[mid]==num)
			return mid;
		if(a[mid]>num)
			end = mid-1;
		else
			start = mid+1;
	}
	return -1;
}

int main(){
	int n,s;
	cin>>n>>s;
	int a[n], b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i] = a[i];
	}
	sort(a,a+n);
	int temp = s, a1,a2,a3;
	bool flag = false,f1=0,f2=0,f3=0;
	for(int i=0;i<n&&a[i]<s;i++){
		temp -= a[i];
		int temp1 = temp;
		for(int j=i+1;j<n&&a[j]<temp1;j++){
			temp1 -= a[j];
			int ind = bs(a,j+1,n-1,temp1);
			if(ind!=-1){
				a1 = a[i], a2 = a[j], a3 = a[ind];
				flag = true;
				break;
			}
			temp1 += a[j];
		}
		if(flag) break;
		temp += a[i];
	}
	vector<int> v;
	if(!flag)
		cout<<"IMPOSSIBLE";
	else{
		for(int i=0;i<n;i++){
			if(v.size()==3) break;
			if(b[i]==a1&&!f1){
				v.push_back(i+1);
				f1 = 1;
			}
			else if(b[i]==a2&&!f2){
				v.push_back(i+1);
				f2 = 1;
			}
			else if(b[i]==a3&&!f3){
				v.push_back(i+1);
				f3 = 1;
			}
		}
		for(int x : v)
			cout<<x<<" ";
	}
}
