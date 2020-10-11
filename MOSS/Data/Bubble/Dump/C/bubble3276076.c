#include<stdio.h>
#define N 100
int bubblesort(int * ,int);
void swap(int *,int *);

int main(){
  int n,i,j;
  int A[N];//配列の宣言
  scanf("%d",&n);//数列の長さの入力
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);//配列の要素を入力
  }
  
    j=bubblesort(A,n);//並び換えを行う関数の呼出
    //並び換えをした回数を変数jに保存

  //出力
  for(i=0;i<=n-1;i++){
    if(i==n-1)
      printf("%d\n",A[n-1]);//一番最後の出力に余計な空白を出力しない
    else{
      printf("%d ",A[i]);
    }
  }
  printf("%d\n",j);//並び換え回数の出力

  return 0;
}
int bubblesort(int *A,int n){
  int i,j,count=0;
  for(i=0;i<=n-1;i++){
    for(j=n-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	swap(&A[j],&A[j-1]);
      count++;
      }
    }
  }
   return count;
}
 

  
void swap(int *a,int *b){
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}

