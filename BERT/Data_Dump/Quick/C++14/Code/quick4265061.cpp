#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&a,vector<char>&c,int left,int mid,int right){
	int n1=mid-left,n2=right-mid;
	vector<int>tmpa1(n1),tmpa2(n2);
	vector<char>tmpc1(n1),tmpc2(n2);
	for(int i=left,j=0;i<mid;++i)tmpa1.at(j)=a.at(i),tmpc1.at(j++)=c.at(i);
	for(int i=mid,j=0;i<right;++i)tmpa2.at(j)=a.at(i),tmpc2.at(j++)=c.at(i);
	tmpa1.push_back(1e9),tmpa2.push_back(1e9);
	for(int i=left,j=0,k=0;i<right;++i){
		if(tmpa1.at(j)<=tmpa2.at(k))a.at(i)=tmpa1.at(j),c.at(i)=tmpc1.at(j++);
		else a.at(i)=tmpa2.at(k),c.at(i)=tmpc2.at(k++);
	}
}

void mergesort(vector<int>&a,vector<char>&c,int left,int right){
	int mid=(left+right)/2;
	if(left+1<right){
		mergesort(a,c,left,mid);
		mergesort(a,c,mid,right);
		merge(a,c,left,mid,right);
	}
}

int partition(vector<int>&a,vector<char>&c,int p,int r){
	int x=a.at(r),i=p-1;
	for(int j=p;j<r;++j){
		if(a.at(j)<=x){
			swap(a.at(++i),a.at(j));
			swap(c.at(i),c.at(j));
		}
	}
	swap(a.at(++i),a.at(r));
	swap(c.at(i),c.at(r));
	return i;
}

void quicksort(vector<int>&a,vector<char>&c,int p,int r){
	if(p<r){
		int q=partition(a,c,p,r);
		quicksort(a,c,p,q-1);
		quicksort(a,c,q+1,r);
	}
}

int main(){
	cin.tie(0),ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<int>v(n),v2(n);
	vector<char>c(n),c2(n);
	for(int i=0;i<n;++i)cin>>c.at(i)>>v.at(i);
	v2=v,c2=c;
	mergesort(v,c,0,n);
	quicksort(v2,c2,0,n-1);
	if(c==c2)cout<<"Stable\n"s;
	else cout<<"Not stable\n"s;
	for(int i=0;i<n;++i)cout<<c2.at(i)<<" "s<<v2.at(i)<<"\n"s;
}
