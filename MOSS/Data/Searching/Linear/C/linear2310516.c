#include<stdio.h>
#include<stdlib.h>

int linearSearch(int * ,int, int);

int main(){

  int i,count=0;
  int insertNumber1,insertNumber2,*S,*T;

  scanf("%d",&insertNumber1);
  S=(int *) malloc(sizeof(int)*insertNumber1);
  for(i=0;i<insertNumber1;i++) scanf("%d",&S[i]);
  scanf("%d",&insertNumber2);
  T= (int *) malloc(sizeof(int)*insertNumber2);
  for(i=0;i<insertNumber2;i++) {
    scanf("%d",&T[i]);
  }

  for(i=0;i<insertNumber2;i++) {
    count+=linearSearch(S,T[i],insertNumber1);
  }

  printf("%d\n",count);

  return 0;
}
int linearSearch(int *S,int key,int insertNumber){

  int i=0;
  S[insertNumber]=key;
  while(S[i]!=key){
    i++;
    if(i==insertNumber) return 0;
  }

  return 1;
}
