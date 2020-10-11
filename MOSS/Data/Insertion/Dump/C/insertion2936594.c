#include<stdio.h>
#include<stdlib.h>

int main(){
  int *ip;
  int i,j,n,v,k;
  scanf("%d",&n);
  if(n>=1&&n<=100){
    ip=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
      scanf("%d",&ip[i]);
      if(ip[i]<0||ip[i]>1000){
	fprintf(stderr,"数値が大きすぎます\n");
	exit(1);
      }
    }
    for(i=0;i<n;i++){
      if(i!=n-1)printf("%d ",ip[i]);
      else printf("%d",ip[i]);
    }
    printf("\n");
    for(i=1;i<n;i++){
      v=ip[i];
      j=i-1;
      while(j>=0&&ip[j]>v)
	{
	  ip[j+1]=ip[j];
	  j--;
	  ip[j+1]=v;
	}
      for(k=0;k<n;k++){
	if(k!=n-1)printf("%d ",ip[k]);
	else printf("%d",ip[k]);
      }
      printf("\n");
    }
  }
  return 0;
}

