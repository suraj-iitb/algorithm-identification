#include<stdio.h>
#define Us 10000
#define Uq 500
int main(){
  int i,j,S[Us],T[Uq],Sn,Tn,count=0;
  scanf("%d",&Sn);
  for(i=0; i<Sn; i++){//入力したSnだけループ
    scanf("%d",&S[i]);
  }
  scanf("%d",&Tn);
  for(i=0; i<Tn; i++){
    scanf("%d",&T[i]);
    for(j=0; j<Sn; j++){
      if(S[j]==T[i]){
    count++;
    break;
      }//異なる整数なので見付けたらjのループをぬけてもOK
    }
  }
  printf("%d\n",count);
  return 0;
}
