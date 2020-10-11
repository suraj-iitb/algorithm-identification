#include<stdio.h>

int selectionsort(int *,int);
void swap(int *, int *);
int main(){
 int n,i,j;
  int A[100];//配列の宣言
  scanf("%d",&n);//数列の長さの入力
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);//配列の要素を入力
  }

    j=selectionsort(A,n);//並び換えを行う関数の呼出
  //交換した回数を変数jに保存
  
  //出力
  for(i=0;i<n;i++){
     if(i==n-1)
      printf("%d\n",A[i]);
      else{
      printf("%d ",A[i]);
      }
  }
  printf("%d\n",j);

  return 0;
}

int selectionsort(int *A,int n){
  int i,j,minj,count=0;
  for(i=0;i<=n-1;i++){
    minj=i;
    for(j=i;j<=n-1;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
   
    if(i!=minj){
     swap(&A[i],&A[minj]);
     count++;
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


