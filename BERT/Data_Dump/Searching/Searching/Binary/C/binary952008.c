#include<stdio.h>
#define Un 100000
#define Uq 50000
int main(){
  int s[Un],t[Uq],Sn,Tn,i,j,L,R,C,count=0;
  scanf("%d\n",&Sn);
  for(i=0;i<Sn;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&Tn);
  for(i=0;i<Tn;i++){
    scanf("%d",&t[i]);
  }
  for(j=0; j<Tn; j++){
    L=0;
    R=Sn;
    while(L<R){
      C=(L+R)/2;
      if(t[j]==s[C]){
	count++;
	break;
      }
      if(t[j]>s[C]){
	L=C+1;
      }
      else if(t[j]<s[C]){
	R=C;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}
