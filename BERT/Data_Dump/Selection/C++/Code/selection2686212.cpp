#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
void swap(int *a,int *b){
	int t;
	t=(*a);
	(*a)=(*b);
	(*b)=t;
}
int selectionsort(int A[],int n){
	int min;
	int sw=0;
	int t;

	for(int i=0;i<n;i++){
		min=i;
		for(int j=i;j<n;j++){
			if(A[j]<A[min]) min=j;
		}
		swap(&A[i],&A[min]);
		if(i!=min) sw++;
	}
	for(int i=0;i<n;i++) {
		if(i>0) cout<<" ";
			cout<<A[i];
	}
	cout<<endl;
	return sw;
}

	
int main()
{
	int A[100];
	int N;
	cin>>N;
	for(int i=0;i<N;i++) cin>>A[i];

	cout<<selectionsort(A,N)<<endl;
	
	
	return 0;
}
	
	
	
