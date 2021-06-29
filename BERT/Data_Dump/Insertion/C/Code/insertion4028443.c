#include <stdio.h>
int main (){
    int x,n[100],i,tmp,j,k;
    scanf("%d",&x);
    for(i=0;i<x;i++){
        scanf("%d",&n[i]);
    }
    for(i=0;i<x;i++){
      printf("%d",n[i]);
      if(i<x-1)printf(" ");
    }
    printf("\n");
    for(i=1;i<x;i++){
      tmp=n[i];
      j=i-1;
      while((j>=0)&&(n[j]>tmp)){
	n[j+1]=n[j];
	j--;
      }
      n[j+1]=tmp;
      for(k=0;k<x;k++){
	printf("%d",n[k]);
	if(k<x-1)printf(" ");
      }
      printf("\n");
    }
    return 0;
}

