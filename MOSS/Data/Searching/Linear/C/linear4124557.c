#include <stdio.h>

int ST(int hi[],int n,int key);
int main()
{
  int i,n,q,key,count=0;
  int hi[10001];

  scanf ("%d",&n);
  for (i=0;i<n;i++)
    scanf("%d",&hi[i]);
  scanf ("%d",&q);
  for (i=0;i<q;i++){
    scanf ("%d",&key);
    if ( ST(hi,n,key) )
      count++;
  }
  printf ("%d\n",count);
  return 0;
}
  

int ST (int hi[],int n,int key){
  int i=0;
  hi[n]=key;
  while(hi[i]!=key)
    i++;
  return i!=n;
}
  

