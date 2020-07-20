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

/*void insertsort(int a[],int n){

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
}*/

int bubblesort(int a[],int n){
	int flag=1;
	int sw=0;
	for(int i=0;flag;i++){
		flag=0;
		for(int j=n-1;j>=i+1;j--){
			if(a[j]<a[j-1]){
				swap(a[j],a[j-1]);
				flag=1;
				sw++;
			}
		}
	}
	return sw;
} 

int main(){
	int n,a[101];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int sw=bubblesort(a,n);
	trace(a,n);
	printf("%d\n",sw);
	return 0;
}
