#include<stdio.h>
 
#define N 10000
#define Q 500
 
int main()
{
  int i, j, count=0,m,n;
  int S[N], T[Q];
   
  scanf("%d", &S[0]);
  for(i=1; i<S[0]+1; i++)
    {
      scanf("%d", &S[i]);
    }
  scanf("%d", &T[0]);
       for(j=1; j<T[0]+1; j++){
	 scanf("%d",&T[j]);
	 for(i=1; i<S[0]; i++){
	   if(S[i]==T[j]){
	     count++;
	     break;
	   }
	 }
       }
       printf("%d\n",count);
       return 0;
}
