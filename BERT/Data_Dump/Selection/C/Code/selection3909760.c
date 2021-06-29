#include <stdio.h>

int main(void){
	
	int n;
	scanf("%d",&n);
	
	int a[n];
	
	int i;
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	int j;
	int c=0; //count
	int t;
	int min, mini;
	
	for(i=0;i<n;i++){
		min = a[i];
		mini = i;
		for (j = i+1; j < n; j++) {
			if( min > a[j]) {
				min = a[j];
				mini = j;
			}
		}
		if(i==mini){
			;
		}
		else{
			t = a[i];
			a[i] = min;
			a[mini] = t;
			c++;
		}
	}

	for(j=0; j<n; j++) {
		if(j>0){
			printf(" ");
		}
		printf("%d",a[j]);
	}
	
	printf("\n%d\n",c);

	return 0;
}
