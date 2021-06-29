#include <stdio.h>

int main(void) {
	
	int n;
	int i;
	int a[100];
	int flag = 1;
	int swap=0;
	int temp;
	
	scanf("%d",&n);
	
	for(i = 0;i < n;i++){
		scanf("%d",&a[i]);
		
	}
	
	while(flag){
		flag = 0;
		for(i = n -1;i > 0; i--){
			if(a[i] < a[i - 1]){
				temp = a[i];
				a[i] = a[i -1];
				a[i -1] = temp;
				flag = 1;
				swap++;
			}
		}
	}

	for(i = 0;i < n -1 ;i++){
		printf("%d ",a[i]);
		
	}
	printf("%d\n",a[n-1]);
	printf("%d\n",swap);
	
	return 0;
}

