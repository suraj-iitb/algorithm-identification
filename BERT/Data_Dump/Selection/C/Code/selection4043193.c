#include <stdio.h>
#define N 100
#define A 100

int main(){
  int a,b[N],i,j,minj,k,count=0;

  scanf("%d",&a);
  
  for(i=0;i<a;i++){
    scanf("%d",&b[i]);
  }

  for(i=0;i<a;i++){

    minj = i;
    // printf("%d\n",i);

    for(j=i;j<a;j++){
      if(b[j] < b[minj]){
	minj = j;
      }
    }
    if(minj!=i){
      k = b[i];
      b[i] = b[minj];
      b[minj] = k;
      count++;
    }
  }
  for(k=0;k<a-1;k++)
  printf("%d ",b[k]);
  printf("%d",b[k]);
  printf("\n");
  printf("%d\n",count);
  


  
  return 0;
}
      
      
    

