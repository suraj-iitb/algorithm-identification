#include<iostream>
#include<string>
#include<utility>
#include<algorithm>
#include<limits>

using namespace std;

int S[500000];
int L[250001];
int R[250001];
int cnt;

void merge(int *A, int left, int mid, int right) {
	int n1=mid-left;
	int n2=right-mid;
	for(int i=0; i<n1; i++) L[i]=A[left+i];
	for(int i=0; i<n2; i++) R[i]=A[mid+i];
	L[n1]=numeric_limits<int>::max();
	R[n2]=numeric_limits<int>::max();
	int i=0, j=0;
	for(int k=left; k<right; k++) {
		if(L[i]>R[j]) A[k]=R[j++];
		else A[k]=L[i++];
	}
	cnt+=(right-left);
}

void mergeSort(int *A, int left, int right) {
	if(left+1<right) {
		int mid=(left+right)/2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0; i<n; i++) cin>>S[i];
	mergeSort(S, 0, n);
	if(n>0) cout<<S[0];
	for(int i=1; i<n; i++) cout<<' '<<S[i];
	cout<<'\n'<<cnt<<'\n';
	return 0;
}

