#include <stdio.h>

int main() {

  int n,c;
  int a[101] = {0};
  int d,i,j;
  int flag;


  scanf("%d",&n);

  c = 0;

  for(i = 0;i<n;i++) {

    scanf("%d" ,&a[i]);

  }

  flag = 1;

  while(flag) { 
    flag = 0;

    for(j=n-1;j>=1;j--) {
      
      if(a[j] < a[j-1]) {
	d = a[j];
	a[j] = a[j-1];
	a[j-1] = d;
	c++;
	flag = 1;
      } 
    }
    
  }

  for(i=0;i<n;i++) {
    printf("%d",a[i]);
    if(i != n-1) printf(" ");

}
  printf("\n%d\n",c);

  return 0;

}


