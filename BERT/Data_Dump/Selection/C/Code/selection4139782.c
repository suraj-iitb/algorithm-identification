#include<stdio.h>
#define MAX 100

int swap(int *x,int *y){
  int z=*x;
  if(*x==*y)return 0;//同じだったら０
  *x=*y;
  *y=z;
  return 1;//違ったら１
}

// N個の要素を含む0-オリジンの配列A
//Aの数を並べ替えて入れ直す
//    / 交換が行われた回数
int selectionSort(int *A,int n){ 
  int i;
  int j;
  int minj;
  int count=0;
  
  for (i=0;i<=n-1;i++){
    minj = i;
    
    for (j=i;j<=n-1;j++){
      if (A[j] < A[minj]) minj=j;
    }
    if(swap(&A[i], &A[minj]))count++;
  }
  return count;
}


int main(){
  int i;
  int n;
  int A[MAX];
  int count=0;
 
  scanf("%d",&n);//Input
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  count=selectionSort(A,n);


  for(i=0;i<n;i++){//OUTPUT
    if(i)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",count);

    
  return 0;
}
//
//3
//1 3 4を昇順に

