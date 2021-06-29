#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int a[105];
void out(int a[],int n){
	for(int i=1;i<=n;i++){
		if(i>1){
			printf(" ");
		}
	    printf("%d",a[i]);
	}
    printf("\n");
}
void SSort(int a[], int n){
	int v,j;
	for(int i=2;i<=n;i++){
		v=a[i];
		j=i-1;
		while(j>0&&a[j]>v){
			a[j+1]=a[j];
			j--;
		} 
	a[j+1]=v;
	out(a,n);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	out(a,n);
	SSort(a,n);
    return 0;
}

