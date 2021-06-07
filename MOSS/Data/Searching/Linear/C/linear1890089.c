#include <stdio.h>
#define x 10000
 
int main(){
  int i,j,n,t,c,Sawa[x],Hira[x];
  c = 0;
 
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&Sawa[i]);
  }
  scanf("%d",&t);
  for(i=0;i<t;i++){
    scanf("%d",&Hira[i]);
  }
   
  for(i=0;i<t;i++){
    for(j=0;j<n;j++){
      if(Hira[i]==Sawa[j]) {
    c++; break;
}
    }
  }
  printf("%d\n",c);
  return 0;
   
}
