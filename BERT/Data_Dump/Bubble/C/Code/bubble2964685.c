#include<stdio.h>
#define N 100

int a[N];
int cnt=0;

void swap(int x,int y){
	int temp=a[x];
	a[x]=a[y];
	a[y]=temp;
	return;
}

void bubbleSort(int n){
	int i,j;
	
	for(i=n-1;i>=0;i--){
		for(j=0;j<i;j++){
			if(a[j] > a[j+1]){
				swap(j,j+1);
				cnt++;
			}
		}
	}
	
	return;
}

int main(){
	int n,i;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	bubbleSort(n);
	
	for(i=0;i<n-1;i++)
		printf("%d ",a[i]);
	printf("%d\n",a[n-1]);
	
	printf("%d\n",cnt);
	
	return 0;
	
}
