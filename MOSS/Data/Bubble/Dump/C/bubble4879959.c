#include <stdio.h>
int main(void){
	int i,j,a,b[101],c,cnt=0;
	scanf("%d",&a);
	for(i=0;i<a;i++)
		scanf("%d",&b[i]);
	for(i=0;i<a-1;i++){
		for(j=a-1;j>i;j--){	
			if(b[j] < b[j-1]){
				c = b[j-1];
				b[j-1] = b[j];
				b[j] = c;
				cnt++;
			}
		}
	}
	for(i=0;i<a;i++){
		printf("%d",b[i]);
		if(i!=a-1)
			printf(" ");
		else
			printf("\n");
	}
	printf("%d\n",cnt);
	return 0;
}

