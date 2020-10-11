#include<stdio.h>
#define N 100000
void bubbleSort(int a[], int array_size)
{
	int i, j, temp;
	int k;
	int cnt=0;
	for (i=0; i<(array_size - 1);i++) {
    		for (j=(array_size-1);j>i;j--) {
      		if(a[j-1]>a[j]) {
        			temp=a[j-1];
       			a[j-1] = a[j];
        			a[j]=temp;
        			cnt++;
        		}
        	}
        }

	for(k=0; k<array_size-1;k++){
		printf("%d ",a[k]);
	}
	for(k=array_size-1; k<array_size;k++){
		printf("%d\n",a[k]);
	}
        printf("%d\n",cnt);
}

int main()
{
	int i,j,n;
	int a[N];
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	bubbleSort(a,n);

  return 0;
}
