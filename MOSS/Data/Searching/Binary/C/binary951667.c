#include <stdio.h>
#define N 100000
#define Q 50000
main(){

  int s,t,c=0,i,j,m,r,l;
  int a[N],b[Q],d[N];
  scanf("%d",&s);
  for(i = 0; i < s; i++){
    scanf("%d",&a[i]);
  }
    scanf("%d",&t); 
   for(i = 0; i < t; i++){
      scanf("%d",&b[i]);   
      d[i] = b[i];
      r = s;
      l = 0;
      while(l < r){
	m = (r + l) / 2;
	if(b[i] == a[m])
	  {
	    c++;
	    break;
	  }
	else if(b[i] > a[m]) l = m + 1;
	else if(b[i] < a[m]) r = m;
      }
   }
printf("%d\n",c);
 return 0;
}
