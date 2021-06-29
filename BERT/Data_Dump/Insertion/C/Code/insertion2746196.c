/*
  挿入ソート
  2018/03/23
*/

#include<stdio.h>

void print(int *x,int n)
{
  int i;
  for(i=0;i<n-1;i++)
    printf("%d ",x[i]);
  printf("%d\n",x[i]);
}
int main(void)
{
  int a[100];
  int n;/*配列の要素数*/
  int temp;/*一時保存*/
  int i,j;
  fscanf(stdin,"%d",&n);
  
  for(i=0;i<n;i++)
    fscanf(stdin,"%d",&a[i]);
  print(a,n);
  
  for(i=1;i<n;i++){
    temp = a[i];
    j = i-1;
    while(j >= 0 && a[j] > temp){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = temp;
    print(a,n);
  }
  return 0;
}
