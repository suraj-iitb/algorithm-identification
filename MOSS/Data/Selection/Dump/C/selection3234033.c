#include<stdio.h>

int main(void){
   int N,i,j,a[100],v,minj,cnt=0,kari;
   scanf("%d",&N);
   for(i=0;i<N;i++)
	scanf("%d",&a[i]);
	
	for(i=0;i<N;i++){
		minj=i;
		for(j=i;j<N;j++){
			if(a[j]<a[minj])
			minj=j;
		}
		
			kari=a[i];
			a[i]=a[minj];
			a[minj]=kari;
			if(i!=minj)
			cnt++;
	}
	
	 for(j=0;j<N;j++){
printf("%d",a[j]);
while(j!=N-1){
putchar(' ');
break;
}
}

putchar('\n');
printf("%d\n",cnt);


	return 0;
}
