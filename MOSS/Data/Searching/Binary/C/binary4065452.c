#include <stdio.h>
int binary(int );
int S[100000],n;
int main()
{
  int i,j,a,goukei =0;
  scanf("%d",&n);
  for(i=0; i<n; i++)
    {
      scanf("%d",&S[i]);
    }
  scanf("%d",&a);
  for( i=0; i<a; i++)
    {
      scanf("%d",&j);
      if(binary(j)) goukei++;
    }
  printf("%d\n",goukei);
  return 0;
}


int binary(int x)
{
  int le=0,ri=n,mid;

  while(le<ri)
    {
      mid =(le+ri)/2;
      if(x==S[mid]) return 1;
      if(x>S[mid]) le =mid+1;
      if( x<S[mid]) ri= mid;
    }
  return 0;
}
  

