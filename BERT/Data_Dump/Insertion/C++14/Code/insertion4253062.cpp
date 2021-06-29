#include<iostream>
using namespace std;
void output(int n,int a[]){
	for(int i=0;i<n;i++){
		if(i==n-1)
		printf("%d\n",a[i]);
		else
		printf("%d ",a[i]);
	}
}
void insertion_sort(int n,int a[]){
	int v,j;
	output(n,a);
	for(int i=1;i<n;i++){
	v=a[i];
		j=i-1;
		while(j>=0&&a[j]>v){
		a[j+1]=a[j];
			j--;
			a[j+1]=v;
		}
		
		output(n,a);}
}

main(){
	int N;
	scanf("%d",&N);
	int A[N];
	for(int i=0;i<N;i++)
	scanf("%d",&A[i]);
	insertion_sort(N,A);
	
	return 0;
}

