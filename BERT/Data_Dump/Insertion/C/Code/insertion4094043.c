#include<stdio.h>
#define N 100
int main(){
  int i,j,tmp;
  int number[N];
  int total;
  scanf("%d",&total);
  for(i=0;i<total;++i)
    scanf("%d",&number[i]);

  for(i=0;i<total;++i){
    tmp=number[i];
    j=i-1;
    while(j>=0 && number[j]>tmp){
      number[j+1]=number[j];
      --j;
    }
    number[j+1]=tmp;
    for(j=0;j<total;++j){
      if(j)
        printf(" ");
      printf("%d",number[j]);
    }
    printf("\n");
  }
  return 0;
}


