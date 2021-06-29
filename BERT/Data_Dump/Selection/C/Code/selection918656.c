#include <stdio.h>

main(){
  int i,j,len,mini,count=0,A[100],tmp;
  
  scanf("%d",&len);
  for(i=0;i<len;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<len;i++){
    mini=i;
    for(j=i;j<=len-1;j++){
      if(A[j]<A[mini]){
	mini=j;    
      }
    }
    if(mini!=i)count++;
    tmp=A[i];
    A[i]=A[mini];
    A[mini]=tmp; 
  }
  
  for(i=0;i<len;i++){
    printf("%d",A[i]);
    if(i<len-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
