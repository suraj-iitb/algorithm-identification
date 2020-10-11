#include<stdio.h>

void view(int a[], int n){
	int i;
	for(i=0;i<n-1;i++) printf("%d ",a[i]);
	printf("%d\n",a[n-1]);
}

void bubbleSort(int a[], int n){
	int j,temp,flag=1,count=0;
	while(flag==1){
		flag = 0;
		for(j=n-1;j>0;j--){
			if(a[j]<a[j-1]){
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
				flag = 1;
				count++;
			}
		}
	}
	view(a,n);
	printf("%d\n",count);
}

int main(void){
	int i,a[100],n;

	scanf("%d\n",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	bubbleSort(a,n);

	return 0;
}
