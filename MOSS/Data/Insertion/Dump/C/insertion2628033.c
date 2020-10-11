#include <stdio.h>
#define N 100

int a[N];

void PrintMatrix(int n){
	int i;
	for(i=0;i<n-1;i++) printf("%d ",a[i]);
	printf("%d\n",a[n-1]);
}

void Insertion(int n){
	int i, j, k, temp;
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(a[i]<a[j]){
				temp=a[i];
				for(k=i;k>j;k--) a[k]=a[k-1];
				a[j]=temp;
			}
		}
		PrintMatrix(n);
	}
}

int main(void){
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
        PrintMatrix(n);
	Insertion(n);
	return 0;
}
