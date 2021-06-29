#include <stdio.h>
void insertionsort(int[], int);
void print(int[], int);
int main(int argc, char const *argv[])
{
	int i, j, a[100], n;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	insertionsort(a, n);	
	return 0;
}

void insertionsort(int a[], int n){
	int j, v, b[n], i;
	for(i=0;i<n;i++){
		b[i]=a[i];
	}
	for(i=0;i<n;i++){
		v=b[i];
		j=i-1;
		while(j>=0&&b[j]>v){
			b[j+1]=b[j];
			j--;
		}
		b[j+1]=v;
		print(b,n);
		if(i!=n-1){

		}
	}
}

void print(int b[],int n){
	int i;
	for(i=0;i<n;i++){
		if(i>0)printf(" ");
		printf("%d", b[i]);
	}
	printf("\n");
}	
