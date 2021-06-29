#include<stdio.h>
void selectionSort(int*,int);
void listprint(int *,int);

int count=0;
int main(){
  int N,i;
  int A[100];
  scanf("%d",&N);
  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
    }
  selectionSort(A,N);
  listprint(A,N);
  printf("%d\n",count);
  return 0;
}
/*昇順*/
void selectionSort(int A[],int N)
{
  int i,j,minj,tmp;
  /*配列の先頭から*/
  for(i=0;i<N-1;i++)
    {
      minj=i;
      /*最小値を探す*/
      for(j=i;j<N;j++)
        {
          if(A[minj]>A[j])
            {
              minj=j;
            }
        }
      /*入れ替えた回数をカウント*/
      if(i!=minj)count++;
      /*入れ替え作業の実行*/
      tmp=A[i];
      A[i]=A[minj];
      A[minj]=tmp;
    }
}
void listprint(int A[],int N)
{
  int i;
  for(i=0;i<N;i++)
    {
      printf("%d",A[i]);
      if(i!=N-1)printf(" ");
    }
  printf("\n");
}



