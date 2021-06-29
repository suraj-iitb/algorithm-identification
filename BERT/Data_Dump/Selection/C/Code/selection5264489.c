#include<stdio.h>
#define N 101



int A[N];
int n;
int cnt=0;



void select(){

  int i,j;
  int min,minj;
  int t;

  for(i=0;i<n;i++){
    min=A[i];
    minj=i;
    for(j=i;j<n;j++){
      if(min>A[j]){
        min=A[j];
        minj=j;
      }
    }

    if(minj!=i){
      t=A[minj];
      A[minj]=A[i];
      A[i]=t;
      cnt++;
    }
  }
}








int main(){

  int i,j;


  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }



  select();


  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",cnt);















  return 0;
}

