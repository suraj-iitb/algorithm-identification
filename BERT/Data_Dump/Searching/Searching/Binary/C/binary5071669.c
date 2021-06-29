#include<stdio.h>
/*外部変数*/
int A[100000],n;

int binarySearch(int key)
{
  int Left =0,Right=n,Mid;
  /*1 2 3 4 5*/
  while(Left<Right)
    {
      Mid=(Left+Right)/2;
      if(key==A[Mid])
        {
          return Mid;
          break;
        }
      if(key>A[Mid])Left=Mid+1;
      else if(key<A[Mid])Right=Mid;
    }
  return 0;
}
int main()
{
  int i,j,key,count=0;
  scanf("%d\n",&n);
  /*1 2 3 4 5*/
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }
  scanf("%d",&j);
  for(i=0;i<j;i++)
     {
       /*3 4 1*/
       scanf("%d",&key);
       if(binarySearch(key))count++;
     }
   printf("%d\n",count);
   return 0;
}

