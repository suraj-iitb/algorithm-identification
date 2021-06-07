#include<stdio.h>
#define max 10000
main(){
  int i,j,n1,n2,f[max],s[max],count=0;
  scanf("%d",&n1);
  for(i=0;i<n1;i++)
    scanf("%d",&f[i]);
  scanf("%d",&n2);
  for(i=0;i<n2;i++)
    scanf("%d",&s[i]);
  for(i=0;i<n2;i++)
    for(j=0;j<n1;j++)
      if(f[j]==s[i]){
	count++;
	break;
      }
  printf("%d\n",count);
  return 0;
}
