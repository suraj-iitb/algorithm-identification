#include <stdio.h>
#define N 100

int main(void) 
{
	int i,v,k,j,n,m,a[N];
	scanf("%d",&n);
	for(m=0;m<n;m++){
		scanf("%d",&a[m]);
	}
	for(k=0;k<n;k++){
		printf("%d",a[k]);
		if(k != n-1){
			printf(" ");
		}
	}
	printf("\n");

	for(i=1;i<n;i++){
	
		v = a[i];
		int j = i-1;
		while(j>=0 && a[j]>v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
		for(k=0;k<n;k++){
			printf("%d",a[k]);
			if(k != n-1){
				printf(" ");
				}
	    }
		printf("\n");
	}
	
	return 0;
}
