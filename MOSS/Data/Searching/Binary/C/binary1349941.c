#include<stdio.h>
#define N 100000
#define Q 50000

int main(){
  
  int s[N],t[Q],c=0;
  int i,n,q,a,b,x;
  
  scanf("%d",&n);
  for( i=0 ; i<n ; i++){
   scanf("%d",&s[i]);
 }
 
 scanf("%d",&q);
  for( i=0 ; i<q ; i++){
      scanf("%d",&t[i]);
    }
    
    
    for( i=0 ; i<q ; i++ ){
      a=0;
      b=n+1;
      while( a < b ){
	x=( a + b-1 )/2;
	if(t[i] == s[x]){
	  c++;
	break;
	}
	else if(t[i] > s[x])
	  a = x + 1;
	else if(t[i] < s[x])
	  b = x;
      }
    }
    
    printf("%d\n",c);
    return 0;
}
