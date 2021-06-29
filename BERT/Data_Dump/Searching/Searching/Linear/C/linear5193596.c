#include <stdio.h>

int main() {
  int n,s,t,count=0;
  
  scanf("%d",&n);
  int a[n];
  for(int i=0; i<n; i++)  
  scanf("%d",&a[i]);
  scanf("%d",&s);
  for(int i=0; i<s; i++) {
    scanf("%d",&t);
    for(int j=0; j<n; j++) {
      if(a[j]==t) {
	count++;
	break;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}

