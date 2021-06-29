#include<stdio.h>
int main(){
  int Ntw,Btw,Ctw=0,i,j;
  scanf("%d",&Ntw);
  int Atw[Ntw];
  for(i=0;i<Ntw;i++){
    scanf("%d",&Atw[i]);
  }
  i=0;
  while(i<Ntw){
    for(j=Ntw-1;j>i;j--){
      if(Atw[j]<Atw[j-1]){
	Btw=Atw[j];
	Atw[j]=Atw[j-1];
	Atw[j-1]=Btw;
	Ctw++;
      }
    }
    i++;
  }
  for(i=0;i<Ntw;i++){
    if(i>0)printf(" ");
    printf("%d",Atw[i]);
  }
  printf("\n%d\n",Ctw);
  return 0;
}

