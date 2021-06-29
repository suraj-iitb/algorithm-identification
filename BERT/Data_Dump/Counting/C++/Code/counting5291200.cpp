#include<iostream>
#include<stdio.h>
using namespace std;
int n;
void CountingSort(int A[],int B[]){
	int C[10002];
	for(int i=0;i<=10000;i++)
	{
		C[i]=0;
	}
	for(int j=1;j<=n;j++)
	{
		C[A[j]]++;
	}
	for(int i=1;i<=10000;i++){
	    C[i]=C[i]+C[i-1];
	}
		
	for(int j=n;j>=1;j--)
	{
		B[C[A[j]]]=A[j];
		C[A[j]]--;
	}
}
int main(){
	cin>>n;
	int a[n+1],b[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	    
	}
	CountingSort(a,b);
	for(int i=1;i<=n;i++)
	{
		cout<<b[i];
		if(i!=n)
			cout<<" ";
	}
	cout<<endl;
	return 0;
}

