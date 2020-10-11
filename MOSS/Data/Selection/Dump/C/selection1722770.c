#include <stdio.h>
#include <math.h>

int main(void) {
	
	int count = 0;//???????????°
	int n;//??°????????°
	int i,j;//????????????
	int a[100]={0};
	int min;
	int temp;
	
	scanf("%d\n",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	
	for(i=0;i<n;i++){
		min = i;
		for(j=i;j<n;j++){
			if(a[min]>a[j]) min = j;
			else{}
			

		}
			if (i != min){
				temp = a[i];
				a[i] = a[min];
				a[min] = temp;
				
				count++;
			}
			else{}
	}
	
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		if (i != n-1) printf(" ");
		else{}
	}
	
	printf("\n%d\n",count);
	
	return 0;
}
