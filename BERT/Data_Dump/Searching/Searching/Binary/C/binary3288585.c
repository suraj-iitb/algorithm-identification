#include<stdio.h>


int main (){

  int S[100000],T[50000];
  int s,t,i,j=0,l,r,m=0;
  
  

  scanf("%d",&s);

  for(i=0;i<s;i++)
    scanf("%d",&S[i]);

  scanf("%d",&t);

  for(i=0;i<t;i++)
    scanf("%d",&T[i]);

   for(i=0;i<t;i++){
     l = 0;
     r = s;
     while(l<r){
       m = (l+r)/2;
       if(S[m]==T[i]){
	 j++;
	 break;
       }
       else if(T[i]<S[m])
	 r = m;
       else
	 l = m+1;
     }
   }
    printf("%d\n",j);
  return 0;
}
    

