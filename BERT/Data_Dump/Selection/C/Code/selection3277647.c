#include<stdio.h>
#include<stdlib.h>
int selectionSort(int *,int);
void swap(int *,int *);
int main(){
  int i,n,*m,count;
  scanf("%d",&n);
  m = (int *)malloc(n * sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&m[i]);
  }
  count = selectionSort(m,n);
  for(i=0;i<n;i++){
    printf("%d",m[i]);
    if(i!=n-1){
      printf(" ");
    }
    else printf("\n");
  }
  printf("%d\n",count);
  return 0;
}

int selectionSort(int *m,int n){
  int count=0,i,j,minj;
  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(m[j]<m[minj]){
        minj = j;
      }
    }
    if(minj!=i){
      swap(&m[i],&m[minj]);
      count++;
    }
  }
  return count;
}

void swap(int *x,int *y){
  int r;
  r=*x;
  *x=*y;
  *y=r;
}
