#include <stdio.h>

int main(){
  int t, c=0, i ,j, m, n, a[100];
  scanf("%d", &n);
  for(i=0; i<n; i++)scanf("%d", &a[i]);
  for(i=0; i<n; i++){
    m = i;
    for(j=i; j<n; j++){
      if(a[j]<a[m]) m = j;
    }
    if(m != i){
      t = a[i];
      a[i] = a[m];
      a[m] = t;
      c++;
    }
  }
  for(i=0; i<n-1; i++)printf("%d ", a[i]);
  printf("%d\n%d\n", a[i],c);
  return 0;
}
