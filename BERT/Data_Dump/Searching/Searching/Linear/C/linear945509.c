#include <stdio.h>
#define N 10000
#define Q 500 
main(){
  int s,t,i,j,count=0;
  int a[N],b[Q];
  scanf("%d", &s);
  for(i=0;i<s;i++)
  {
    scanf("%d", &a[i]);
  }
  scanf("%d", &t);
  for(i=0;i<t;i++)
  {
    scanf("%d", &b[i]);
  }
for(j=0;j<t;j++)
  {
  for(i=0;i<s;i++)
     {
      if(a[i] == b[j])
	{
        count+=1;
        break;
	}
     }
   }
  printf("%d\n", count);
  return 0;
}     
