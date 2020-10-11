#include<stdio.h>
#include<stdlib.h>
void sellectionsort(int*,int);
int cnt=0;
int main(){
  int i,j;
  int *num;

  scanf("%d",&j);
  num=(int *)malloc(j * sizeof(int));
  for(i=0;i<j;i++)scanf("%d",&num[i]);
  sellectionsort(num,j);
  printf("%d",num[0]);
  for(i=1;i<j;i++)printf(" %d",num[i]);
  printf("\n");
  printf("%d\n",cnt);
  return 0;
}
void sellectionsort(int *num,int x){
  int j,key,minj,i;
  for(i=0;i<x;i++){
    minj=i;
    for(j=i;j<x;j++){
      if(num[j]<num[minj])minj=j;
    }
    if(i!=minj){
      key=num[i];
      num[i]=num[minj];
      num[minj]=key;
      cnt++;
    }
  }
}

