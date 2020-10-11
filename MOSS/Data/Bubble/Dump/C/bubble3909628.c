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
	
	for(i=0;i<n;i++){
		for (j = n-1; j > i; j--) {
			if( a[j] < a[j-1]) {
				t= a[j];
				a[j]=a[j-1];
				a[j-1]=t;
				c++;
				//printf("%d %d\n",a[j-1],a[j]);
			}
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
