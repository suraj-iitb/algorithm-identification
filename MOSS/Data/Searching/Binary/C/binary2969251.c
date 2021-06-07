#include <stdio.h>
 
int int_cmp(const int *a, const int *b)
{
  if (*a < *b)
    return (-1);
  else if (*a > *b)
    return (1);
  return (0);
}
 
 
int main()
{
  int n,q,i,x,j;
  int array_n[100000];
  int array_q[50000];
  int count=0;
 
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&array_n[i]);
  }
  qsort(array_n,n,sizeof(array_n[0]),(int(*)(const void*, const void*))int_cmp);
 
  scanf("%d",&q);
  for (i=0;i<q;i++){
    scanf("%d",&x);
    int l=0;
    int r=n-1;
    int m;
    while (l<=r){
      m=(l+r)/2;
      if (array_n[m]==x){
        count++;
        break;
      }else if(array_n[m]<x){
        l=m+1;
      }else if(array_n[m]>x){
        r=m-1;
      }
    }
  }
 
  printf("%d\n",count);
 
  return 0;
}
