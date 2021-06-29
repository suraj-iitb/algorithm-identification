#include<stdio.h>
void MIYASUKU(int[],int);
void sort(int[],int);
main(){
	int n,i;
	int a[1000];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		}
	
	MIYASUKU(a,n);
	sort(a,n);
}

void MIYASUKU(int a[1000],int n){
	int i;
	for(i=0;i<n;i++){
		if(i>0)printf(" ");
		printf("%d",a[i]);
		}
	printf("\n");
}

void sort(int a[1000],int n){
	int i,v,j;
	for(i=1;i<n;i++){
		v=a[i];
		j=i-1;
		while(j>=0&&a[j]>v){
			a[j+1]=a[j];
			j--;
		}
	a[j+1]=v;
	MIYASUKU(a,n);
	}
}
