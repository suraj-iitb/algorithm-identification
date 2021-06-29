#include <stdio.h>

int main() {

  int i,j,k,c;
  int  a[101],flag;
  int t,n,minj;

  scanf("%d",&n);

  for(i=0;i<n;i++) {

    scanf("%d",&a[i]);

  }

  c = 0;
  
  for(i=0;i<=n-1;i++) {
    minj = i;
    flag = 0;

    for(j=i; j<=n-1; j++) {
      if(a[j] < a[minj]) {
	minj = j;
	flag = 1;
	
      }
    }

    if(flag == 1) {
      t = a[i];
      a[i] = a[minj];
      a[minj] = t;
      c++;
      
    }


  }
 








  for(i = 0; i<n;i++) {

    printf("%d",a[i]);

    if(i != n-1) printf(" ");

  }

  printf("\n%d\n",c);

  return 0;



}

