#include <stdio.h>

#define Max 10000
#define max 500

main(){
  int n[Max],q[max];
  int a,b,i,j,count=0;

  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&n[i]);
  }
  scanf("%d",&b);
  for(j=0;j<b;j++){
    scanf("%d",&q[j]);
  }

  for(i=0;i<b;i++){
    for(j=0;j<a;j++){
      if(n[j] == q[i]){
	count++;
	break;
      }
    }
  }
  
  printf("%d\n",count);
  return 0;
}
