#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstdlib>
#include<utility>
using namespace std;

int A[500500];
int L[500500];
int R[500500];
int cnt;

void merge(int l, int m, int r){
	int n1 = m-l;
	int n2 = r-m;
	for(int i=0; i<n1; i++){
		L[i] = A[l+i];
	}
	for(int i=0; i<n2; i++){
		R[i] = A[m+i];
	}
	L[n1] = 1001001001;
	R[n2] = 1001001001;
	int i = 0;
	int j = 0;
	for(int k=l; k<r; k++){
		if(L[i]<R[j]){
			A[k] = L[i];
			i++;
		}else{
			A[k] = R[j];
			j++;
		}
		cnt++;
	}
}

void merge_sort(int l, int r){
	if(l+1<r){
		int m = (l+r)/2;
		merge_sort(l, m);
		merge_sort(m, r);
		merge(l, m, r);
	}
}

int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> A[i];
	}
	cnt = 0;
	merge_sort(0, n);

	for(int i=0; i<n; i++){
		cout << A[i];
		if(i==n-1) cout << endl;
		else cout << " ";
	}
	cout << cnt << endl;
	return 0;
}
