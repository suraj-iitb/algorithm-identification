#include<stdio.h>
#define N 100
int selectionSort(int [],int);

int main(){
  int n,a[N],i,cnt=0;
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  } 

  cnt=selectionSort(a,n);

  printf("%d",a[0]);
  for(i=1;i<n;i++){
    printf(" %d",a[i]);
  }
  printf("\n");
  printf("%d\n",cnt);

  return 0;
}

int selectionSort(int x[],int y){
  int i,j,tmp,count=0,minj;

  for(i=0;i<y-1;i++){
    minj=i;
    for(j=i;j<y;j++){
      if(x[j]<x[minj]){
	minj=j;
      }
    }
    tmp=x[i];
    x[i]=x[minj];
    x[minj]=tmp;
    if(i!=minj)
      count++;
  }
  return count;
}

