/* Insert Sort(挿入ソート) */
/* N 個の要素を含む数列 A を昇順に並び替える挿入ソートのプログラム */
/* 入力: 入力の最初の行に、数列の長さを表す整数 N が与えられます。2 行目に、N 個の整数が空白区切りで与えられます。 */
/* 出力: 出力は N 行からなります。挿入ソートの各計算ステップでの途中結果を 1 行に出力してください。配列の要素は１つの空白で区切って出力してください。最後の要素の後の空白など、余計な空白や改行を含めると Presentation Error となりますので注意してください。 */

#include <stdio.h>

void insertionSort(int *,int);
void abc(int *,int);

int main()
{
  
  int i,N,A[1000];

  scanf("%d",&N);
    
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  
  abc(A,N);
  insertionSort(A,N);
    
  return 0;
}


void abc(int *A,int N)
{
  int i;
  for(i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}


void insertionSort(int *A,int N)
{
  
  int i,j,k;

  for(i=1;i<N;i++){
    k=A[i];
    j=i-1;
    
    while(j>=0&&A[j]>k){
      A[j+1]=A[j];
    j--;
    }
    A[j+1]=k;
    abc(A,N);
  }
}

