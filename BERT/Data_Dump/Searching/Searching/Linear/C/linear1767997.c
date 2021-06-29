#include<stdio.h>
#define N 10000
#define Q 500
int linearSearch(int);
int n,S[N];
int main()
{
  int   q,i,j,count=0,T[Q],key;

  scanf("%d",&n);
  for(i=0;i<=n-1;i++){
    scanf("%d",&S[i]);
}

  scanf("%d",&q);
  for(j=0;j<=q-1;j++){
    scanf("%d",&T[j]);
    if(linearSearch(T[j])==1)
    count++;
}
 
  /* for(i=0;i<=n-1;i++){
   key=S[i];
   for(j=0;j<=q-1;j++){
     if(T[j]==key)
       count++;
     
   }
 }
  */
 printf("%d\n",count);
 return 0;
}
int linearSearch(int key)
{
  int i;
 
  for(i=0;i<n;i++){
    if(S[i]==key) return 1;
 }
return 0;
}
