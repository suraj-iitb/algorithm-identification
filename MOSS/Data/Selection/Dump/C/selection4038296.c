#include<stdio.h>
int main(){
  int Ntw,Btw,Ctw=0,i,j,minj;
  scanf("%d",&Ntw);
  int Atw[Ntw];
  for(i=0;i<Ntw;i++){
    scanf("%d",&Atw[i]);
  }
  for(i=0;i<Ntw;i++){
    minj=i;
    for(j=i;j<Ntw;j++){
      if(Atw[j]<Atw[minj])minj=j;
    }
    if(Atw[i]!=Atw[minj]){
      Btw=Atw[i];
      Atw[i]=Atw[minj];
      Atw[minj]=Btw;
      Ctw++;
    }
  }
    
  for(i=0;i<Ntw;i++){
    if(i>0)printf(" ");
    printf("%d",Atw[i]);
  }
  printf("\n%d\n",Ctw);
  return 0;
}

