#include <stdio.h>

int main(void) {
	
	int n;
	int i,j;
	int a[100];
	int flag = 1;
	int swap=0;
	int temp;
	int min;
	
	scanf("%d",&n);
	
	for(i = 0;i < n;i++){
		scanf("%d",&a[i]);
		
	}
	
	for(i = 0;i < n;i++){
		min = i;
		for(j = i;j< n;j++){
			if(a[j]< a[min]){
				min = j;
			}
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
		if(i != min){
			swap++;	
		}
		
	}
	
	for(i = 0;i < n -1 ;i++){
		printf("%d ",a[i]);
		
	}
	printf("%d\n",a[n-1]);
	printf("%d\n",swap);
	
	return 0;
}

