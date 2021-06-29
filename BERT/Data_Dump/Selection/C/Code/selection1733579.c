#include <stdio.h>
#define N 100
int selectionSort(int *,int);

int main(){
  int i,j,n,count;
  int in[N];

  /* input */  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&in[i]);
  }

  /* sort */
  count = selectionSort(in,n);

  /* output */
  for(i=0;i<n-1;i++){
    printf("%d ",in[i]);
  }
  printf("%d\n",in[i]);
  printf("%d\n",count);

  return 0;
}

int selectionSort(int *in,int n){
  int i,j,minj,count,tmp;

  count = 0;
  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if( in[j] < in[minj] ){
	minj = j;
      }
    }
    tmp = in[i];
    in[i] = in[minj];
    in[minj] = tmp;
    if( i != minj ){
      count++;
    }
  }
  return count;
}
