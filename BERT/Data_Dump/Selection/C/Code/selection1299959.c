#include <stdio.h>
#define A 100

main(){
  int c,i,j,k,n,minj=0,count=0;
  int b[A];

  scanf("%d",&n);

  for(i=0;i<n;i++)scanf("%d",&b[i]);

  for(i=0;i<=n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(b[j]<b[minj])minj = j;
    }
    c = b[i];
    b[i] = b[minj];
    b[minj] = c;
    if(minj != i)count++;
  }
  
  for(i=0;i<n;i++){
    printf("%d",b[i]);
    if(i != n-1)printf(" ");
  }
  
  printf("\n%d\n",count);
  return 0;
}
