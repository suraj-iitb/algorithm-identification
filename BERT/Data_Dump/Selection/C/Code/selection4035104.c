#include<stdio.h>
#include<stdlib.h>
int selectionSort(int *,int);

int main(){
  int *akira;
  int i,count,n;

  scanf("%d",&n);
  akira=(int *)malloc(sizeof(int)*n);

  for(i=0;i<n;i++){
    scanf("%d",&akira[i]);
  }
  
  count=selectionSort(akira,n);
  
  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",akira[i]);
  }
  printf("\n%d\n",count);
  
  return 0;
}
int selectionSort(int *akira,int n){
  int i,j,tmp,minj,count=0;

  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(akira[j]<akira[minj]) minj=j;
    }
    if(minj!=i){
      count++;
      tmp=akira[i];
      akira[i]=akira[minj];
      akira[minj]=tmp;
    }
  }
  return count;
}

