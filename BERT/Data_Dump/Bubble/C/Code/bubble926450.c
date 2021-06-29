#include <stdio.h>
#define N 100
void Tr(int m[], int n){
  int i;
  for ( i = 1; i <= n; i++ ){
    if ( i > 1 ) printf(" ");
    printf("%d", m[i]);
  }
  printf("\n");
}
int main(void)
{
  int m[N+1],i,j,key,n,count=0;
  scanf("%d",&n);
  for(i=1 ; i<n+1 ; i++){
      scanf("%d",&m[i]);
    }
  for(i=1 ; i<n+1 ; i++){
      for(j=n ; j >= i+1 ; j--)
    {
      if(m[j] < m[j-1]){
          key = m[j];
          m[j] = m[j-1];
          m[j-1] = key;
          count++;
        }
    }
  }
  Tr(m, n);
  printf("%d\n",count);
  return 0;
}
