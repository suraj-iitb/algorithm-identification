#include <stdio.h>

void sy(int a[100],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d",a[i]);
		if(i!=n-1){printf(" ");}
	}
	printf("\n");
}

int main(void){
    int i,j,k,n,b[100];
    scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	sy(b,n);
	for(i=1;i<n;i++){
		j=i;
		while(j>0){
			if(b[j-1]>b[j]){
				k=b[j-1];
				b[j-1]=b[j];
				b[j]=k;
				j--;
			}else{
				break;
			}
		}
		sy(b,n);
	}
	return 0;
}
