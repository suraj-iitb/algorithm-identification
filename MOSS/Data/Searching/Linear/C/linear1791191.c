#include <stdio.h>




int main(){
  int i,j=0;
  int s,t;
  int count=0;
  int key;

  scanf("%d",&s);
  int S[s];
  for(i=0;i<s;i++)scanf("%d",&S[i]);


  scanf("%d",&t);
  int T[t];
  for(i=0;i<t;i++)scanf("%d",&T[i]);

  for(i=0;i<t;i++){

    key=T[i];
    j=0;
    S[s]=key;
    while(S[j]!=key)j++;


     if(j==s);
    else{
       count++;
    }
 

  }

  printf("%d\n",count);
   return 0;
}
