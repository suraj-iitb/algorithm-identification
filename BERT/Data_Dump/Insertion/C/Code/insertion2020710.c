#include <stdio.h>
int main(void){
	int a,b[1001],c,i,j,x,k;
	scanf("%d",&a);
	for(i=0;i<a;i++)
		scanf("%d",&b[i]);
	for(i=0;i<a;i++){
		if(i==0)
			goto out;
		for(j=i-1;j>=0;j--){
			if(b[j] > b[j+1]){
				c = b[j];
				b[j] = b[j+1];
				b[j+1] = c;
			}
		}
		out:
		for(k=0;k<a;k++){
			printf("%d",b[k]);
			if(k!=a-1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
