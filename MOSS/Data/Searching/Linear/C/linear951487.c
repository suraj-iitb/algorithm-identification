#include <stdio.h>
#define N 10000
#define Q 500
main(){
  int s,t,c=0,i,j;
  int a[N],b[Q];

  scanf("%d",&s);
  for(i = 0; i < s; i++){
    scanf("%d",&a[i]);
  }

  scanf("%d",&t);
  for(i = 0; i < t; i++){
    scanf("%d",&b[i]);
  }

  for(i = 0; i < t; i++){
    for(j = 0; j < s; j++){
      if(b[i] == a[j]){
	c++;
	break;
      }
    }
  }
  printf("%d\n",c);
  return 0;
}
