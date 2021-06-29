#include <stdio.h>
int main(void){
	int n, i, j, flag, count, temp, a[100];
	
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	
	flag = 1;
	i = 0;
	count = 0;
	
	while(flag){
		flag = 0;
		
		for(j=n-1;j>i;j--){
			if(a[j] < a[j-1]){
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
				
				count++;
				flag = 1;
			}
		}
		
		i++;
	}
	
	for(i=0; i<n; i++){
		if(i != n-1){
			printf("%d ", a[i]);
		}else{
			printf("%d\n", a[i]);
		}
	}
	
	printf("%d\n", count);
	
	return 0;
}
