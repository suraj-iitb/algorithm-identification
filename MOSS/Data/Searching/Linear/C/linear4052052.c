#include <stdio.h>

int main(void) 
{
  int n, q,i,z,count=0;
  int s[10000], t[500];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &s[i]);
  }
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &t[i]);
  }
  for(i=0;i<q;i++){
    for(z=0;z<n;z++){
      if(t[i] == s[z]){
	count++;
	break;
      }
    }
  }
  
  printf("%d\n", count);
  return 0;
}

