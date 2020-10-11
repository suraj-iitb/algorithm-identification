#include<stdio.h>

#define N 100000
#define Gard 10000001

typedef struct{
  int Num;
  char Spel;
}Tarot;

Tarot Qui[N];
Tarot Mer[N];

void QuickS(int ,int );
int Par(int ,int );
void Merge(Tarot *,int ,int ,int );
void MergeS(Tarot *,int ,int );

int main(){
  Tarot Mer[N];
  int i;
  int flag=0;
  int loop;
    
  scanf("%d ",&loop);
  for(i=0;i<loop;i++){
    scanf("%s %d",&Qui[i].Spel,&Qui[i].Num);
    Mer[i].Spel=Qui[i].Spel;
    Mer[i].Num=Qui[i].Num;
  }

  QuickS(0,loop-1);
  MergeS(Mer,0,loop);
  
  
  for(i=0;i<loop;i++){
    if(Qui[i].Spel!=Mer[i].Spel){
      flag=1;
      break;
    }
  }

  if(flag==0){
    printf("Stable\n");
  }

  else if(flag==1){
    printf("Not stable\n");
  }
  
  for(i=0;i<loop;i++){
    printf("%c ",Qui[i].Spel);
    printf("%d\n",Qui[i].Num);
  }

  return 0;
}

void QuickS(int zero,int set){
  int point;

  if(zero<set){
    point=Par(zero,set);
    
    QuickS(zero,point-1);
    
    QuickS(point+1,set);
    }
}

int Par(int zero,int set){
  int init;
  int j;
  Tarot last,temp;
  
  last=Qui[set];
  init=zero-1;
  
  for(j=zero;j<set;j++){
    
    if(last.Num>=Qui[j].Num){
      init+=1;
      temp=Qui[init];
      Qui[init]=Qui[j];
      Qui[j]=temp;
    }
  }
  
  temp=Qui[init+1];
  Qui[init+1]=Qui[set];
  Qui[set]=temp;
  
  return init+1;
}

void  Merge(Tarot *Mer,int lside,int center,int rside){
  int i;
  int Lrenge,Rrenge;
  Tarot Left[N/2+6],Right[N/2+6];
  int jud1,jud2;

  Lrenge=center-lside;
  Rrenge=rside-center;

  for(i=0;i<Lrenge;i++){
    Left[i]=Mer[lside+i];
  }

  for(i=0;i<Rrenge;i++){
    Right[i]=Mer[center+i];
  }

  Left[Lrenge].Num=Gard;
  Right[Rrenge].Num=Gard;
  
  jud1=0;
  jud2=0;

  for(i=lside;i<rside;i++){

    if(Left[jud1].Num<=Right[jud2].Num){
      Mer[i]=Left[jud1];
      jud1++;
    }

    else{
      Mer[i]=Right[jud2];
      jud2++;
    }
  }
}

void MergeS(Tarot *Mer,int lside,int rside){
  int center;

  if(rside>lside+1){

    center=(lside+rside)/2;

    MergeS(Mer,lside,center);

    MergeS(Mer,center,rside);

    Merge(Mer,lside,center,rside);
  }
}

