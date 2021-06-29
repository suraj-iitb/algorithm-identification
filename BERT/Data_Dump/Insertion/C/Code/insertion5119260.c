#include<stdio.h>
#include<stdlib.h>
#define N 1000

int main()
{
  int i,j,s,key,a[N],h;

  scanf("%d",&s);
  if(s<1||s>100)exit(2);
  for(i=0;i<s;i++)
    {
      scanf("%d",&a[i]);
    }
  printf("%d",a[0]);
  for(i=1;i<s;i++)printf(" %d",a[i]);
  printf("\n");
  for(i=1;i<s;i++)
    {
key = a[i];
      j = i - 1;
      while(j >=0&&a[j]>key)
        {
          a[j+1] = a[j];
          j--;
        }
      a[j+1] = key;
      printf("%d",a[0]);
      for(j=1;j<s;j++){

     printf(" %d",a[j]);
        }
      printf("\n");

    }
return 0;
}
