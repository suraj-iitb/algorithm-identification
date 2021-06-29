#include <stdio.h>
#define A 100

main(){
  int c,i,n,flag=1,count=0;
  int b[A];

  scanf("%d",&n);

  for(i=0;i<n;i++)scanf("%d",&b[i]);

  while(flag){
    flag=0;
    for(i=n-1;i>0;i--)
      if(b[i]<b[i-1]){
	c = b[i-1];
	b[i-1] = b[i];
	b[i] = c;
	count++;
	flag=1;
      }
  }

  for(i=0;i<n;i++){
    printf("%d",b[i]);
    if(i != n-1)printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}
