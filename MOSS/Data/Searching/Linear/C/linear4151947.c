#include<stdio.h>
#define N 10000
#define Q 500


int main(){
  int i,len=0,key=0,s[N],t[Q],count=0;

  scanf("%d",&len);
  for( i = 0 ; i < len ; i++ ){
    scanf("%d",&s[i]);
  }

  scanf("%d",&key);
  for( i = 0 ; i < key ; i++ ){
    scanf("%d",&t[i]);
    for(int j = 0 ; j < len ; j++ ){
      if( t[i] == s[j]){
        count++;
        break;
      }
    }
  }
  printf("%d\n",count);

  return 0;
}

