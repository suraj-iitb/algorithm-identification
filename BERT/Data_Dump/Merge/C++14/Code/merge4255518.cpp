#include<bits/stdc++.h>
using namespace std;

int c=0;

void merge(vector<int>&s,int left,int mid,int right){
	int n1=mid-left,n2=right-mid;
	vector<int>L(n1),R(n2);
	for(int i=0;i<n1;++i)L.at(i)=s.at(left+i);
	for(int i=0;i<n2;++i)R.at(i)=s.at(mid+i);
	L.push_back(0x7FFFFFFF),R.push_back(0x7FFFFFFF);
	for(int k=left,i=0,j=0;k<right;++k){
		if(L.at(i)<=R.at(j)){
			s.at(k)=L.at(i);
			++i;
		}else{
			s.at(k)=R.at(j);
			++j;
		}
		++c;
	}
}

void mergesort(vector<int>&s,int left,int right){
	int mid=(left+right)/2;
	if(left+1<right){
		mergesort(s,left,mid);
		mergesort(s,mid,right);
		merge(s,left,mid,right);
	}
	return;
}

int main(){
	cin.tie(0),ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<int>s(n);
	for(int i=0;i<n;++i)cin>>s.at(i);
	mergesort(s,0,n);
	cout<<s.at(0);
	for(int i=1;i<n;++i)cout<<" "s<<s.at(i);
	cout<<"\n"s<<c<<"\n"s;
}
