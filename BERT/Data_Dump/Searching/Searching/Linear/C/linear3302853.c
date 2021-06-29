#include <stdio.h>
#define N 10000
#define Q 500
#define NOT_FOUND -1



int count=0,n;

int linear(int a[],int key){
  int i=0;
  a[n]=key;
  while(a[i]!=key)
    i++;
  if(i==n)return NOT_FOUND;
  return i;
}




int main(){
  int a[N],b[Q],i,q;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++)
    scanf("%d",&b[i]);

  for(i=0;i<q;i++)
    if(linear(a,b[i])!=NOT_FOUND)count++;

  printf("%d\n",count);
  return 0;
}



