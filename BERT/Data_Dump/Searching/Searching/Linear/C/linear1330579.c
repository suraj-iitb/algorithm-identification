#include<stdio.h>
#define N 10000
#define Q 500

int main(){

  int s[N],t[Q],c=0;
  int i,a,b,key,x;

  scanf("%d",&a);
 for( i=0 ; i<a ; i++){
   scanf("%d",&s[i]);
 }

  scanf("%d",&b);
    for( i=0 ; i<b ; i++){
      scanf("%d",&t[i]);
    }


    for( i=0 ; i<b ; i++ ){
      key = t[i];
      s[a] = key;
      x = 0;
      while(s[x] != key){
	x++;
      }
      if(x != a){
	c++;
      }
    }
    
    printf("%d\n",c);
    return 0;
}
