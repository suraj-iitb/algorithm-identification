#include<stdio.h>
#define MAX 100

int main(){
  int i,k,j[MAX],h,d,g;
  scanf("%d",&i);
  for(k=0;k<i;k++){
  scanf("%d",&j[k]);
  }
  for(k=0;k<i-1;k++){
      printf("%d ",j[k]);
  }
  printf("%d\n",j[k]);
  
  for(h=1;h<i;h++){
    d=j[h];
    g=h;
    while(j[g-1]>d&&g>0){
      j[g]=j[g-1];
      g--;
    }
    j[g]=d;
    for(k=0;k<i-1;k++){
      printf("%d ",j[k]);
    }
    printf("%d\n",j[k]);
  }
  return 0;
}

