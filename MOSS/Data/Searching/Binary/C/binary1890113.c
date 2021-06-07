#include<stdio.h>
#define N 100000
#define Q 50000

int main(){
  int i,n,q,Sawa[N],Hira[Q],f=0,a,b,c;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&Sawa[i]);
  }
  
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&Hira[i]);
  }
  for(i=0;i<q;i++){
    a=0;
    b=n;
    while(a<b){
      c=(a+b)/2;
      if(Hira[i]==Sawa[c]){
    f++;
    break;
      }
      if(Hira[i]>Sawa[c])
    a=c+1;
      else if(Hira[i]<Sawa[c])
    b=c;
    }
  }
  printf("%d\n",f);
    
    
  return 0;
}
