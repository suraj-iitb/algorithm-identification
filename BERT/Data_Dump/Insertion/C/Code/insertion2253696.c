#include<stdio.h>
#define N 100
int main(){
  int a,b,j,i,key;
  int kazu[N];
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&kazu[i]);
  }
  for(i=1;i<a;i++){
    key=kazu[i];
    b=i-1;
    for(j=0;j<a-1;j++){
      printf("%d ",kazu[j]);
    }
    printf("%d\n",kazu[j]);
    while(b>=0 && kazu[b]>key){
      kazu[b+1]=kazu[b];
      b=b-1;
      kazu[b+1]=key;
    }
  }
  for(j=0;j<a-1;j++){
    printf("%d ",kazu[j]);
  }
  printf("%d\n",kazu[j]);
  return 0;
}
   
