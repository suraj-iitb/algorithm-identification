/*
  選択ソート（数列Aを読み込み、選択ソートのアルゴリズムで昇順に並び替え
  　　　　　　出力するプログラム）
  2018/04/16
*/

#include<stdio.h>

#define MAX 100//Aの要素数

void swap(int *a,int i,int j)
{
  int temp;
  temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}
//Ｎこの要素を含む０-オリジンの配列
int selectionSort(int *a,int n)
{
  int i,j;
  int minj;
  int count;
  int sum=0;//比較回数の合計

  for(i=0;i<n;i++){
    minj = i;
    count = 0;
    for (j=i;j<n;j++)
      if(a[j] < a[minj]){
	minj = j;
	count = 1;
      }
    swap(a,i,minj);
    sum += count;
  }
  return sum;
}

int main(void)
{
  int a[MAX];
  int n;
  int i;
  int count = 0;

  fscanf(stdin,"%d",&n);
  for(i=0;i<n;i++)
    fscanf(stdin,"%d",&a[i]);

  count = selectionSort(a,n);

  for(i=0;i<n-1;i++)
    fprintf(stdout,"%d ",a[i]);
  fprintf(stdout,"%d\n%d\n",a[i],count);

  return 0;
}
