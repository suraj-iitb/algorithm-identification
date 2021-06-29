#include<iostream>
#include<cstdio>

using namespace std;

void trace(int a[],int n){
	for(int i=0;i<n;i++){
		if(i) printf(" ");
		printf("%d",a[i]);
	}
	printf("\n");
}

void insertsort(int a[],int n){

	for(int i=1;i<n;i++){
		int v=a[i];
		int j=i-1;
		while(j>=0 && v<a[j]){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		trace(a,n);
	}
	return;
}


int main(){
	int n,a[101];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	trace(a,n);
	insertsort(a,n);
	return 0;
}
