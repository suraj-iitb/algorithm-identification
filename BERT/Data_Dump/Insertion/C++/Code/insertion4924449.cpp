#include <bits/stdc++.h>
using namespace std;

void insertSort(int A[],int n){
	for (int i=1;i<n;i++){
		int v = A[i];
		int j = i-1;
		while (j>=0 && A[j]>v){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
		for(int j=0;j<n-1;j++){cout<<A[j]<<" ";};cout<<A[n-1]<<endl;
	}
}

int main(){
	int n;
	cin >> n;
	int A[n];
	for (int i=0;i<n;i++)cin>>A[i];
	for(int j=0;j<n-1;j++){cout<<A[j]<<" ";};cout<<A[n-1]<<endl;
	insertSort(A,n);

}
