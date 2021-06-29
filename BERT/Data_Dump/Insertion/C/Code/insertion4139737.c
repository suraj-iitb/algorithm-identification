#include<stdio.h>
#define MAX 1000

//A[]にある数を　前からn番目から昇順に整列させ、A[]に再入力
//配列、n/ 埋め込む
void insertionSort(int *A,int  n){
  int i,j;
  int key;

  for(i=1;i<=n-1;i++){
    key=A[i];
       
    for(j=i-1;j>=0&&A[j]>key;j--){
      A[j+1]=A[j];
    }
    A[j+1]=key;
     
    for(j=0;j<n;j++){//経過を見るため
      if(j)  printf(" ");
      printf("%d",A[j]);
    }
    printf("\n");
  }
}


int main(){
  int i,j,n;
  int A[MAX];//need
  
  scanf("%d",&n);//input
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<n;i++){//output
    if(i)printf(" ");
    printf("%d",A[i]);
  }

  printf("\n");
  insertionSort(A, n);
   
  return 0;
}

/*
3
3 2 1
を昇順に並べる
経過も出力
 */

