#include<stdio.h>

int main(void){
   int N,i,a[1000],v,j;
   scanf("%d",&N);
   for(i=0;i<N;i++)
	scanf("%d",&a[i]);
	
	for(i=1;i<=N;i++){
		 for(j=0;j<N;j++){
printf("%d",a[j]);
while(j!=N-1){
putchar(' ');
break;
}
}
putchar('\n');

		v=a[i];
		j=i-1;
		while(j>=0 && a[j]>v){
			a[j+1]=a[j];
			j--;
			a[j+1]=v;
		}
	}

return 0;
}
