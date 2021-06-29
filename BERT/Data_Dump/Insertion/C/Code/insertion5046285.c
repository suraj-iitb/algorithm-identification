#include<stdio.h>
void listprint(int A[],int N);
void insertionSort(int A[],int N);

int main(){
  int N,i,j;
  int A[1000];

  scanf("%d",&N);
  for(i=0;i<N;i++){
      scanf("%d",&A[i]);
    }
  listprint(A,N);
  insertionSort(A,N);

  return 0;
}


void listprint(int A[],int N){
  int i;
  for(i=0;i<=N-1;i++){
    if(i>0)printf(" ");                                                        \

    printf("%d",A[i]);
  }
  printf("\n");
}

void insertionSort(int A[],int N){
  int i,j,v;/*v:=値を保持,N:=数列の長さ,i:=未ソート,j:=ソート済み*/
  for(i=1;i<N;i++){
    v=A[i];
    j=i-1; /*|未ソート部分|の先頭から探し出す*/
    while(j>=0 && A[j]>v){/*|ソート済み|のj番目の要素がv(A[i])よりも大きいとき*\
/
      A[j+1]=A[j]; /*要素を右にずらす*/
      j--;
    }
      A[j+1]=v;//見つけたらそこに入れる                                         
      listprint(A,N);
    }
}


