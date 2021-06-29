#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;
int cnt=0;

void merge(vector<int> &A,int left,int mid,int right){
	int n1=mid-left;
	int n2=right-mid;
	vector<int> L,R;
	for(int i=0;i<n1;i++){
		L.push_back(A.at(left+i));
	}

	for(int i=0;i<n2;i++){
		R.push_back(A.at(mid+i));
	}
	L.push_back(inf);
	R.push_back(inf);

	int i=0;
	int j=0;

	for(int k=left;k<right;k++){
		if(L.at(i)<=R.at(j)){
			A.at(k)=L.at(i);
			i++;
		}else{
			A.at(k)=R.at(j);
			j++;
		}

		cnt++;
	}
}

void mergeSort(vector<int> &A,int left,int right){
	if(left+1<right){
		int mid=(left+right)/2;
		mergeSort(A,left,mid);
		mergeSort(A,mid,right);
		merge(A,left,mid,right);
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> A(n);
	for(int i=0;i<n;i++) cin>>A.at(i);

	mergeSort(A,0,n);

	for(int i=0;i<n;i++){
		cout<<A.at(i);
		if(i<n-1) cout<<" ";
		else cout<<endl<<cnt<<endl;
	}

	return 0;
}

