#include <stdio.h>

void trace(int a[],int N){
  int k;
  for(k=0;k<N;k++){
      if(k>0){
         printf(" ");
      }
    printf("%d",a[k]);
    }
  printf("\n");
}

void insertionsort(int a[],int N){
  int i,j,v;
  for(i=1;i<N;i++){
    v=a[i];
    j=i-1;
    while(j>=0&&a[j]>v){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
    trace(a,N);
  }
}

int main(void)
{
  int N,i,j,a[100];

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
  }
  trace(a,N);
  insertionsort(a,N);
      
  return 0;
}

    
  
