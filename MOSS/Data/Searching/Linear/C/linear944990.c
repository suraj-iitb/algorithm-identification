#include <stdio.h>
#define N 10000
#define Q 500
main(){
  int array1[N],array2[Q],i,j,c=0,n,m;

  scanf("%d%",&n);
  for(i=0;i<n;i++){
    scanf("%d%",&array1[i]);
  }

  scanf("%d%",&m);
  for(j=0;j<m;j++){
    scanf("%d%",&array2[j]);
  }

  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      if(array2[i]==array1[j]){
	c++;
	break;
      }
    }
  }

  printf("%d\n",c);
  return 0;
}
