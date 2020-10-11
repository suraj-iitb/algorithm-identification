#include<stdio.h>
#include<stdlib.h>
#define M 2000001
#define V 10000

int main(){
	unsigned short *a, *b;

	int c[V+1];
	int num,i,j;

	scanf("%d",&num);

	a=malloc(sizeof(short)*num+1);

	b=malloc(sizeof(short)*num+1);



	for(i=0;i<V+1;i++){
		c[i]=0;
	}

	for(i=0;i<num;i++){
		scanf("%hu",&a[i+1]);
		c[a[i+1]]=c[a[i+1]]+1;
	}

	for(i=1;i<V+1;i++){
		c[i]=c[i]+c[i-1];
	}

	for(j=1;j<num+1;j++){
		b[c[a[j]]]=a[j];
		c[a[j]]=c[a[j]]-1;
	}


	for(i=1;i<num+1;i++){
		if(i>1)
			printf(" ");

		printf("%d",b[i]);
	}

	printf("\n");

	return 0;
}
