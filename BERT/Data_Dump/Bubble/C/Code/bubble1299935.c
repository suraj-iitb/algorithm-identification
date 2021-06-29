#include<stdio.h>
#define N 100


main(){

  int i,j,c[N],n,t,s=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&c[i]);
  }
  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(c[j]<c[j-1]){
	t=c[j];
	c[j]=c[j-1];
	c[j-1]=t; 
	s++;
      }
    }

  }
 
 for(i=0;i<n-1;i++){
   
    printf("%d ",c[i]);
 }
 printf("%d\n",c[n-1]);

 printf("%d\n",s);
 return 0;
}
