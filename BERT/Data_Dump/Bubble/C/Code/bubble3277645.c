#include<stdio.h>
#include<stdlib.h>
int bubbleSort(int *,int);
void swap(int *x,int *y);

int main(){
  int i,n,*m,count;
  scanf("%d",&n);
  m = (int *)malloc(n * sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&m[i]);
  }
  count = bubbleSort(m,n);
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

int bubbleSort(int *m,int n){
  int flag=1,i,count=0;
  while(flag){
    flag=0;
    for(i=n-1;i>0;i--){
      if(m[i]<m[i-1]){
        swap(&m[i],&m[i-1]);
        flag=1;
        count++;
      }
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
