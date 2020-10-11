#include<stdio.h>
#define N 100

int cnt=0;
int a[N];

void swap(int x,int y){
	int temp=a[x];
	a[x]=a[y];
	a[y]=temp;
	return;
}

void selectionSort(int n){
	int i,j;
	int min;
	int idx;
	
	for(i=0;i<n;i++){
		min=1000;
		for(j=i+1;j<n;j++){
			if(min > a[j]){
				idx=j;
				min=a[j];
			}
		}
		if(a[i] > min){
			swap(i,idx);
			cnt++;
		}
	}
	
	return;
}

int main(){
	int n,i;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	selectionSort(n);
	
	for(i=0;i<n-1;i++)
		printf("%d ",a[i]);
	printf("%d\n",a[n-1]);
	
	printf("%d\n",cnt);
	
	return 0;
	
}
