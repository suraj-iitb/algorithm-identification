#include<stdio.h>
int main(){
  int i=0,j=0,k=0;
  int N=0,temp=0;
  int num[100];
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&num[i]);
  }
  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",num[i]);
  }
  printf("\n");
  for(i=1;i<N;i++){
    temp=num[i];
    j=i-1;
    while(j>=0&&num[j]>temp){
      num[j+1]=num[j];
      j--;
    }
    num[j+1]=temp;
    for(k=0;k<N;k++){
      if(k>0)printf(" ");
      printf("%d",num[k]);
    }
    printf("\n");
  }
  return 0;
}

