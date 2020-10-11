#include <stdio.h>
#include <math.h>

int main(void) {
	
	int count = 0;//???????????°
	int n;//??°????????°
	int i,j;//????????????
	int a[100]={0};
	int temp;
	
	scanf("%d\n",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	for(j=0;j<n;j++){
		for(i=n-1;i>j;i--){
			if(a[i-1]>a[i]){
				temp = a[i-1];
				a[i-1] = a[i];
				a[i] = temp;
				
				count++;
			}
			else{}
		}
	}
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		if (i != n-1) printf(" ");
		else{}
	}
	
	printf("\n%d\n",count);
	
	return 0;
}
