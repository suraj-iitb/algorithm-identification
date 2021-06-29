#include<stdio.h>
int main(void)
{
	int a,b,c,e,f;
	scanf("%d",&a);
	int d[a];
	for(b=0; b<a; b++){
			d[b]=0;
		}
	for(b=0; b<a; b++){
			scanf("%d",&d[b]);
		}
		
	for(b=0; b<a; b++){
		c=d[b];
		e=b-1;
		while(e>=0 && d[e]>c){
			d[e+1]=d[e];
			e--;
			d[e+1]=c;
		}
		
		for(f=0; f<a; f++){
			printf("%d",d[f]);
			if(f==a-1){
				break;
			}
			printf(" ");
		}
		printf("\n");
	}

	return 0;
	
}


