#include<stdio.h>
#include<stdlib.h>

#define N 10000
#define Q 500

//???????????¢??°
int main(void){

  //??????????????°?????£?¨?
  int i,j,n,q,count=0,key,flag=0;;
  int s[N],t[Q];

 
  scanf("%d",&n);
  if(n>N) exit(1);
  for(i=0;i<n;i++) scanf("%d",&s[i]);
  
  scanf("%d",&q);
  if(q>Q) exit(2);
  for(i=0;i<q;i++) scanf("%d",&t[i]);

  //?????¢??¢?´¢????§?
  for(i=0;i<q;i++){
    flag=0;
    key=t[i];
      j=0;
    s[n]=key;

    while(1){
      if(s[j]==key){
	flag++;
	break;
      }
      j++;
      if(j==n) break;

    }
    if(flag==1) count ++;
  }


  
  printf("%d\n",count);

  return 0;
}
