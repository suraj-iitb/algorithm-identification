#include <stdio.h>
#include <math.h>
#include <time.h>


#define VMAX 500000
#define SS 2000000000

int Lum[VMAX/2+2],Rum[VMAX/2+2];
int c;
void mergeum(int Aum[],int num, int leftum, int midum, int rightum){
  int ium,jum,kum;
  int num1 = midum - leftum;
  int num2 = rightum - midum;
  for(ium=0;ium<num1;ium++) Lum[ium]=Aum[leftum+ium];
  for(ium=0;ium<num2;ium++) Rum[ium]=Aum[midum+ium];
  Lum[num1]=Rum[num2]=SS;
  ium=0,jum=0;
  for(kum=leftum;kum<rightum;kum++){
    c++;
    if(Lum[ium]<=Rum[jum]){
      Aum[kum]=Lum[ium++];
    }else{
      Aum[kum]=Rum[jum++];
    }
  }
}
void mergesortum(int Aum[],int num,int leftum,int rightum){
  int midum;
  if(leftum+1<rightum){
    midum = (leftum+rightum)/2;
    mergesortum(Aum,num,leftum,midum);
    mergesortum(Aum,num,midum,rightum);
    mergeum(Aum,num,leftum,midum,rightum);
  }
}



int main(void) {
  int Aum[VMAX],num,ium;
  c=0;

  scanf("%d",&num);
  for(ium=0;ium<num;ium++) scanf("%d",&Aum[ium]);

  mergesortum(Aum,num,0,num);
  for(ium=0;ium<num;ium++){
    if(ium) printf(" ");
    printf("%d",Aum[ium]);
  }
  printf("\n%d\n",c);

  return 0;
}

