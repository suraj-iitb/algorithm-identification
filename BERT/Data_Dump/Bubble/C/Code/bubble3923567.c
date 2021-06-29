#include<stdio.h>
int main(void)
{
	int a,b,c,e,f;
	e=0;
	scanf("%d", &a);
	int d[a];
	for(b=0; b<a; b++){
		scanf("%d", &d[b]);
		}
	for(f=0; f<a; f++){
	for(b=a-1; b>=f; b--){
		if(d[b]<d[b-1])
		{
			c=d[b];
			d[b]=d[b-1];
			d[b-1]=c;
			e++;
		}
	}
	}
		for(b=0; b<a; b++){
			printf("%d", d[b]);
			if(b==a-1){break;}
			printf(" ");
		}
		printf("\n");
		printf("%d\n",e);
		return 0;
}
