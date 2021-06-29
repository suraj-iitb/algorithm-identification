#include <stdio.h>

int main(){
  int n, i, j, t, c = 0;
  int a[100];

  scanf("%d", &n);

  for(i=0; i<n; i++)
    scanf("%d",&a[i]);
  
  for(i=0; i<n; i++)
    for(j=n-1; j>i; j--)
      if(a[j-1] > a[j]){
        t = a[j-1];
        a[j-1] = a[j];
        a[j] = t;
        c++;
      }
  
  for(i=0; i<n; i++)
    printf("%d%c", a[i], i==n-1 ? '\n' : ' ');
  printf("%d\n", c);    

  return 0;
}

