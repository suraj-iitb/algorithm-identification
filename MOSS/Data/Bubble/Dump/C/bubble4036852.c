#include <stdio.h>
#define N 100

int main(){
	int a,b,flag,i,j,c,v;
	int A[N];

	scanf("%d",&b);
	for(i=0;i<b;i++){
		scanf("%d",&A[i]);
		v=A[i];
	}
	c = 0;
	for (i = 0; i < b-1; i++){
		for ( j = 0; j < b-1; j++){
			if (A[j] > A[j+1]){
				v = A[j];
				A[j] = A[j+1];
				A[j+1] = v;
				c++;
			}
		}
	}
	for(j=0;j<b;j++){
		printf("%d",A[j]);
		if(j<b-1) printf(" ");
	}
	printf("\n");
	printf("%d\n",c);
	return 0;
}
