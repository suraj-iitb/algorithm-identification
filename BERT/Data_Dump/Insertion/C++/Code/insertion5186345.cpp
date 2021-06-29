#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void print(int A[],int n){
	int i;
	for(i=0;i<n;i++){
		cout<<A[i]<<(i==n-1?"\n":" ");
	}
}
void insertsort(int A[],int n){
	int i,j,t;
	for(i=1;i<n;i++){ //i是无序区的起始下标 
		t=A[i];
		j=i-1; //j是有序区的起始下标  
		while(j>=0&&A[j]>t){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=t;
		print(A,n);
	}
}
int main()
{
	int n;
	cin>>n;
	int A[n];
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	print(A,n);
	insertsort(A,n);
   return 0;
}

