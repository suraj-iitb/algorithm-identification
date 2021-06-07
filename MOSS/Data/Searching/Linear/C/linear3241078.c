#include <stdio.h>
 
int main()
{
  int n,m,i,j,count=0;
  scanf("%d",&n);
  int a[n];
  for(i=0; i<n; i++) scanf("%d",&a[i]);
  scanf("%d",&m);
  for(i=0; i<m; i++) {
    int x;
    scanf("%d",&x);
    for(j=0; j<n; j++) {
      if(a[j]==x) {
    count++;
    break;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}

