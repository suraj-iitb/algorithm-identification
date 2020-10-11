#include<stdio.h>

void print_array(int a[],int n);

int main(void){
	int n,i,j,key;
	int a[101];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		key=a[i];
		j=i-1;
		while(j>=0 && a[j] > key){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
		print_array(a,n);
	}
	return 0;
}

void print_array(int a[], int n)
{
  int i;
  for(i = 0; i < n; i++){
    printf("%d",a[i]);
	if(i!=n-1) printf(" ");
  }
  printf("\n");
  return;
}
