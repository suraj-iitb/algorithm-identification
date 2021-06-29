#include <stdio.h>

int main() {
  int n,hairetsu[101],i,j;

  scanf("%d",&n);
  for(i=0; i<n; i++) scanf("%d",&hairetsu[i]);
  int cnt=0;
  for(i=0; i<n; i++) {
    for(j=n-1; j>i; j--) {
      if(hairetsu[j]<hairetsu[j-1]) {
	int tmp=hairetsu[j];
	hairetsu[j]=hairetsu[j-1];
	hairetsu[j-1]=tmp;
	cnt++;
      }
    }
  }

  for(i=0; i<n; i++) {
    if(i) printf(" ");
    printf("%d",hairetsu[i]);
  }
  printf("\n%d\n",cnt);
  return 0;
}

