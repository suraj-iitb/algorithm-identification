/*
  バブルソート（数列 A を読み込み、バブルソートで昇順に並び変え出力するプログラム）
  2018/04/10
*/

#include<stdio.h>

#define MAX 100

void swap(int *a,int i,int j)
{
  int temp;
  temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

int bubbleSort(int *a,int n)
{
  int i;
  int count=0;//要素の交換回数
  int flag;//逆の隣接要素が存在する
  
  flag = 1;
  while(flag){
    flag = 0;
    for(i=n-1;0<i;i--)
      if(a[i]<a[i-1]){
	swap(a,i,(i-1));
	count+=1;
	flag = 1;
      }
  }
  return count;
}

int main(void)
{
  int a[MAX];/*数列A*/
  int n;/*数列Aの要素数*/
  int count = 0;//要素の交換回数
  int i;
  
  //数列の要素数を読み込む
  fscanf(stdin,"%d",&n);

  //数列を読み込む
  for(i=0;i<n;i++)
    fscanf(stdin,"%d",&a[i]);

  count = bubbleSort(a,n);

  for(i=0;i<n-1;i++)
    printf("%d ",a[i]);
  printf("%d\n%d\n",a[i],count);

  return 0;
}
