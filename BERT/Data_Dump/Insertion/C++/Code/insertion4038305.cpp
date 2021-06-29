#include <stdio.h>

void trace(int*,int);
void insertionSort(int*,int);
int main()
{
  int hiroshi,mika,takuro,i,j,k;
  int takeshi[1000];

  scanf("%d",&k);
  for(i=0;i<k;i++)
    scanf("%d",&takeshi[i]);
    trace(takeshi,k);
    insertionSort(takeshi,k);
  
    return 0;
}

void trace(int takeshi[],int k){
  int i;
  for(i=0;i<k;i++){
    if(i>0)printf(" ");
    printf("%d",takeshi[i]);
  }
  printf("\n");
}

void insertionSort(int takeshi[],int k){
  int j,mika,takuro;
  for(j=1;j<k;j++){
    takuro=takeshi[j];
    mika=j-1;
    while(mika>=0 && takeshi[mika]>takuro){
      takeshi[mika+1]=takeshi[mika];
      mika--;
    }
    takeshi[mika+1]=takuro;
    trace(takeshi,k);
  }
}

