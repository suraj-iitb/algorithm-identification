#include <stdio.h>

int main(){
  int n, i, j, t, min, c = 0;
  int a[100];

  scanf("%d", &n);

  for(i=0; i<n; i++)
    scanf("%d",&a[i]);
  
  for(i=0; i<n; i++){
    min = i;
    for(j=i; j<n; j++)
      if(a[j] < a[min])
        min = j;

    if(i != min)
      c++;

    t = a[i];
    a[i] = a[min];
    a[min] = t;
  }
  
  for(i=0; i<n; i++)
    printf("%d%c", a[i], i==n-1 ? '\n' : ' ');
  printf("%d\n", c);    

  return 0;
}

