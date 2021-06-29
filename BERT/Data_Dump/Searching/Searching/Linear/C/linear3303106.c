#include <stdio.h>
#define M 10000
#define N 500
#define NOT_FOUND -1

int cnt=0,n;

int linearsearch(int a[],int key)
{
  int i=0;
  a[n]=key;
  while(a[i]!=key)
    i++;
  if(i==n)return NOT_FOUND;
  return i;
}


int main(){
  int a[M],j[N],x,y,i;
  
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);

  scanf("%d",&y);
  for(i=0;i<y;i++)
  scanf("%d",&j[i]);

   for(i=0;i<y;i++)
     if(linearsearch(a,j[i])!=NOT_FOUND)cnt++;

   printf("%d\n",cnt);
   return 0;
}

