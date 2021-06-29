#include<stdio.h>
#include<stdlib.h>

typedef struct{
  char mark;
  int num;
  int order;
}card;

int partition(card *,int,int);
void sort(card *,int,int);

int main(){

  card *C;
  int i,j,n,judge=0;
  char a,b;

  scanf("%d%c",&n,&a);

  C=(card*)malloc(sizeof(card)*n*2+1);

  for(i=0;i<n;i++){
    scanf("%c%c%d%c",&C[i].mark,&a,&C[i].num,&b);

    C[i].order=i;
  }
  sort(C,0,i-1);

  for(i=0;i<n;i++){
    if(C[i].num==C[i+1].num){
      if(C[i].order>C[i+1].order){
	judge=1;
	break;
      }
    }
  }
  if(judge==0){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }

  for(i=0;i<n;i++){
    printf("%c %d\n",C[i].mark,C[i].num);
  }

  free(C);
  return 0;
}

void sort(card *C,int p,int r){

  int q;

  if(p<r){
    q=partition(C,p,r);
    sort(C,p,q-1);
    sort(C,q+1,r);
  }
}

int partition(card *C,int p,int r){

  card change;

  int i=p-1,j;
  int x=C[r].num;

  for(j=p;j<r;j++){
    if(C[j].num<=x){
      i=i+1;
      change=C[j];
      C[j]=C[i];
      C[i]=change;
    }
  }
  change=C[r];
  C[r]=C[i+1];
  C[i+1]=change;

  return i+1;
}
