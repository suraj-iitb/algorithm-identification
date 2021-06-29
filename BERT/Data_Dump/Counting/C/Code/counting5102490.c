#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 2000001


int num;
int C[VMAX+1];

void CSort(unsigned short* Ebi,unsigned short* Bob,int kmo){
    int i,j;

    for(i=0;i<=kmo;i++){
         C[i]=0;
     }
    for(j=1;j<=num;j++){
        C[Ebi[j]]++;
     }

    for(i=1;i<=kmo;i++){
        C[i]=C[i]+C[i-1];
    }
    for(j=num;j>=1;j--){
        Bob[C[Ebi[j]]]=Ebi[j];
        C[Ebi[j]]--;
    }
    
}

int main(){
  short *maegari,*Bugee;
  int m=0;
  int i;

  scanf("%d", &num);

  maegari=malloc(sizeof(short)*num+1);
  Bugee=malloc(sizeof(short)*num+1);

  for(i=1;i<=num;i++){
      scanf("%d",&maegari[i]);
      if(maegari[i]>m)  m=maegari[i];
  }

  CSort(maegari,Bugee,m);
  for(i=1;i<num;i++){
      printf("%d ",Bugee[i]);
  }
  printf("%d\n",Bugee[i]);


  return 0;
}
