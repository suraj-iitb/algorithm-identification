#include<stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
  char mar;
  int  id,num;
} car;

void swap(car *a,car* b){
  car t=*a;*a=*b,*b=t;
}

int partition(car *A,int p,int r){
  int x=A[r].num,i=p-1,j;
  for(j=p;j<r;j++){
    if(A[j].num<=x){
      i=i+1;
      swap(&A[i],&A[j]);
    }
  }
  swap(&A[i+1],&A[r]);
  return i+1;
}



int isStable(car *a,int n){
  int i;
  for(i=0;i<n-1;i++){
    if(a[i].num==a[i+1].num && a[i].id>a[i+1].id)return 0;
  }
  return 1;
}

void quickSort(car *A,int p,int r){
  if(p<r){
    int q=partition(A,p,r);
    quickSort(A,p,q-1);
    quickSort(A,q+1,r);
  }
}


int main(void){

  car A[100000];
  int i,n;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf(" %c %d",&A[i].mar,&A[i].num);
    A[i].id=i;
  }
  quickSort(A,0,n-1);
  printf("%s\n",isStable(A,n)?"Stable":"Not stable");

  for(i=0;i<n;i++){
    printf("%c %d\n",A[i].mar,A[i].num);
  }
  return 0;
}

