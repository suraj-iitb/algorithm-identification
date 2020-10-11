#include<stdio.h>
#define N 1000
int main(){
  int key,num,i,j,k,math[N];
  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&math[i]);
  }
  printf("%d",math[0]);
  for(k=1;k<num;k++){
    printf(" %d",math[k]);
  }
  

  for(i=1;i<num;i++){
    key = math[i];
    j = i-1;
    while(j>=0 && math[j]>key){
      math[j+1]=math[j];
      j--;
    }
    math[j+1] = key;
    printf("\n");
    printf("%d",math[0]);
    for(k=1;k<num;k++){
      printf(" %d",math[k]);
    }
   
  }
  printf("\n");
}

